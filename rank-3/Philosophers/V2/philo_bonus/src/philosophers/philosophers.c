/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 12:29:30 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/30 11:35:59 by nduvoid          ###   ########.fr       */
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
__attribute__((cold)) void	destroy_philos(
	t_philo *restrict *restrict philosophers
)
{
	if (__builtin_expect(!philosophers || !*philosophers, unexpected))
		return ;
	free(*philosophers);
	*philosophers = NULL;
}

/** */
__attribute__((cold)) int	init_all(
	sem_t *restrict *restrict semaphore,
	t_philo *restrict *restrict philosophers,
	const t_args args
)
{
	*semaphore = init_semaphore(args.data);
	if (__builtin_expect(!*semaphore, unexpected))
		return (-1);
	*philosophers = _init_philo(args.data.nb_philo, forks, args.data,
		args.display);
	if (__builtin_expect(!*philosophers, unexpected))
		return (destroy_mutex(forks, args.data.nb_philo), -1);
	return (0);
}

#pragma endregion Functions