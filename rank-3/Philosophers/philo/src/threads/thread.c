/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 08:47:53 by nduvoid           #+#    #+#             */
/*   Updated: 2025/05/09 09:13:29 by nduvoid          ###   ########.fr       */
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
__attribute__((always_inline, used)) static inline int	_launch_watcher(
	t_thread *thread,
	t_philo *philosopher
)
{
	return (pthread_create(thread, NULL, watcher, philosopher));
}

/** */
__attribute__((always_inline, used)) static inline int	_lauch_philo(
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
	int				corps;
	register int	i;

	threads = (t_thread *)malloc(sizeof(t_thread) * (data.nb_philo + 1));
	if (__builtin_expect(!threads, unexpected))
		return (-1);
	global_storage(request_init);
	init_display(data, &philosophers[0], display);
	_launch_watcher(&threads[data.nb_philo], philosophers);
	_lauch_philo(threads, philosophers, data.nb_philo);
	corps = 0;
	pthread_join(threads[data.nb_philo], NULL);
	i = -1;
	while (__builtin_expect(++i < data.nb_philo, expected))
	{
		pthread_join(threads[i], NULL);
		corps += (philosophers[i].status == died);
	}
	free(threads);
	return (corps);
}

#pragma endregion Functions