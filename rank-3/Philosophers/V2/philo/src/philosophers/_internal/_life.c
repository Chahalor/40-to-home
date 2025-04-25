/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _life.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 13:09:14 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/25 19:53:47 by nduvoid          ###   ########.fr       */
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

// /** */
// void	_eat(
// 	t_philo *philo
// )
// {
// 	lock(philo->left_fork);
// 	info(philo->id, get_ms_time(), "has taken a fork 🍴");
// 	if (__builtin_expect(philo->right_fork != philo->left_fork, expected))
// 	{
// 		lock(philo->right_fork);
// 		info(philo->id, get_ms_time(), "has taken a fork 🍴");
// 	}
// 	lock(philo->lock);
// 	if (__builtin_expect(philo->status == died || !global_manager(request_get_run), unexpected))
// 	{
// 		unlock(philo->left_fork);
// 		if (__builtin_expect(philo->right_fork != philo->left_fork, expected))
// 			unlock(philo->right_fork);
// 		unlock(philo->lock);
// 		return ;
// 	}
// 	philo->status = sleeping;
// 	philo->last_meal = get_ms_time();
// 	++philo->nb_meals;
// 	if (philo->data.nb_meals != -1
// 			&& philo->nb_meals >= philo->data.nb_meals)
// 		global_manager(request_add_finished);
// 	info(philo->id, philo->last_meal, "is eating 🍝");
// 	ft_usleep(philo->data.time_to_eat * 1000);
// 	unlock(philo->lock);
// 	unlock(philo->left_fork);
// 	if (__builtin_expect(philo->right_fork != philo->left_fork, expected))
// 		unlock(philo->right_fork);
// 	ft_usleep(10);
// }

/** */
void	_eat(
	t_philo *philo
)
{
	t_mutex	*first;
	t_mutex	*second;

	if (philo->left_fork < philo->right_fork)
	{
		first = philo->left_fork;
		second = philo->right_fork;
	}
	else
	{
		first = philo->right_fork;
		second = philo->left_fork;
	}

	lock(first);
	info(philo->id, get_ms_time(), "has taken a fork 🍴");
	if (__builtin_expect(philo->left_fork != philo->right_fork, expected))
	{
		lock(second);
		info(philo->id, get_ms_time(), "has taken a fork 🍴");
	}

	lock(philo->lock);
	if (__builtin_expect(philo->status == died || !global_manager(request_get_run), unexpected))
	{
		unlock(first);
		if (__builtin_expect(philo->left_fork != philo->right_fork, expected))
			unlock(second);
		unlock(philo->lock);
		return ;
	}

	philo->status = sleeping;
	philo->last_meal = get_ms_time();
	++philo->nb_meals;
	if (philo->data.nb_meals != -1
		&& philo->nb_meals >= philo->data.nb_meals)
		global_manager(request_add_finished);

	info(philo->id, philo->last_meal, "is eating 🍝");
	ft_usleep(philo->data.time_to_eat * 1000);
	unlock(philo->lock);
	unlock(first);
	if (__builtin_expect(philo->left_fork != philo->right_fork, expected))
		unlock(second);
	ft_usleep(10);
}


/** */
void	_sleep(
	t_philo *philo
)
{
	lock(philo->lock);
	if (__builtin_expect(philo->status == died || !global_manager(request_get_run), unexpected))
	{
		unlock(philo->lock);
		return ;
	}
	philo->status = thinking;
	info(philo->id, get_ms_time(), "is sleeping 💤");
	ft_usleep(philo->data.time_to_sleep * 1000);
	unlock(philo->lock);
	ft_usleep(10);
}

/** */
void	_think(
	t_philo *philo
)
{
	lock(philo->lock);
	if (__builtin_expect(philo->status == died || !global_manager(request_get_run), unexpected))
	{
		unlock(philo->lock);
		return ;
	}
	philo->status = eating;
	unlock(philo->lock);
	info(philo->id, get_ms_time(), "is thinking 💭");
}

/** */
void	_finish(
	t_philo *philo
)
{
	(void)philo;
}

/** */
void	_die(
	t_philo *philo
)
{
	lock(philo->lock);
	philo->status = died;
	info(philo->id, get_ms_time(), "died 🪦");
	unlock(philo->lock);
	ft_usleep(10);
}

#pragma endregion Functions