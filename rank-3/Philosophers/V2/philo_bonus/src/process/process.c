/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 14:48:20 by nduvoid           #+#    #+#             */
/*   Updated: 2025/05/06 16:06:28 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Headers

/* -----| Internal |----- */
#include "_process.h"

/* -----| Modules  |----- */
#include "process.h"

#pragma endregion Headers
#pragma region Functions

/** */
__attribute__((always_inline, used)) static inline void	_kill_process(
	pid_t *restrict all_pid,
	register const int nb_process
)
{
	register int	i;

	if (__builtin_expect(!all_pid, unexpected))
		return ;
	i = -1;
	while (++i < nb_process)
	{
		if (__builtin_expect(all_pid[i] != -1, unexpected))
			kill(all_pid[i], SIGKILL);
	}
	free(all_pid);
}

/** */
__attribute__((always_inline, used))static inline pid_t	*_launch_process(
	t_philo *philos,
	const t_args args
)
{
	pid_t			*all_pid;
	register int	i;
	int				pid;

	all_pid = NULL;
	i = -1;
	while (++i < args.data.nb_philo)
	{
		pid = fork();
		if (__builtin_expect(pid == -1, unexpected))
			return (_kill_process(all_pid, i), NULL);
		else if (pid == 0)
			exit(circle_of_life(&philos[i]));
		else
		{
			if (__builtin_expect(!all_pid, unexpected))
				all_pid = (pid_t *)malloc(sizeof(pid_t) * args.data.nb_philo);
			if (__builtin_expect(!all_pid, unexpected))
				return (kill(pid, SIGKILL), NULL);
			all_pid[i] = pid;
		}
	}
	return (all_pid);	// maybe multi threading this (overkill max)
}

/** */
__attribute__((always_inline, used)) inline int	launch_simu(
	t_philo *philos,
	const t_args args,
	const t_semaphores *semaphores
)
{
	pid_t			*all_pid;
	t_thread		check_meal;
	int				result;
	register int	i;
	t_check			var;
	
	var = (t_check){ \
		.finished = semaphores->nb_finished,
		.run = semaphores->run,
		.nb_philo = args.data.nb_philo};
	philos[0].info(semaphores->print, init);
	pthread_create(&check_meal, NULL, _check_meals, &(var));
	all_pid = _launch_process(philos, args);
	if (__builtin_expect(!all_pid, unexpected))
		return (-1);
	swait(semaphores->run);
	i = -1;
	while (++i < args.data.nb_philo)
		post(semaphores->nb_finished);
	pthread_join(check_meal, NULL);
	result = _look_for_death(philos);
	_kill_process(all_pid, args.data.nb_philo);
	return (result);
}

#pragma endregion Functions