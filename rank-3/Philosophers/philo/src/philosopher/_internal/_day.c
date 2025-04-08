/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _day.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 10:59:19 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/08 16:55:48 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region "Headers"
// System
#include <sys/time.h>

// Global
#include "type.h"
#include "config.h"

// Modules
#include "_philosopher.h"

#pragma endregion "Headers"
#pragma region "Functions"

/** */
__attribute__((used, always_inline)) void	eat(
	t_philo *philo
)
{
	pthread_mutex_lock(philo->left_fork);
	pthread_mutex_lock(philo->right_fork);
	info(eat, philo)
}

/** */
__attribute__((used, always_inline)) void	think(
	t_philo *philo
)
{
	(void)philo;
	// think(1);
}

/** */
__attribute__((used, always_inline)) void	die(
	t_philo *philo
)
{
	(void)philo;
	// die(1);
}

#pragma endregion "Functions"