/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _init.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 13:52:12 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/29 13:58:31 by nduvoid          ###   ########.fr       */
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
 * @brief	Allocate and initialize the mutexes for the Program.
 * 
 * @param	nb_mutex Number of mutexes to allocate.
 * 
 * @return	t_mutex	Pointer to the allocated mutexes.
 */
__attribute__((malloc, cold)) t_mutex	*_init_mutex(
	register int nb_mutex
)
{
	t_mutex			*forks;
	register int	i;

	forks = (t_mutex *)malloc(sizeof(t_mutex) * nb_mutex);
	if (__builtin_expect(!forks, unexpected))
		return (NULL);
	i = -1;
	while (++i < nb_mutex)
	{
		if (__builtin_expect(pthread_mutex_init(&forks[i], NULL) != 0,
				unexpected))
			return (destroy_mutex(&forks, i), NULL);
	}
	return (forks);
}

/**
 * @brief	Choose the display function for the philosopher.
 * 
 * 
 * @param	philo	Pointer to the philosopher.
 * @param	display	Display mode (1 for display, 0 for raw log).
 * 
 * @return	void
 */
__attribute__((always_inline, used)) static inline void	_choose_info(
	t_philo *philo,
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
 * @param	mutex_pool	Pointer to the mutex pool.
 * @param	data		Philosopher data.
 * @param	display		Display mode (1 for display, 0 for raw log).
 */
__attribute__((malloc, cold)) t_philo	*_init_philo(
	register const int nb_philos,
	t_mutex *restrict *restrict mutex_pool,
	const t_philo_data data,
	const int display
)
{
	const t_time	time_start = get_ms_time();
	t_philo			*philosophers;
	register int	i;
	t_mutex			*pool;

	if (__builtin_expect(!mutex_pool || !*mutex_pool || nb_philos < 1,
			unexpected))
		return (NULL);
	philosophers = (t_philo *)malloc(sizeof(t_philo) * nb_philos);
	if (__builtin_expect(!philosophers, unexpected))
		return (NULL);
	pool = *mutex_pool;
	i = -1;
	while (++i < nb_philos)
	{
		philosophers[i] = (t_philo){
			.id = i, .last_meal = time_start, .status = eating,
			.lock = &pool[nb_philos + i], .left_fork = &pool[i],
			.right_fork = &pool[(i + 1) % nb_philos], .data = data,
			.eat = _eat, .sleep = _sleep, .think = _think, .die = _die,
			.finish = _die
		};
		_choose_info(&philosophers[i], display);
	}
	return (philosophers);
}

#pragma endregion Functions