/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 14:58:38 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/25 19:57:02 by nduvoid          ###   ########.fr       */
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
void	info(
	const int id,
	const t_time time,
	const char *msg
)
{
	static t_time	time_start = 0;

	if (__builtin_expect(!msg, unexpected))
		return ;
	else if (__builtin_expect(id == -1, unexpected))
		time_start = get_ms_time();
	printf(CYAN "[" YELLOW "%3d.%-3d" CYAN "] " RESET "%-3d %s\n",
		(time - time_start) / 1000, (time - time_start) % 1000, id, msg);
}

/** */
__attribute__((hot)) void	*circle_of_life(
	void *arg	/* the t_philo struct needed by the thread */
)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	info(philo->id, get_ms_time(), "✅ thread started");
	int state = global_manager(request_get_run);	// move this in the while
	while (state == true)
	{
		if (philo->status == eating)
			philo->eat(philo);
		else if (philo->status == sleeping)
			philo->sleep(philo);
		else if (philo->status == thinking)
			philo->think(philo);
		else if (philo->status == died)
			return (NULL);
		state = global_manager(request_get_run);
	}
	info(philo->id, get_ms_time(), "❌ thread stopped");
	global_manager(request_stop);
	return (NULL);
}

#pragma endregion Functions