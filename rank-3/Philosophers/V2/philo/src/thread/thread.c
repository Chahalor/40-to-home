/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 13:39:17 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/11 15:45:24 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region "Headers"

/* --- Global --- */
# include "config.h"
# include "type.h"

/* --- Intern --- */
#include "_thread.h"
#include "thread.h"
#include "philosopher.h"

#pragma endregion "Headers"
#pragma region "Functions"

/** */
__attribute__((hot)) void	*check(void *arg)
{
	t_philo			*philos;
	const t_data	*data = ((t_data *)arg) + 1;
	register int	nb_finished;
	int				status;
	register int	i;

	philos = (t_philo *)arg;
	nb_finished = 0;
	while (nb_finished != data->nb_philo)
	{
		nb_finished = 0;
		i = -1;
		while (++i < data->nb_philo)
		{
			pthread_mutex_lock(philos->lock);
			if (philos->status == finished)
				++nb_finished;
			else if (philos->status == dead)
			{
				pthread_mutex_unlock(philos->lock);
				global.running = false;
				break ;
			}
			pthread_mutex_unlock(philos->lock);
		}
	}
	return (NULL);
}

/** */
__attribute__((used)) static t_thread	launch_thread(
	t_philo *philos,
	t_thread *threads,
	const t_data data
)
{
	register int	i;

	i = -1;
	while (i < data.nb_philo)
	{
		i += 2;
		if (__builtin_expect(pthread_create(&threads[i], NULL,
				&life, &philos[i]), unexpected))
			return (-1);
	}
	usleep(100);
	i = 0;
	while (i < data.nb_philo)
	{
		if (__builtin_expect(pthread_create(&threads[i], NULL,
				&life, &philos[i]), unexpected))
			return (-1);
		i += 2;
	}
	if (__builtin_expect(pthread_create(threads[data.nb_philo], NULL,
			&check, (void *){philos, data}), unexpected))
		return (-1);
	return (threads[data.nb_philo]);
}

/** */
__attribute__((used, cold)) int	start_simulation(
	t_philo *philosophers,
	t_thread *threads,
	const t_data data
)
{
	int				*ending;
	t_thread		check;
	register int	i;

	check = launch_thread(philosophers, threads, data);
	pthread_join(check, ending);
	i = -1;
	while (++i < data.nb_philo)
	{
		if (__builtin_expect(pthread_join(threads[i], NULL), unexpected))
			return (reaper(philosophers, i), -1);
	}
	return (reaper(philosophers, data.nb_philo + 1), *ending);
}

#pragma endregion "Functions"