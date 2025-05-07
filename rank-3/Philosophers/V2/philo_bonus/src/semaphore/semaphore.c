/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semaphore.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 11:20:33 by nduvoid           #+#    #+#             */
/*   Updated: 2025/05/07 12:29:14 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Headers

/* -----| Internal |----- */
// #include "_semaphore.h"

/* -----| Modules  |----- */
#include "semaphores.h"

#pragma endregion Headers
#pragma region Functions

/**
 * @brief	Close and unlink all the globals semaphores.
 * 
 * @param	semaphore The semaphores to close.
 * 
 * @return 1 if success, -1 if failed.
*/
__attribute__((always_inline, used)) inline int	close_semaphores(
	t_semaphores	*semaphore
)
{
	if (__builtin_expect(!semaphore, unexpected))
		return (-1);
	else
	{
		sem_close(semaphore->forks);
		sem_unlink(DEFAULT_SEMA_DIR DEFAULT_SEMA_FORKS);
		sem_close(semaphore->print);
		sem_unlink(DEFAULT_SEMA_DIR DEFAULT_SEMA_PRINT);
		sem_close(semaphore->run);
		sem_unlink(DEFAULT_SEMA_DIR DEFAULT_SEMA_RUN);
		sem_close(semaphore->nb_finished);
		sem_unlink(DEFAULT_SEMA_DIR DEFAULT_SEMA_FINISHED);
		return (1);
	}
}

/**
 * @brief	Unlink and Initialize the semaphores for the simulation.
 * 
 * @param	nb_philo The number of philosophers.
 * 
 * @return	The initialized semaphores.
 * 
 * @note	Unlink the semaphores if they already exist.
 * @note	Don t forget to unlink the semaphores if you add a new one.
 */
__attribute__((always_inline, used)) inline t_semaphores	init_semaphore(
	const int nb_philo
)
{
	t_semaphores	semaphores;

	sem_unlink(DEFAULT_SEMA_DIR DEFAULT_SEMA_FORKS);
	sem_unlink(DEFAULT_SEMA_DIR DEFAULT_SEMA_PRINT);
	sem_unlink(DEFAULT_SEMA_DIR DEFAULT_SEMA_RUN);
	sem_unlink(DEFAULT_SEMA_DIR DEFAULT_SEMA_FINISHED);
	semaphores.forks = sem_open(DEFAULT_SEMA_DIR DEFAULT_SEMA_FORKS,
			O_CREAT | O_EXCL, S_IRUSR | S_IWUSR, nb_philo);
	semaphores.print = sem_open(DEFAULT_SEMA_DIR DEFAULT_SEMA_PRINT,
			O_CREAT | O_EXCL, S_IRUSR | S_IWUSR, 1);
	semaphores.run = sem_open(DEFAULT_SEMA_DIR DEFAULT_SEMA_RUN,
			O_CREAT | O_EXCL, S_IRUSR | S_IWUSR, 0);
	semaphores.nb_finished = sem_open(DEFAULT_SEMA_DIR DEFAULT_SEMA_FINISHED,
			O_CREAT | O_EXCL, S_IRUSR | S_IWUSR, 0);
	if (__builtin_expect(semaphores.forks == SEM_FAILED
			|| semaphores.print == SEM_FAILED || semaphores.run == SEM_FAILED
			|| semaphores.nb_finished == SEM_FAILED, unexpected))
	{
		close_semaphores(&semaphores);
		return ((t_semaphores){0});
	}
	return (semaphores);
}

#pragma endregion Functions