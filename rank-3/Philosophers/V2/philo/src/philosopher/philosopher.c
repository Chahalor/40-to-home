/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 13:14:50 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/14 09:27:35 by nduvoid          ###   ########.fr       */
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
__attribute__((hot)) void	*life(
	void *arg
)
{
	t_philo			*philosopher;
	static t_bool	*running = NULL;

	philosopher = (t_philo *)arg;
	if (__builtin_expect(!running, unexpected))
		running = (t_bool *)get_data(run, NULL);
	while (philosopher->status != dead && *running != false)
	{
		pthread_mutex_lock(philosopher->lock);
		if (philosopher->status == dead)
			_death(philosopher);
		else if (philosopher->status == eating)
			_eat(philosopher);
		else if (philosopher->status == sleeping)
			_sleep(philosopher);
		else if (philosopher->status == thinking)
			_think(philosopher);
		pthread_mutex_unlock(philosopher->lock);
	}
	return (NULL);
}

/** */
__attribute__((used, always_inline)) inline void	reaper(
	t_philo *philosophers,
	register int i
)
{
	while (--i >= 0)
	{
		pthread_mutex_destroy(philosophers[i].lock);
		pthread_mutex_destroy(philosophers[i].left_fork);
		pthread_mutex_destroy(philosophers[i].right_fork);
	}
	free(philosophers);
}

/** */
__attribute__((cold, malloc)) t_philo	*build_philos(
	const t_data data
)
{
	t_philo			*philosophers;
	t_mutex			*pool_forks;
	t_mutex			*pool_lock;
	register int	i;

	philosophers = (t_philo *)malloc(sizeof(t_philo) * data.nb_philo
		+ sizeof(t_mutex) * data.nb_philo * 2);
	if (!philosophers)
		return (NULL);
	pool_forks = (t_mutex *)(philosophers + data.nb_philo);
	pool_lock = (t_mutex *)(pool_forks + data.nb_philo);
	i = -1;
	while (++i < data.nb_philo)
	{
		philosophers[i] = (t_philo){
			.lock = &pool_lock[i], .left_fork = &pool_forks[i],
			.right_fork = &pool_forks[(i + 1) % data.nb_philo],
			.data = data, .id = i, .last_meal = get_ms_time(),
			.eat_count = 0, .status = thinking,
		};
	}
	return (init_mutex(philosophers, data));
}

#pragma endregion "Functions"