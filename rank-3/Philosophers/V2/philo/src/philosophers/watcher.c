/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   watcher.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 08:40:47 by nduvoid           #+#    #+#             */
/*   Updated: 2025/05/02 14:18:03 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Headers

/* -----| Internal |----- */
#include "_philosopher.h"

/* -----| Modules  |----- */
#include "philosophers.h"

#pragma endregion Headers
#pragma region Functions

/** */
__attribute__((cold)) void	*watcher(
	void *arg
)
{
	const t_philo		*philosophers = (t_philo *)arg;
	const t_philo_data	data = philosophers->data;
	register int		i;
	t_philo				*philo;

	if (__builtin_expect(!data.nb_philo, unexpected))
		return ((void)global_storage(request_stop), NULL);
	i = -1;
	while (__builtin_expect(global_storage(request_get_run), expected))
	{
		i = (i + 1) % data.nb_philo;
		philo = (t_philo *)&philosophers[i];
		lock(philo->lock);
		if (__builtin_expect(get_ms_time() - philo->last_meal
				>= data.time_to_die, unexpected))
		{
			unlock(philo->lock);
			philo->die(philo);
		}
		else
			unlock(philo->lock);
		ft_usleep(100);
	}
	global_storage(request_stop);
	return (NULL);
}

#pragma endregion Functions