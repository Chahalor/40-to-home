/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 08:47:53 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/28 10:10:54 by nduvoid          ###   ########.fr       */
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

	i = 0;
	while (i < nb_philo)
	{
		pthread_create(&threads[i], NULL, circle_of_life, &philosopher[i]);
		i += 2;
	}
	ft_usleep(10);
	i = -1;
	while (i + 2 < nb_philo)
	{
		i += 2;
		pthread_create(&threads[i], NULL, circle_of_life, &philosopher[i]);
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
	register int	i;

	threads = (t_thread *)malloc(sizeof(t_thread) * (data.nb_philo));
	if (__builtin_expect(!threads, unexpected))
		return (-1);
	global_manager(request_init);
	global_manager(request_start);
	info(-1, "Start of the simulation");
	lauch_philo(threads, philosophers, data.nb_philo);
	i = -1;
	while (++i < data.nb_philo)
		pthread_join(threads[i], NULL);
	global_manager(request_destroy);
	free(threads);
	return (0);
}

#pragma endregion Functions