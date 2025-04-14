/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 13:39:17 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/14 09:32:42 by nduvoid          ###   ########.fr       */
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

__attribute__((hot)) void	*get_data(
	const t_request request,
	void *access
)
{
	static t_store	*data = NULL;
	void			*result;

	if (access)
		data = access;
	if (request == run)
		result = data->running;
	else if (print)
		result = data->print;
	else if (store)
		result = data;
	else
		result = NULL;
	return (result);
}

/** */
__attribute__((hot)) void	*check(void *arg)
{
	t_philo			*philos;
	const t_data	*data = ((t_data *)arg) + 1;
	register int	nb_finished;
	register int	i;
	t_store			*global;

	global = (t_store *)get_data(run, NULL);
	philos = (t_philo *)arg;
	nb_finished = 0;
	while (nb_finished != data->nb_philo && *global->running != false)
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
				pthread_mutex_lock(global->lock);
				*global->running = false;
				pthread_mutex_unlock(global->lock);
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
	const void		*storage[2] = {philos, &data};

	i = -1;
	while (++i < data.nb_philo)
	{
		if (__builtin_expect(pthread_create(&threads[i], NULL,
				&life, &philos[i]), unexpected))
			return (-1);
	}
	// while (i < data.nb_philo)
	// {
	// 	i += 2;
	// 	if (__builtin_expect(pthread_create(&threads[i], NULL,
	// 			&life, &philos[i]), unexpected))
	// 		return (-1);
	// }
	// usleep(100);
	// i = 0;
	// while (i < data.nb_philo)
	// {
	// 	if (__builtin_expect(pthread_create(&threads[i], NULL,
	// 			&life, &philos[i]), unexpected))
	// 		return (-1);
	// 	i += 2;
	// }
	if (__builtin_expect(pthread_create(&threads[data.nb_philo], NULL,
			&check, storage), unexpected))
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
	t_thread		checker;
	register int	i;
	t_store			store;
	t_bool			running;

	running = true;
	store = (t_store){&running, 
		0,
		0
	};
	get_data(0, &store);
	checker = launch_thread(philosophers, threads, data);
	if (__builtin_expect(checker == (unsigned long)(-1), unexpected))
		return (reaper(philosophers, data.nb_philo), -1);
	pthread_join(checker, NULL);
	i = -1;
	while (++i < data.nb_philo)
	{
		if (__builtin_expect(pthread_join(threads[i], NULL), unexpected))
			return (reaper(philosophers, i), -1);
	}
	return (checker);	//rm cause reaper make a SEGFAULT
	return (reaper(philosophers, data.nb_philo + 1), checker);
}

#pragma endregion "Functions"