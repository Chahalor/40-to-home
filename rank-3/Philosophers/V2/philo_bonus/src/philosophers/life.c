/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 14:58:38 by nduvoid           #+#    #+#             */
/*   Updated: 2025/05/07 11:28:22 by nduvoid          ###   ########.fr       */
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
__attribute__((always_inline, used)) static inline t_bool	_should_quit(
	t_philo *philo
)
{
	t_bool	result;

	result = false;
	swait(philo->lock);
	if (__builtin_expect(philo->status == died, unexpected))
		result = true;
	post(philo->lock);
	return (result);
}

/** */
__attribute__((cold)) void	*_watcher(
	void *arg
)
{
	t_philo	*philo;
	int		diff;

	philo = (t_philo *)arg;
	if (__builtin_expect(!philo, unexpected))
		return (NULL);
	while (true)
	{
		swait(philo->lock);
		diff = get_ms_time() - philo->last_meal;
		if (__builtin_expect(diff >= (int)philo->data.time_to_die, unexpected))
		{
			post(philo->lock);
			philo->die(philo);
			return (NULL);
		}
		post(philo->lock);
		ft_usleep(100);
	}
}

/** */
__attribute__((always_inline, used)) static inline t_bool	_open_sem(
	const int id,
	char buffer[32],
	sem_t **lock
)
{
	ft_memcpy(buffer, "philo_secu_", 12);
	ft_sprintf(buffer + 11, id);
	sem_unlink(buffer);
	*lock = sem_open(buffer, O_CREAT, 0644, 1);
	if (*lock == SEM_FAILED)
	{
		printf(RED ERROR RESET "sem_open failed for \"%s\" (%d)\n",
			buffer, id);
		return (false);
	}
	return (true);
}

/** */
__attribute__((cold)) int	circle_of_life(
	t_philo *philo
)
{
	t_thread	thread;
	char		buffer[32];

	if (!_open_sem(philo->id, buffer, &philo->lock))
		return (-1);
	else if (philo->data.nb_philo < 2)
		return (_one(philo));
	pthread_create(&thread, NULL, _watcher, philo);
	philo->last_meal = get_ms_time();
	while (!_should_quit(philo))
	{
		if (philo->status == eating)
			philo->eat(philo);
		else if (philo->status == sleeping)
			philo->sleep(philo);
		else if (philo->status == thinking)
			philo->think(philo);
	}
	post(philo->finished);
	post(philo->run);
	_exit_process(philo, philo->lock);
	return (0);
}

#pragma endregion Functions