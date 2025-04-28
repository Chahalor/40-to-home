/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _life.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 13:09:14 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/28 15:17:50 by nduvoid          ###   ########.fr       */
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
__attribute__((hot)) void	_eat(
	t_philo *philo
)
{
	t_mutex	*first;
	t_mutex	*second;

	_lock_forks(philo, &first, &second);
	lock(philo->lock);
	philo->status = sleeping;
	philo->last_meal = get_ms_time();
	++philo->nb_meals;
	if (philo->data.nb_meals != -1
		&& philo->nb_meals == philo->data.nb_meals)
		global_manager(request_add_finished);
	// info(philo->id, "is eating 🍝");
	display_philo(philo, eating);
	ft_usleep(philo->data.time_to_eat * 1000);
	unlock(philo->lock);
	unlock(first);
	if (__builtin_expect(philo->left_fork != philo->right_fork, expected))
		unlock(second);
}

/** */
__attribute__((hot)) void	_sleep(
	t_philo *philo
)
{
	lock(philo->lock);
	philo->status = thinking;
	// info(philo->id, "is sleeping 💤");
	display_philo(philo, sleeping);
	ft_usleep(philo->data.time_to_sleep * 1000);
	unlock(philo->lock);
}

/** */
__attribute__((hot)) void	_think(
	t_philo *philo
)
{
	lock(philo->lock);
	philo->status = eating;
	unlock(philo->lock);
	// info(philo->id, "is thinking 💭");
	display_philo(philo, thinking);
}

/** */
__attribute__((hot)) void	_die(
	t_philo *philo
)
{
	lock(philo->lock);
	philo->status = died;
	unlock(philo->lock);
	// info(philo->id, "died 🪦");
	display_philo(philo, died);
	global_manager(request_stop);
}

#pragma endregion Functions