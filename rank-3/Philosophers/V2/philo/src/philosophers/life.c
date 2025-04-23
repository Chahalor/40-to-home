/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 14:58:38 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/23 15:24:18 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Headers

/* -----| Internal |----- */
#include "_philosopher.h"

/* -----| Modules  |----- */
#include "philosophers.h"

#pragma endregion Headers
#pragma region Functions

/**
 * 
 */
void	info(
	const int id,		/* the philosopher id     */
	const t_time time,	/* the time of the event */
	const char *msg		/* the message to print */
)
{
	if (__builtin_expect(!msg || id < 0, unexpected))
		return ;
	printf(CYAN "[" YELLOW "%03d" CYAN "] " RESET "%3d %s\n", time, id, msg);
}

/** */
__attribute__((hot)) void	*circle_of_life(
	void *arg	/* the t_philo struct needed by the thread */
)
{
	t_philo	*philo;
	
	philo = (t_philo *)arg;
	while (get_status(NULL))
	{
		if (philo->status == eating)
			philo->eat(philo);
		else if (philo->status == sleeping)
			philo->sleep(philo);
		else if (philo->status == thinking)
			philo->think(philo);
		else if (philo->status == died)
			return (NULL);
	}
	return (NULL);
}

#pragma endregion Functions