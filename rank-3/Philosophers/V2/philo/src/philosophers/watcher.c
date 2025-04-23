/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   watcher.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 14:39:19 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/23 14:56:45 by nduvoid          ###   ########.fr       */
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
__attribute__((cold)) void	*watcher(
	void *arg	/* the t_wacher struct needed by the thread */
)
{
	const t_watcher		*watcher = (t_watcher *)arg;
	t_philo				*philosophers = watcher->philosophers;
	register int		i;
	int					running;
	int					nb_finished;

	running = 1;
	while (running)
	{
		nb_finished = 0;
		i = -1;
		while (++i < watcher->data.nb_philo)
		{
			if (unexpect(philosophers[i].last_meal - get_ms_time()
				> watcher->data.time_to_die))
				philosophers[i].die(&philosophers[i]);
			else if (unexpect(philosophers[i].nb_meals >= watcher->data.nb_meals))
			{
				philosophers[i].finish(&philosophers[i]);
				++nb_finished;
			}
			running = (philosophers[i].status != died && nb_finished
				!= watcher->data.nb_philo);
		}
	}
	get_states(&running);
	return (NULL);
}

#pragma endregion Functions