/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 14:58:38 by nduvoid           #+#    #+#             */
/*   Updated: 2025/05/09 09:07:05 by nduvoid          ###   ########.fr       */
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
__attribute__((hot)) void	*circle_of_life(
	void *arg
)
{
	t_philo		*philo;
	t_status	status;

	philo = (t_philo *)arg;
	if (__builtin_expect(philo->data.nb_philo < 2, unexpected))
	{
		philo->info(philo, forks);
		ft_usleep(philo->data.time_to_eat * 1000);
		printf("  The philosopher is too civilized to eat with one fork. "
			"He prefers dying of starvation.\n");
		return (NULL);
	}
	while (__builtin_expect(global_storage(request_get_run) == true, expected))
	{
		lock(philo->lock);
		status = philo->status;
		unlock(philo->lock);
		if (status == eating)
			philo->eat(philo);
		else if (status == sleeping)
			philo->sleep(philo);
		else if (status == thinking)
			philo->think(philo);
	}
	return (NULL);
}

#pragma endregion Functions