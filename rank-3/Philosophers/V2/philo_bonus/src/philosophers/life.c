/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 14:58:38 by nduvoid           #+#    #+#             */
/*   Updated: 2025/05/06 16:47:11 by nduvoid          ###   ########.fr       */
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
	else if (__builtin_expect(philo->data.nb_philo < 2, unexpected))
	{
		philo->info(philo, forks);
		ft_usleep(philo->data.time_to_die * 1000);
		printf("The philosopher %d is too civilized to eat with one fork. "
			"He prefers to die of starvation.\n", philo->id);
		philo->die(philo);
		result = true;
	}
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
__attribute__((cold)) int	circle_of_life(
	t_philo *philo
)
{
	t_thread	thread;
	char	buffer[32];

	ft_memcpy(buffer, "philo_secu_", 12);
	ft_sprintf(buffer + 11, philo->id);
	printf("philo %d is trying to open %s\n", philo->id, buffer);
	sem_unlink(buffer);
	philo->lock = sem_open(buffer,O_CREAT, 0644, 1);
	if (philo->lock == SEM_FAILED)
		return (printf(RED ERROR RESET "sem_open failed for \"%s\" (%d)\n",
			buffer, philo->id));
	pthread_create(&thread, NULL, _watcher, philo);
	pthread_detach(thread);	// useless ?
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
	post(philo->run);
	post(philo->finished);
	_exit_process(philo, philo->lock);
	return (0);
}

#pragma endregion Functions