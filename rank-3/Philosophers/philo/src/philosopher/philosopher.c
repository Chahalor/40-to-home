/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 07:59:38 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/10 19:46:14 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region "Headers"
// System
#include <unistd.h>

// Global
#include "type.h"
#include "config.h"

// Modules
#include "_philosopher.h"
#include "philosopher.h"
#include "utils.h"
#include "debug.h"

#pragma endregion "Headers"
#pragma region "Functions"

/** */
__attribute__((hot)) void	*check_death(
	void *param
)
{
	unsigned int	time;
	t_global		*global;
	register int	i;
	register int	nb_finish;

	global = (t_global *)param;
	while (true)
	{
		nb_finish = 0;
		i = -1;
		while (++i < global->data.nb_philo)
		{
			time = get_ms_time();
			if (__builtin_expect(pthread_mutex_lock(global->philos[i]->lock), unexpected))
				return (NULL);
			// printf("philo[%d].last_meal=%d, time_to_die=%d, time=%d, diff=%d\n",
			// 	global->philos[i]->id, global->philos[i]->last_meal,
			// 	global->data.time_to_die, time, time - global->philos[i]->last_meal);	// rm
			if (__builtin_expect(global->philos[i]->state == dead, unexpected))
				return (NULL);
			else if (__builtin_expect(time - global->philos[i]->last_meal
					>= global->data.time_to_die, unexpected))
			{
				global->philos[i]->state = dead;
				info(dead, global->philos[i], time);
				global->data.running = false;
				return (NULL);
			}
			else if (__builtin_expect(global->philos[i]->state == finish, unexpected))
				++nb_finish;
			if (__builtin_expect(pthread_mutex_unlock(global->philos[i]->lock),
				unexpected))
				return (NULL);
			}
		if (__builtin_expect(nb_finish == global->data.nb_philo, unexpected))
			return (NULL);
	}
}

/** */
__attribute__((cold, malloc)) t_philo	**build_philos(
	const t_philo_data data)
{
	t_mutex	**forks;
	t_philo	**philos;

	if (data.nb_philo < 1 || data.time_to_die < 1
		|| data.time_to_eat < 1 || data.time_to_sleep < 1)
		return (NULL);
	forks = (t_mutex **)ft_calloc(1, sizeof(t_mutex *) * data.nb_philo
		+ sizeof(t_mutex) * data.nb_philo);
	philos = (t_philo **)ft_calloc(1, sizeof(t_philo *) * data.nb_philo
		+ sizeof(t_philo) * data.nb_philo + sizeof(t_mutex) * data.nb_philo);
	if (__builtin_expect(!forks || !philos, unexpected))
		return (free(philos), free(forks), NULL);
	else if (__builtin_expect(init_forks(forks, data.nb_philo), unexpected))
		return (free(philos), free(forks), NULL);
	else
		if (__builtin_expect(init_philos(philos, forks, data), unexpected))
			return (NULL);
	emergency_storage(forks);
	return (philos);
}

/** */
__attribute__((cold)) inline void	terminator(t_philo **philo, const int nb_philo)
{
	register int	i;

	if (__builtin_expect(!philo, unexpected))
		return ;
	i = -1;
	while (++i < nb_philo)
	{
		if (__builtin_expect(!philo[i], unexpected))
			continue ;
		else
		{
			pthread_mutex_destroy(philo[i]->left_fork);
			pthread_mutex_destroy(philo[i]->lock);
		}
	}
	free(emergency_storage(NULL));
	free(philo);
}

/** */
__attribute__((cold)) void	*single_mind(void *ptr)
{
	t_philo		*philo;
	static int	sleep_time = -1;
	t_bool		running = true;

	philo = (t_philo *)ptr;
	if (__builtin_expect(!philo, unexpected))
		return (NULL);
	else if (__builtin_expect(sleep_time == -1, expected))
		sleep_time = get_data(time_to_sleep);
	while (running)
	{
		// printf("single_mind(), philo->state=%d at the begining\n", philo->state);	// rm
		if (philo->state == sleeping)	// removing certaine __builtin_expect could be an good idea
			mein_sleep(philo, sleep_time);
		else if (philo->state == thinking)
			think(philo);
		else if (philo->state == eating)
			eat(philo);
		else if (philo->state == dead)
			break ;
		running = (get_data(state) + (philo->state != finish)) == 2;
		// printf("philo[%d] state: %d at the end\n", philo->id, philo->state);	// rm
	}
	return (NULL);
}

/** */
__attribute__((cold)) inline void	hive_mind(
	t_global *global,
	t_thread *main_thread
)
{
	register int	i;

	if (__builtin_expect(!global || !global->philos, unexpected))
		return ;
	// print_debug("starting Hive mind");	//rm
	global->data.start_time = get_ms_time();
	pthread_mutex_lock(&global->data_lock);
	store_global(global);
	pthread_mutex_unlock(&global->data_lock);
	get_data(setup);
	i = -1;
	while (++i < global->data.nb_philo)
	{
		// print_debug("creating thread");	//rm
		if (__builtin_expect(pthread_create(&global->philos[i]->thread, NULL,
				&single_mind, global->philos[i]), unexpected))
			return (terminator(global->philos, global->data.nb_philo));
	}
	if (__builtin_expect(pthread_create(main_thread, NULL, &check_death,
		global), unexpected))
	i = -1;
	while (++i < global->data.nb_philo)
		pthread_join(global->philos[i]->thread, NULL);
	// terminator(global->philos, global->data.nb_philo);
}

#pragma endregion "Functions"