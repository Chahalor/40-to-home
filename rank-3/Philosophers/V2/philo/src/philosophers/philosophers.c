/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 12:29:30 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/24 13:29:08 by nduvoid          ###   ########.fr       */
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
__attribute__((malloc, cold)) static t_mutex	*init_mutex(
	register int nb_mutex	/* the number of mutexes to create */
)
{
	t_mutex			*forks;
	register int	i;

	forks = (t_mutex *)malloc(sizeof(t_mutex) * nb_mutex);
	if (__builtin_expect(!forks, unexpected))
		return (NULL);
	i = -1;
	while (++i < nb_mutex)
	{
		if (__builtin_expect(pthread_mutex_init(&forks[i], NULL) != 0,
				unexpected))
			return (destroy_mutex(&forks, i), NULL);
	}
	return (forks);
}

/** */
__attribute__((malloc, cold)) static t_philo	*init_philo(
	const register int nb_philos,
	t_mutex *restrict *restrict forks,
	const t_philo_data data
)
{
	const int		time_start = get_ms_time();
	t_philo			*philosophers;
	register int	i;

	philosophers = (t_philo *)malloc(sizeof(t_philo) * nb_philos);
	if (!philosophers)
		return (NULL);
	i = -1;
	while (++i < nb_philos)
	{
		philosophers[i] = (t_philo){
			.id = i,
			.last_meal = time_start,
			.status = eating,
			.lock = forks[nb_philos + i],
			.left_fork = forks[i],
			.right_fork = forks[(i + 1) % nb_philos],
			.data = data,
			.eat = _eat, .sleep = _sleep, .think = _think, .die = _die
		};
	}
	return (philosophers);
}

/** */
__attribute__((cold)) void	destroy_mutex(
	t_mutex *restrict *restrict forks,
	const int nb_forks
)
{
	register int	i;

	if (!forks || !*forks)
		return ;
	i = -1;
	while (++i < nb_forks)
		pthread_mutex_destroy(&(*forks)[i]);
	free(*forks);
	*forks = NULL;
}

/** */
__attribute__((cold)) void	destroy_philos(
	t_philo *restrict *restrict philosophers	/* the philosophers list      */
)
{
	if (!philosophers || !*philosophers)
		return ;
	free(*philosophers);
	*philosophers = NULL;
}

/** */
__attribute__((cold)) int	init_all(
	t_mutex **forks,
	t_philo *restrict *restrict philosophers,
	t_philo_data data
)
{
	*forks = init_mutex(3 * data.nb_philo);
	if (__builtin_expect(!*forks, unexpected))
		return (-1);
	*philosophers = init_philo(data.nb_philo, forks, data);
	if (__builtin_expect(!*philosophers, unexpected))
		return (destroy_mutex(forks, data.nb_philo), -1);
	return (0);
}

#pragma endregion Functions