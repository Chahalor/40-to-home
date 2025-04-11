/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _life.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 15:06:54 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/11 15:39:39 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region "Headers"

/* --- Global --- */
# include "config.h"
# include "type.h"

/* --- Intern --- */
#include "_philosopher.h"
#include "philosopher.h"

#pragma endregion "Headers"
#pragma region "Functions"

/** */
__attribute__((hot)) void	info(
	const int id,
	t_status status,
	const int timer
)
{
	static const char	*msg[6] = {
		[fork] = "has taken a fork",
		[thinking] = "is thinking",
		[eating] = "is eating",
		[sleeping] = "is sleeping",
		[dead] = "is dead"
	};
	static int			start_time = 0;
	static t_mutex		*print_lock = NULL;

	if (__builtin_expect(!start_time, unexpected))
		start_time = get_ms_time();
	if (__builtin_expect(!print_lock, unexpected))
		print_lock = get_data(print);
	pthread_mutex_lock(print_lock);
	printf("%3d.%-3d | %3d %s\n", (timer - start_time) / 1000,
		(timer - start_time) % 1000, id, msg[status]);
	pthread_mutex_lock(print_lock);
}

/** */
__attribute__((hot)) void	_eat(
	t_philo *philosopher
)
{
	pthread_mutex_lock(philosopher->left_fork);
	info(philosopher->id, fork, get_ms_time());

	pthread_mutex_lock(philosopher->right_fork);
	info(philosopher->id, fork, get_ms_time());

	philosopher->last_meal = get_ms_time();
	++philosopher->eat_count;
	info(philosopher->id, eating, philosopher->last_meal);
	usleep(philosopher->data.time_to_eat * 1000);

	pthread_mutex_unlock(philosopher->right_fork);
	pthread_mutex_unlock(philosopher->left_fork);
	philosopher->status = sleeping;
}

/** */
__attribute__((hot)) void	_sleep(
	t_philo *philosopher
)
{
	info(philosopher->id, sleeping, get_ms_time());
	usleep(philosopher->data.time_to_sleep * 1000);
	philosopher->status = thinking;
}

/** */
__attribute__((hot)) void	_think(
	t_philo *philosopher
)
{
	info(philosopher->id, thinking, get_ms_time());
	philosopher->status = eating;
}

/** */
__attribute__((hot)) void	_death(
	t_philo *philosopher
)
{
	info(philosopher->id, dead, get_ms_time());
	philosopher->status = dead;
}

#pragma endregion "Functions"