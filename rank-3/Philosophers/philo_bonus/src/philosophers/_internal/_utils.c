/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _utils.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 12:48:48 by nduvoid           #+#    #+#             */
/*   Updated: 2025/05/09 14:31:29 by nduvoid          ###   ########.fr       */
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

/**
 * @brief	Exit the process and close all semaphores.
 * 
 * @param	philos Pointer to the philosophers.
 * 
 * @param	print_lock Pointer to the print semaphore.
 * 
 * @return	void
*/
__attribute__((always_inline, used)) inline void	_exit_process(
	t_philo *restrict philos,
	sem_t *restrict print_lock
)
{
	sem_close(print_lock);
	sem_unlink(DEFAULT_SEMA_DIR DEFAULT_SEMA_PRINT);
	sem_close(philos->lock);
	sem_close(philos->finished);
	sem_close(philos->forks);
	sem_close(philos->run);
}

/**
 * @brief	Lock the forks for the philosopher. And print the message.
 * 
 * @param	philo Pointer to the philosopher.
 * 
 * @return	void
 */
__attribute__((always_inline, used)) inline void	_lock_forks(
	t_philo *philo
)
{
	swait(philo->forks);
	philo->info(philo, forks);
	swait(philo->forks);
	philo->info(philo, forks);
}

/**
 * @brief	Do the simulaion in case of one philosopher.
 * 
 * @param	philo Pointer to the philosopher.
 * 
 * @return	int 1 anyway
 */
__attribute__((always_inline, used)) inline int	_one(
	t_philo *philo
)
{
	philo->info(philo, forks);
	ft_usleep(philo->data.time_to_die * 1000);
	printf("The philosopher %d is too civilized to eat with one fork. "
		"He prefers to dying of starvation.\n", philo->id);
	philo->die(philo);
	return (1);
}

#pragma endregion Functions