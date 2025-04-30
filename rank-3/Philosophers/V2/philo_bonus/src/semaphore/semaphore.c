/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semaphore.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 11:20:33 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/30 13:42:07 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Headers

/* -----| Internal |----- */
// #include "_semaphore.h"

/* -----| Modules  |----- */
#include "semaphore.h"

#pragma endregion Headers
#pragma region Functions

/** */
__attribute__((always_inline, used)) inline int destroy_semaphore(
	sem_t *semaphore
)
{
	if (__buitlin_expect(!semaphore, unexpected))
		return (0);
	else
	{
		sem_close(semaphore);
		sem_unlink(SEMA_FORKS_DEFAULT);
	}
}

/** */
__attribute__((always_inline, used)) inline sem_t	*init_semaphore(
	const t_philo_data data
)
{
	sem_t	*sem;

	sem_unlink(SEMA_FORKS_DEFAULT);
	sem = sem_open(SEMA_FORKS_DEFAULT, O_CREAT | O_EXCL, data.nb_philo);
	if (__builtin_expect(sem == SEM_FAILED, unexpected))
		return (NULL);
	if (__builtin_expect(sem_init(sem, 1, data.nb_philo) == -1, unexpected))
		return (NULL);
	return (sem);
}

#pragma endregion Functions