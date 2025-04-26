/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 14:58:38 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/26 20:24:17 by nduvoid          ###   ########.fr       */
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
	const char *msg
)
{
	static t_time	time_start = 0;
	static t_mutex	print_lock = PTHREAD_MUTEX_INITIALIZER;
	int				time;
	int				sec;
	int				ms;

	(void)time;
	if (__builtin_expect(!msg, unexpected))
		return ;
	else if (__builtin_expect(id == -1, unexpected))
	{
		time_start = get_ms_time();
		pthread_mutex_init(&print_lock, NULL);
	}
	// if (global_manager(request_get_run) == false)
	// {
	// 	pthread_mutex_destroy(&print_lock);
	// 	return ;
	// }
	lock(&print_lock);
	time = get_ms_time();
	sec = (time - time_start) / 1000;
	ms = (time - time_start) % 1000;
	printf(CYAN "[" YELLOW "%3d.%03d" CYAN "] " RESET "%-3d %s\n",
		sec, ms, id, msg);
	unlock(&print_lock);
}

/** */
static inline t_bool _should_quit(
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
	int state = global_manager(request_get_run);
	while (state == true)
	{
		printf("philo %d: state=%d\n", philo->id, state);
		if (_should_quit(philo))
			break ;
		if (philo->status == eating)
			philo->eat(philo);
		else if (philo->status == sleeping)
			philo->sleep(philo);
		else if (philo->status == thinking)
			philo->think(philo);
		state = global_manager(request_get_run);
	}
	return (NULL);
}

#pragma endregion Functions