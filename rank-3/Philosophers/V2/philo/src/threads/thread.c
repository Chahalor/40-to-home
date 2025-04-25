/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 08:47:53 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/25 20:01:32 by nduvoid          ###   ########.fr       */
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
__attribute__((always_inline, used)) static inline int	lauch_philo(
	t_thread *threads,
	t_philo *philosopher,
	const int nb_philo
)
{
	register int	i;

	i = -1;
	while (i + 2 < nb_philo - 1)
	{
		i += 2;
		pthread_create(&threads[i], NULL, circle_of_life, &philosopher[i]);
	}
	ft_usleep(10);
	i = 0;
	while (i < nb_philo)
	{
		pthread_create(&threads[i], NULL, circle_of_life, &philosopher[i]);
		i += 2;
	}
	return (0);
}

/** */
__attribute__((cold)) int	launch_simu(
	t_philo *philosophers,
	const t_philo_data data
)
{
	t_thread		*threads;
	t_watcher		watcher;
	register int	i;

	threads = (t_thread *)malloc(sizeof(t_thread) * (data.nb_philo + 1));
	if (__builtin_expect(!threads, unexpected))
		return (-1);
	global_manager(request_init);
	info(-1, get_ms_time(), "Start of the simulation");
	watcher.philosophers = philosophers;
	watcher.data = data;
	printf("launch_simu(): nb_meals: %d, nb_philo: %d\n", data.nb_meals, data.nb_philo); // rm
	pthread_create(&threads[data.nb_philo], NULL, big_brother, &watcher);
	lauch_philo(threads, philosophers, data.nb_philo);
	pthread_join(threads[data.nb_philo], NULL);
	i = -1;
	while (++i < data.nb_philo)
		pthread_join(threads[i], NULL);
	global_manager(request_destroy);
	free(threads);
	return (0);
}

#pragma endregion Functions