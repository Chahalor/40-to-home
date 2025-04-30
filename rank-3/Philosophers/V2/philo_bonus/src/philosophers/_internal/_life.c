/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _life.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 13:09:14 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/30 13:52:51 by nduvoid          ###   ########.fr       */
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
	const int nb_forks
)
{
	sem_post(philo->forks);
	if (nb_forks > 1)
		sem_post(philo->forks);
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

	sem_wait(philo->forks);
	philo->info(philo, forks);
	diff = get_ms_time() - philo->last_meal;
	if (__builtin_expect(diff >= philo->data.time_to_die, unexpected))
		return (_starvation(philo, 1));
	sem_wait(philo->forks);
	philo->info(philo, forks);
	diff = get_ms_time() - philo->last_meal;
	if (__builtin_expect(diff >= philo->data.time_to_die, unexpected))
		return (_starvation(philo, 2));
	philo->status = sleeping;
	if (philo->data.nb_meals != -1
		&& philo->nb_meals == philo->data.nb_meals)
		global_storage(request_add_finished);
	philo->info(philo, eating);
	ft_usleep(philo->data.time_to_eat * 1000 + philo->data.time_to_eat == 0);
	philo->last_meal = get_ms_time();
	++philo->nb_meals;
	sem_post(philo->forks);
	sem_post(philo->forks);
}

/** */
__attribute__((hot)) void	_sleep(
	t_philo *philo
)
{
	philo->status = thinking;
	philo->info(philo, sleeping);
	ft_usleep(philo->data.time_to_sleep * 1000);
}

/** */
__attribute__((hot)) void	_think(
	t_philo *philo
)
{
	philo->status = eating;
	philo->info(philo, thinking);
}

/** */
__attribute__((hot)) void	_die(
	t_philo *philo
)
{
	philo->status = died;
	philo->info(philo, died);
	global_storage(request_stop);
}

#pragma endregion Functions