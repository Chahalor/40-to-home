/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 14:58:38 by nduvoid           #+#    #+#             */
/*   Updated: 2025/05/05 17:27:52 by nduvoid          ###   ########.fr       */
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
__attribute__((always_inline, used, noreturn)) static inline void	_quit(
	t_philo *philo,
	const char *name
)
{
	sem_close(philo->lock);
	sem_close(philo->forks);
	sem_unlink(name);
	exit(philo->status);
}

/** */
__attribute__((always_inline, used)) static inline t_bool	_should_quit(
	t_philo *philo
)
{
	if (__builtin_expect(philo->status == died, unexpected))
		return (true);
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
__attribute__((cold)) void	*_watcher(
	void *arg
)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (__builtin_expect(!philo, unexpected))
		return (NULL);
	while (true)
	{
		wait(philo->lock);
		const t_time diff = get_ms_time() - philo->last_meal;
		if (__builtin_expect(diff >= philo->data.time_to_die, unexpected))
		{
			printf("Philosopher %d died, diff=%u, time_to_die=%d\n", philo->id, diff, philo->data.time_to_die);
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
	static char	sema_name[32] = DEFAULT_SEMA_DIR DEFAULT_SEMA_LOCK;	// @todo: add a proper way to change the sema name
	t_thread	thread;

	thread = philo->id % 2;
	sema_name[sizeof(DEFAULT_SEMA_DIR) + sizeof(DEFAULT_SEMA_LOCK) - 1] = '0' + philo->id;
	sem_open(sema_name, O_CREAT | O_EXCL, 0644, 1);
	pthread_create(&thread, NULL, _watcher, philo);
	while (true)
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
	printf("Philosopher %d after while\n", philo->id);
	_quit(philo, sema_name);
}

#pragma endregion Functions