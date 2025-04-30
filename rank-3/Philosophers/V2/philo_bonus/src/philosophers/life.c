/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 14:58:38 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/30 10:46:35 by nduvoid          ###   ########.fr       */
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
static inline t_bool	_should_quit(
	t_philo *philo
)
{
	if (__builtin_expect(get_ms_time() - philo->last_meal
			>= philo->data.time_to_die, unexpected))
	{
		philo->die(philo);
		return (true);
	}
	else if (__builtin_expect(global_storage(request_get_finished)
			>= philo->data.nb_philo || !philo->data.nb_meals, unexpected))
	{
		global_storage(request_stop);
		return (true);
	}
	else if (__builtin_expect(philo->data.nb_philo < 2, unexpected))
	{
		philo->info(philo, forks);
		ft_usleep(philo->data.time_to_die * 1000);
		printf("The philosopher %d is too civilized to eat with one fork. "
			"He prefers to die of starvation.\n", philo->id);
		philo->die(philo);
	}
	return (false);
}

/** */
__attribute__((hot)) void	*circle_of_life(
	void *arg
)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (global_storage(request_get_run) == true)
	{
		if (_should_quit(philo))
			break ;
		printf("  philo %d status: %d\n", philo->id, philo->status);
		if (philo->status == eating)
			philo->eat(philo);
		else if (philo->status == sleeping)
			philo->sleep(philo);
		else if (philo->status == thinking)
			philo->think(philo);
	}
	return (NULL);
}

#pragma endregion Functions