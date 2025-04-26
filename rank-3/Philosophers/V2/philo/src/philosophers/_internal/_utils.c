/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _utils.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 12:48:48 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/26 16:32:21 by nduvoid          ###   ########.fr       */
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
__attribute__((always_inline, used)) inline void	_set_mutex(
	t_philo *philo,
	t_mutex **first,
	t_mutex **second
)
{
	if (philo->left_fork < philo->right_fork)
	{
		*first = philo->left_fork;
		*second = philo->right_fork;
	}
	else
	{
		*first = philo->right_fork;
		*second = philo->left_fork;
	}
}

/** */
__attribute__((always_inline, used)) inline void	_lock_forks(
	t_philo *philo,
	t_mutex **first,
	t_mutex **second
)
{
	_set_mutex(philo, first, second);
	lock(*first);
	info(philo->id, "has taken a fork 🍴");
	if (__builtin_expect(philo->left_fork != philo->right_fork, expected))
	{
		lock(*second);
		info(philo->id, "has taken a fork 🍴");
	}
}



#pragma endregion Functions