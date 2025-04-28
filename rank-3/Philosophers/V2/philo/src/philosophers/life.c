/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 14:58:38 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/28 13:58:44 by nduvoid          ###   ########.fr       */
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
	else if (__builtin_expect(global_manager(request_get_finished)
			>= philo->data.nb_philo, unexpected))
	{
		global_manager(request_stop);
		return (true);
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
	philo->eat(philo);
	while (global_manager(request_get_run) == true)
	{
		if (_should_quit(philo))
			break ;
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