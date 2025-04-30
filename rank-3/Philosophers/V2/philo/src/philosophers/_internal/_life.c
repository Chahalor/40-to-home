/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _life.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 13:09:14 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/30 16:37:38 by nduvoid          ###   ########.fr       */
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
__attribute__((always_inline, used)) static inline void	_starvation(
	t_philo *philo,
	t_mutex *first,
	t_mutex *second
)
{
	unlock(first);
	if (__builtin_expect(philo->left_fork != philo->right_fork, expected))
		unlock(second);
	philo->die(philo);
}

/** */
__attribute__((hot)) void	_eat(
	t_philo *philo
)
{
	t_mutex	*first;
	t_mutex	*second;
	t_time	diff;

	_lock_forks(philo, &first, &second);
	diff = get_ms_time() - philo->last_meal;
	if (__builtin_expect(diff >= philo->data.time_to_die, unexpected))
		return (_starvation(philo, first, second));
	lock(philo->lock);
	if (philo->data.nb_meals != -1
		&& philo->nb_meals == philo->data.nb_meals)
		global_storage(request_add_finished);
	philo->info(philo, eating);
	ft_usleep((philo->data.time_to_eat * 1000)
		+ (philo->data.time_to_eat == 0));
	philo->status = sleeping;
	++philo->nb_meals;
	philo->last_meal = get_ms_time();
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
	philo->info(philo, sleeping);
	ft_usleep((philo->data.time_to_sleep * 1000)
		+ (philo->data.time_to_sleep == 0));
	philo->status = thinking;
	unlock(philo->lock);
}

/** */
__attribute__((hot)) void	_think(
	t_philo *philo
)
{
	lock(philo->lock);
	philo->info(philo, thinking);
	philo->status = eating;
	unlock(philo->lock);
}

/** */
__attribute__((hot)) void	_die(
	t_philo *philo
)
{
	lock(philo->lock);
	philo->status = died;
	unlock(philo->lock);
	philo->info(philo, died);
	global_storage(request_stop);
}

#pragma endregion Functions