/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _life.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 13:09:14 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/23 13:26:33 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Headers

/* -----| Internal |----- */
	//...

/* -----| Modules  |----- */
#include "philosophers.h"

#include "utils.h"

#pragma endregion Headers
#pragma region Functions

/** */
void	_eat(
	t_philo *philo
)
{
	lock(philo->left_fork);
	info(philo->id, get_ms_time(), "has taken a fork");
	if (__builtin_expect(philo->right_fork != philo->left_fork, unexpected))
	{
		lock(philo->right_fork);
		info(philo->id, get_ms_time(), "has taken a fork");
	}
	lock(philo->lock);
	philo->status = sleeping;
	philo->last_meal = get_ms_time();
	info(philo->id, philo->last_meal, "is eating");
	ft_usleep(philo->data.time_to_eat);
	unlock(philo->lock);
	unlock(philo->left_fork);
	if (__builtin_expect(philo->right_fork != philo->left_fork, unexpected))
		unlock(philo->right_fork);
}

/** */
void	_sleep(
	t_philo *philo
)
{
	lock(philo->lock);
	philo->status = thinking;
	info(philo->id, get_ms_time(), "is sleeping");
	ft_usleep(philo->data.time_to_sleep);
	unlock(philo->lock);
}

/** */
void	_think(
	t_philo *philo
)
{
	lock(philo->lock);
	philo->status = eating;
	unlock(philo->lock);
	info(philo->id, get_ms_time(), "is thinking");
}

/** */
void	_die(
	t_philo *philo
)
{
	lock(philo->lock);
	philo->status = died;
	info(philo->id, get_ms_time(), "died");
	unlock(philo->lock);
}

#pragma endregion Functions