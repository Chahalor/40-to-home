/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   watcher.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 14:39:19 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/25 19:50:02 by nduvoid          ###   ########.fr       */
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
__attribute__((always_inline, used)) static inline t_bool	_is_dead(
	const t_philo philo,
	const t_time now
)
{
	return (now - philo.last_meal >= philo.data.time_to_die);
}

/** */
__attribute__((cold)) void	*big_brother(
	void *arg	/* the t_wacher struct needed by the thread */
)
{
	const t_watcher		*watcher = (t_watcher *)arg;
	register int		i;
	int					running;

	running = 1;
	while (running)
	{
		i = -1;
		while (++i < watcher->data.nb_philo && running)
		{
			lock(watcher->philosophers[i].lock);
			printf("looking at %d\n", i);	// rm
			if (__builtin_expect(_is_dead(watcher->philosophers[i],
					get_ms_time()), unexpected))
				watcher->philosophers[i].die(&watcher->philosophers[i]);
			running = (watcher->philosophers[i].status != died
					&& global_manager(request_get_finished) != watcher->data.nb_philo);
			unlock(watcher->philosophers[i].lock);
		}
	}
	global_manager(request_stop);
	return (NULL);
}
#pragma endregion Functions