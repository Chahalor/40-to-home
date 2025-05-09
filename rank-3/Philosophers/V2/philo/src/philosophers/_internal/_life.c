/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _life.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 13:09:14 by nduvoid           #+#    #+#             */
/*   Updated: 2025/05/09 14:14:05 by nduvoid          ###   ########.fr       */
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
__attribute__((always_inline, used)) static inline void	_add_meal(
	const int nb_philos
)
{
	global_storage(request_add_finished);
	if (__builtin_expect(global_storage(request_get_finished) == nb_philos,
			unexpected))
		global_storage(request_stop);
}

/** */
__attribute__((hot)) void	_eat(
	t_philo *philo
)
{
	t_mutex	*first;
	t_mutex	*second;

	_lock_forks(philo, &first, &second);
	philo->info(philo, eating);
	philo->last_meal = get_ms_time();
	ft_usleep((philo->data.time_to_eat * 1000));
	lock(philo->lock);
	philo->status = sleeping;
	++philo->nb_meals;
	if (philo->data.nb_meals != -1
		&& philo->nb_meals == philo->data.nb_meals)
		_add_meal(philo->data.nb_philo);
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
	philo->info(philo, sleeping);
	ft_usleep((philo->data.time_to_sleep * 1000));
	lock(philo->lock);
	philo->status = thinking;
	unlock(philo->lock);
}

/** */
__attribute__((hot)) void	_think(
	t_philo *philo
)
{
	philo->info(philo, thinking);
	lock(philo->lock);
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