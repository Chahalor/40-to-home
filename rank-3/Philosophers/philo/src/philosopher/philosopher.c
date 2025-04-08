/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 07:59:38 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/08 16:49:41 by nduvoid          ###   ########.fr       */
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
__attribute__((cold, malloc)) t_philo	**build_philos(
	const t_philo_data data)
{
	t_mutex	**forks;
	t_philo	**philos;

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
	t_philo				*philo;
	static const int	sleep_time = get_data(time_to_sleep);	// @todo

	philo = (t_philo *)ptr;
	if (__builtin_expect(!philo, unexpected))
		return (NULL);
	while (1)
	{
		if (__builtin_expect(philo->state == sleeping, unexpected))
			usleep(sleep_time);	// we maybe need to reduce the sleep time cause the function is not accurate
		else if (pthread_mutex_trylock(philo->left_fork) == 0 && 
			pthread_mutex_trylock(philo->right_fork) == 0)
			eat(philo);
		else
			usleep(100);	// @todo
	}
	return (NULL);
}

/** */
__attribute__((cold)) inline void	hive_mind(
	t_global *global
)
{
	register int	i;

	if (__builtin_expect(!global->philos, unexpected))
		return ;
	i = -1;
	while (++i < global->data.nb_philo)
	{
		if (__builtin_expect(pthread_create(&global->philos[i]->thread, NULL,
				&single_mind, global->philos[i]), unexpected))
			return (terminator(global->philos, global->data.nb_philo));
	}
	i = -1;
	while (++i < global->data.nb_philo)
		pthread_join(global->philos[i]->thread, NULL);
	terminator(global->philos, global->data.nb_philo);
}

#pragma endregion "Functions"