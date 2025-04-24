/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   watcher.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 14:39:19 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/24 13:34:59 by nduvoid          ###   ########.fr       */
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
__attribute__((cold)) void	*big_brother(
	void *arg	/* the t_wacher struct needed by the thread */
)
{
	const t_watcher		*watcher = (t_watcher *)arg;
	register int		i;
	int					running;
	int					nb_finished;

	running = 1;
	while (running)
	{
		nb_finished = 0;
		i = -1;
		while (++i < watcher->data.nb_philo && running)
		{
			if (unexpect(watcher->philosophers[i].last_meal - get_ms_time()
					> watcher->data.time_to_die))
				watcher->philosophers[i].die(&watcher->philosophers[i]);
			else if (unexpect(watcher->philosophers[i].nb_meals
					>= watcher->data.nb_meals && ++nb_finished))
				watcher->philosophers[i].finish(&watcher->philosophers[i]);
			running = (watcher->philosophers[i].status != died && nb_finished
					!= watcher->data.nb_philo);
		}
	}
	global_manager(request_stop);
	return (NULL);
}

#pragma endregion Functions