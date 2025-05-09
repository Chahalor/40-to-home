/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _utils.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 12:48:48 by nduvoid           #+#    #+#             */
/*   Updated: 2025/05/09 09:11:44 by nduvoid          ###   ########.fr       */
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
__attribute__((always_inline, used)) inline void	_lock_forks(
	t_philo *philo,
	t_mutex **first,
	t_mutex **second
)
{
	*first = philo->left_fork;
	*second = philo->right_fork;
	lock(*first);
	philo->info(philo, forks);
	if (__builtin_expect(philo->left_fork != philo->right_fork, expected))
	{
		lock(*second);
		philo->info(philo, forks);
	}
}

#pragma endregion Functions