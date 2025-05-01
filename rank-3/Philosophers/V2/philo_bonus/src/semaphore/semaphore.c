/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semaphore.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 11:20:33 by nduvoid           #+#    #+#             */
/*   Updated: 2025/05/01 11:44:14 by nduvoid          ###   ########.fr       */
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
__attribute__((always_inline, used)) inline int	destroy_semaphore(
	t_semaphores	*semaphore
)
{
	if (__buitlin_expect(!semaphore, unexpected))
		return (-1);
	else
	{
		sem_close(semaphore->forks);
		sem_unlink(DEFAULT_SEMA_DIR DEFAULT_SEMA_FORKS);
		sem_close(semaphore->print);
		sem_unlink(DEFAULT_SEMA_DIR DEFAULT_SEMA_PRINT);
		sem_close(semaphore->run);
		sem_unlink(DEFAULT_SEMA_DIR DEFAULT_SEMA_RUN);
		return (1);
	}
}

/** */
__attribute__((always_inline, used)) inline t_semaphores	*init_semaphore(
	const int nb_philo
)
{
	t_semaphores	semaphores;

	sem_unlink(DEFAULT_SEMA_DIR DEFAULT_SEMA_FORKS);
	sem_unlink(DEFAULT_SEMA_DIR DEFAULT_SEMA_PRINT);
	sem_unlink(DEFAULT_SEMA_DIR DEFAULT_SEMA_RUN);
	semaphores.forks = sem_open(DEFAULT_SEMA_DIR DEFAULT_SEMA_FORKS,
		O_CREAT | O_EXCL, S_IRUSR | S_IWUSR, nb_philo);
	semaphores.print = sem_open(DEFAULT_SEMA_DIR DEFAULT_SEMA_PRINT,
		O_CREAT | O_EXCL, S_IRUSR | S_IWUSR, 1);
	semaphores.run = sem_open(DEFAULT_SEMA_DIR DEFAULT_SEMA_RUN,
		O_CREAT | O_EXCL, S_IRUSR | S_IWUSR, 1);
	if (__builtin_expect(semaphores.forks == SEM_FAILED
			|| semaphores.print == SEM_FAILED || semaphores.run == SEM_FAILED,
			unexpected))
	{
		destroy_semaphore(&semaphores);
		return (NULL);
	}
	return (&semaphores);
}

#pragma endregion Functions