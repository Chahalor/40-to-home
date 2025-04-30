/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 12:29:30 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/29 14:00:35 by nduvoid          ###   ########.fr       */
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

	if (!forks || !*forks)
		return ;
	i = -1;
	while (++i < nb_forks)
		pthread_mutex_destroy(&(*forks)[i]);
	free(*forks);
	*forks = NULL;
}

/** */
__attribute__((cold)) void	destroy_philos(
	t_philo *restrict *restrict philosophers
)
{
	if (!philosophers || !*philosophers)
		return ;
	free(*philosophers);
	*philosophers = NULL;
}

/** */
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