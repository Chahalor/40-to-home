/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _init.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 10:27:22 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/11 14:52:16 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region "Headers"

#include "_philosopher.h"
#include "philosopher.h"

#include "utils.h"
#include "debug.h"

#pragma endregion "Headers"
#pragma region "Functions"

/** */
__attribute__((always_inline)) inline int	init_philos(
	t_philo **philo,
	t_mutex **fork,
	const t_philo_data data)
{
	const int		color_step = (COLORS_END - COLORS_START) / data.nb_philo;
	const t_philo	*philo_data = (t_philo *)(philo + data.nb_philo);
	const t_mutex	*fork_data = (t_mutex *)(fork + data.nb_philo);
	const t_mutex	*lock_pool = (t_mutex *)(fork + data.nb_philo
		+ data.nb_philo * sizeof(t_philo));
	register int	i;

	i = -1;
	while (++i < data.nb_philo)
	{
		philo[i] = (t_philo *)(&philo_data[i]);
		*philo[i] = (t_philo){
			.id = i, .nb_meals = 0, .last_meal = get_ms_time(), .state = eating,
			.color = i * color_step, .thread = 0,
			.lock = (t_mutex *)(&lock_pool[i]),
			.left_fork = (t_mutex *)(&fork_data[i]),
			.right_fork = (t_mutex *)(&fork_data[(i + 1) % data.nb_philo])
		};
		if (__builtin_expect(pthread_mutex_init(philo[i]->lock, NULL),
			unexpected))
			return (terminator(philo, i), free(fork), -1);
	}
	return (0);
}

/** */
__attribute__((always_inline)) static inline void	destroy_forks(
	t_mutex **forks, register int i)
{
	while (i >= 0)
		pthread_mutex_destroy(forks[i--]);
}

/** */
__attribute__((always_inline)) inline int	init_forks(
	t_mutex **fork, const int nb_philo)
{
	register int	i;
	t_mutex			*fork_data;

	fork_data = (t_mutex *)(fork + nb_philo);
	i = -1;
	while (++i < nb_philo)
	{
		fork[i] = &fork_data[i];
		if (__builtin_expect(pthread_mutex_init(fork[i], NULL), unexpected))
			return (destroy_forks(fork, i), -1);
	}
	return (0);
}

#pragma endregion "Functions"