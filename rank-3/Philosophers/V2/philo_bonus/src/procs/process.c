/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 14:48:20 by nduvoid           #+#    #+#             */
/*   Updated: 2025/05/05 16:55:44 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Headers

/* -----| Internal |----- */
// #include "_process.h"

/* -----| Modules  |----- */
#include "process.h"

#pragma endregion Headers
#pragma region Functions

/** */
__attribute__((always_inline, used)) static inline void	kill_process(
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
__attribute__((always_inline, used)) inline pid_t	*launch_process(
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
			return (kill_process(all_pid, i), NULL);
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
	return (all_pid);
}

/** */
__attribute__((always_inline, used)) inline int	launch_simu(
	t_philo *philos,
	const t_args args
)
{
	pid_t	*all_pid;

	philos[0].info(&philos[0], init);
	all_pid = launch_process(philos, args);
	if (__builtin_expect(!all_pid, unexpected))
		return (-1);
	waitpid(-1, NULL, 0);
	kill_process(all_pid, args.data.nb_philo);
	return (0);
}

#pragma endregion Functions