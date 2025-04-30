/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 08:47:53 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/30 15:32:00 by nduvoid          ###   ########.fr       */
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
	while (__builtin_expect(i < nb_philo, expected))
	{
		pthread_create(&threads[i], NULL, circle_of_life, &philosopher[i]);
		i += 2;
	}
	ft_usleep(100);
	i = -1;
	while (__builtin_expect(i + 2 < nb_philo, expected))
	{
		i += 2;
		pthread_create(&threads[i], NULL, circle_of_life, &philosopher[i]);
	}
	return (0);
}

/** */
__attribute__((cold)) int	launch_simu(
	t_philo *philosophers,
	const t_philo_data data,
	const int display
)
{
	t_thread		*threads;
	register int	i;
	t_bool			a_dead;

	threads = (t_thread *)malloc(sizeof(t_thread) * (data.nb_philo));
	if (__builtin_expect(!threads, unexpected))
		return (-1);
	global_storage(request_init);
	init_display(data, &philosophers[0], display);
	lauch_philo(threads, philosophers, data.nb_philo);
	a_dead = false;
	i = -1;
	while (__builtin_expect(++i < data.nb_philo, expected))
	{
		pthread_join(threads[i], NULL);
		a_dead = a_dead == true || philosophers[i].status == died;
	}
	global_storage(request_destroy);
	free(threads);
	return (a_dead);
}

#pragma endregion Functions