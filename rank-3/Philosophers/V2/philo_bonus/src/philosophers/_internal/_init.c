/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _init.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 13:52:12 by nduvoid           #+#    #+#             */
/*   Updated: 2025/05/05 12:42:27 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Headers

/* -----| Internal |----- */
#include "_philosopher.h"

/* -----| Modules  |----- */
#include "philosophers.h"

#include "utils.h"
#include "debug.h"

#pragma endregion Headers
#pragma region Functions

/**
 * @brief	Choose the display function for the philosopher.
 * 
 * @param	philo	Pointer to the philosopher.
 * @param	display	Display mode (1 for display, 0 for raw log).
 * 
 * @return	void
 */
__attribute__((always_inline, used)) static inline void	_choose_info(
	t_philo *restrict philo,
	const int display
)
{
	if (display == 1)
		philo->info = display_philo;
	else
		philo->info = raw_log;
}

/**
 * @brief	Allocate and initialize all philosophers.
 * 
 * @param	nb_philos	Number of philosophers.
 * @param	sema		Pointer to the forks semaphore.
 * @param	data		Philosopher data.
 * @param	display		Display mode (1 for display, 0 for raw log).
 * 
 * @return	Pointer to the philosophers array.
 */
__attribute__((malloc, cold)) t_philo	*_init_philo(
	register const int nb_philos,
	sem_t *sema,
	const t_philo_data data,
	const int display
)
{
	const t_time	time_start = get_ms_time();
	t_philo			*philosophers;
	register int	i;	

	if (__builtin_expect(!sema || nb_philos < 1, unexpected))
		return (NULL);
	philosophers = (t_philo *)malloc(sizeof(t_philo) * nb_philos);
	if (__builtin_expect(!philosophers, unexpected))
		return (NULL);
	i = -1;
	while (++i < nb_philos)
	{
		philosophers[i] = (t_philo){
			.id = i, .last_meal = time_start, .status = eating, .data = data,
			.eat = _eat, .sleep = _sleep, .think = _think, .die = _die,
			.forks = sema, .lock = NULL
		};
		_choose_info(&philosophers[i], display);
	}
	return (philosophers);
}

#pragma endregion Functions