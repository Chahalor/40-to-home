/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _life.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 13:09:14 by nduvoid           #+#    #+#             */
/*   Updated: 2025/05/06 16:23:37 by nduvoid          ###   ########.fr       */
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
	swait(philo->forks);
	philo->info(philo, forks);
	swait(philo->forks);
	philo->info(philo, forks);
	philo->info(philo, eating);
	ft_usleep(philo->data.time_to_eat * 1000);
	swait(philo->lock);
	philo->status = sleeping;
	++philo->nb_meals;
	if (philo->data.nb_meals != -1
			&& philo->nb_meals == philo->data.nb_meals)
		sem_post(philo->finished);
	philo->last_meal = get_ms_time();
	post(philo->lock);
	post(philo->forks);
	post(philo->forks);
}

/** */
__attribute__((hot)) void	_sleep(
	t_philo *philo
)
{
	swait(philo->forks);
	philo->status = thinking;
	post(philo->forks);
	philo->info(philo, sleeping);
	ft_usleep(philo->data.time_to_sleep * 1000);
}

/** */
__attribute__((hot)) void	_think(
	t_philo *philo
)
{
	swait(philo->forks);
	philo->status = eating;
	post(philo->forks);
	philo->info(philo, thinking);
}

/** */
__attribute__((hot)) void	_die(
	t_philo *philo
)
{
	swait(philo->lock);
	philo->status = died;
	post(philo->lock);
	philo->info(philo, died);
	post(philo->run);
}

#pragma endregion Functions