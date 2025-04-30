/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 12:29:30 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/30 14:10:28 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Headers

/* -----| Internal |----- */
#include "_philosopher.h"

/* -----| Modules  |----- */
#include "philosophers.h"

#pragma endregion Headers
#pragma region Functions

/** */
__attribute__((cold)) void	destroy_mutex(
	t_mutex *restrict *restrict forks,
	const int nb_forks
)
{
	register int	i;

	if (__builtin_expect(!forks || !*forks, unexpected))
		return ;
	i = -1;
	while (__builtin_expect(++i < nb_forks, expected))
		pthread_mutex_destroy(&(*forks)[i]);
	free(*forks);
	*forks = NULL;
}

/** */
__attribute__((cold)) void	destroy_philos(
	t_philo *restrict *restrict philosophers
)
{
	if (__builtin_expect(!philosophers || !*philosophers, unexpected))
		return ;
	free(*philosophers);
	*philosophers = NULL;
}

/**
 * @brief	Initialize all philosophers and forks.
 * 
 * @param	forks			Pointer to the forks mutexes.
 * @param	philosophers	Pointer to the philosophers.
 * @param	data			Philosopher data.
 * @param	display			Display mode (1 for display, 0 for raw log).
 * 
 * @return	0 on success, -1 on failure.
 */
__attribute__((cold)) int	init_all(
	t_mutex **forks,
	t_philo *restrict *restrict philosophers,
	t_philo_data data,
	const int display
)
{
	*forks = _init_mutex(3 * data.nb_philo);
	if (__builtin_expect(!*forks, unexpected))
		return (-1);
	*philosophers = _init_philo(data.nb_philo, forks, data, display);
	if (__builtin_expect(!*philosophers, unexpected))
		return (destroy_mutex(forks, data.nb_philo), -1);
	return (0);
}

#pragma endregion Functions