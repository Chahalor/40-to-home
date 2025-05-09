/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 07:59:38 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/23 10:18:23 by nduvoid          ###   ########.fr       */
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
__attribute__((cold)) inline void	terminator(
	t_philo **philo, 
	const int nb_philo
)
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
__attribute__((hot)) void	*check_death(
	void *param
)
{
	unsigned int	time;
	t_global		*global;
	register int	i;
	register int	nb_finish;

	global = (t_global *)param;
	nb_finish = 0;
	printf("check_death(): starting\n");	//rm
	while (global->data.running)
	{
		nb_finish = 0;
		i = -1;
		while (++i < global->data.nb_philo)
		{
			time = get_ms_time();
			// if (__builtin_expect(pthread_mutex_lock(global->philos[i]->lock),
			// 	unexpected))
			// 	return (NULL);
			/*else*/ if (__builtin_expect(time - global->philos[i]->last_meal
					> global->data.time_to_die, unexpected))
			{
				_death(global->philos[i], global);
				break ;
			}
			else if (__builtin_expect(global->philos[i]->state == finish,
				unexpected))
				++nb_finish;
			// if (__builtin_expect(pthread_mutex_unlock(global->philos[i]->lock),
			// 	unexpected))
			// 	return (NULL);
			// printf("  check_death(): philo %d: last_meal=%u | %u\n", global->philos[i]->id, global->philos[i]->last_meal, time);	//rm
		}
		if (__builtin_expect(nb_finish == global->data.nb_philo, unexpected))
			global->data.running = false;
		// printf("check_death(): nb_finish=%d && nb_philo=%d\n", nb_finish, global->data.nb_philo);	//rm
	}
	printf("check_death(): returning\n");	//rm
	return (NULL);
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
		+ sizeof(t_philo) * data.nb_philo
		+ sizeof(t_mutex *) * data.nb_philo
		+ sizeof(t_mutex) * data.nb_philo);
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
__attribute__((cold)) void	*single_mind(void *ptr)
{
	const t_mind		*mind = (t_mind *)ptr;
	const register int	sleep_time = mind->sleep_time;
	t_philo				*philo;
	t_bool				running;

	philo = mind->philo;
	running = true;
	if (__builtin_expect(!philo || sleep_time < 0, unexpected))
		return (NULL);
	printf("single_mind(%d): mind: %p\n", philo->id, mind);	//rm
	printf("single_mind(%lu): philo %d start is life\n", philo->thread, philo->id);	//rm
	while (running)
	{
		if (philo->state == sleeping)
			_sleep(philo, sleep_time);
		else if (philo->state == thinking)
			_think(philo);
		else if (philo->state == eating)
			_eat(philo);
		else if (philo->state == dead)
			break ;
		int statee = get_data(state);
		// printf("philo[%d]: get_data(state)=%d\n", philo->id, statee);	//rm
		running = (statee + (philo->state != finish)) == 2;
	}
	free(ptr);
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
	global->data.start_time = get_ms_time();
	store_global(global);
	get_data(setup);
	launch_thread(global, main_thread);
	pthread_join(*main_thread, NULL);
	i = -1;
	while (++i < global->data.nb_philo)
	{
		printf("hive_mind(): waiting for philo %d\n", global->philos[i]->id);	//rm
		pthread_join(global->philos[i]->thread, NULL);
	}
}

#pragma endregion "Functions"