/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 08:47:53 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/24 08:55:02 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Headers

/* -----| Internal |----- */
	//...

/* -----| Modules  |----- */
#include "threads.h"

#pragma endregion Headers
#pragma region Functions

/** */
__attribute__((cold)) int	launch_simu(
	t_philo *philosophers,		/* the philosophers list */
	const t_philo_data data		/* the simulation data  */
)
{
	t_thread		*threads;
	t_watcher		watcher;
	register int	i;

	threads = (t_thread *)malloc(sizeof(t_thread) * (data.nb_philo + 1));
	if (__builtin_expect(!threads, unexpected))
		return (-1);
	watcher.philosophers = philosophers;
	watcher.data = data;
	pthread_create(&threads[data.nb_philo], NULL, big_brother, &watcher);
	i = -1;
	while (++i < data.nb_philo)
		pthread_create(&threads[i], NULL, circle_of_life, &philosophers[i]);
	pthread_join(threads[data.nb_philo], NULL);
	i = -1;
	while (++i < data.nb_philo)
		pthread_join(threads[i], NULL);
	free(threads);
	return (0);
}

#pragma endregion Functions