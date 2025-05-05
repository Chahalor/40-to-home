/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _utils.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 12:48:48 by nduvoid           #+#    #+#             */
/*   Updated: 2025/05/05 16:15:49 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Headers

/* -----| Internal |----- */
#include "_philosopher.h"

/* -----| Modules  |----- */
#include "philosophers.h"

#include "utils.h"

#pragma endregion Headers
#pragma region Functions

/** */
__attribute__((always_inline, used)) inline void	_lock_forks(
	t_philo *philo
)
{
	wait(philo->forks);
	philo->info(philo, forks);
	wait(philo->forks);
	philo->info(philo, forks);
}

/** */
__attribute__((always_inline, used)) inline int	wait(
	sem_t *sem
)
{
	if (__builtin_expect(!sem, unexpected))
		return (-1);
	else
		return (sem_wait(sem));
}

/** */
__attribute__((always_inline, used)) inline int	post(
	sem_t *sem
)
{
	if (__builtin_expect(!sem, unexpected))
		return (-1);
	else
		return (sem_post(sem));
}

#pragma endregion Functions