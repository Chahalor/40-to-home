/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _day.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 10:59:19 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/09 14:44:56 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region "Headers"
// System
#include <sys/time.h>
#include <unistd.h>

// Global
#include "type.h"
#include "config.h"

// Modules
#include "_philosopher.h"
#include "utils.h"
#include "debug.h"

#pragma endregion "Headers"
#pragma region "Functions"

/** */
__attribute__((hot)) void	info(
	const t_state info,
	const t_philo *restrict philo,
	const int time
)
{
	static const char	*infos[5] = {
		[thinking] = " is thinking",
		[eating] = " is eating",
		[sleeping] = " is sleeping",
		[dead] = " died",
		[take_fork] = " is taking a fork",
	};

	lock_print();
	printf("| %d | %d | philo %d%s\n" RESET, philo->color, time, philo->id + 1,
		infos[info]);
	unlock_print();
}

/** */
__attribute__((used, always_inline)) void	eat(
	t_philo *philo
)
{
	const int	time = get_ms_time();
	static int	eat_time = -1;
	const int	max_meals = get_data(nb_meals);

	print_debug("eat()");	// rm
	if (__builtin_expect(eat_time == -1, unexpected))
		eat_time = get_data(time_to_eat);
	pthread_mutex_lock(philo->left_fork);
	if (philo->right_fork != philo->left_fork)
		pthread_mutex_lock(philo->right_fork);
	pthread_mutex_lock(philo->lock);
	info(eating, philo, time);
	philo->last_meal = time;
	++philo->nb_meals;
	if (max_meals > 0 && philo->nb_meals == max_meals)
		philo->state = finish;
	else
		philo->state = sleeping;
	usleep(eat_time);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->lock);
}

/** */
__attribute__((used, always_inline)) void	think(
	t_philo *philo
)
{
	print_debug("think()");	// rm
	pthread_mutex_lock(philo->lock);
	info(thinking, philo, get_ms_time());
	philo->state = eating;
	pthread_mutex_unlock(philo->lock);
}

/** */
__attribute__((used, always_inline)) void	mein_sleep(
	t_philo *philo,
	const int sleep_time
)
{
	print_debug("mein_sleep()");	// rm
	pthread_mutex_lock(philo->lock);
	info(sleeping, philo, get_ms_time());
	pthread_mutex_unlock(philo->lock);
	usleep(sleep_time);
	pthread_mutex_lock(philo->lock);
	philo->state = thinking;
	pthread_mutex_unlock(philo->lock);
}

#pragma endregion "Functions"