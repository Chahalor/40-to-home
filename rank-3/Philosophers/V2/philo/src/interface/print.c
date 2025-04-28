/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 20:25:18 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/28 10:09:51 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Headers

/* -----| Internal |----- */
// #include "_interface.h"

/* -----| Modules  |----- */
#include "interface.h"

#pragma endregion Headers
#pragma region Functions

/** */
__attribute__((always_inline, used)) static inline void	_add_to_log(
	t_info *info,
	const int id,
	const char *msg
)
{
	register int	i;
	const t_time	current = get_ms_time();

	if (__builtin_expect(!msg, unexpected))
		return ;
	else if (__builtin_expect(info->nb_logs >= MAX_LOGS, expected))
	{
		i = 0;
		while (++i < info->nb_logs)
			info->logs[i - 1] = info->logs[i];
		info->nb_logs--;
	}
	info->logs[info->nb_logs].msg = msg;
	info->logs[info->nb_logs].sec = (current - info->time_start) / 1000;
	info->logs[info->nb_logs].ms = (current - info->time_start) % 1000;
	info->logs[info->nb_logs].id = id;
	++info->nb_logs;
}

/** */
__attribute__((hot)) void	info2(
	const int id,
	const char *msg
)
{
	static t_info	info = {0};
	register int	i;

	if (__builtin_expect(!msg, unexpected))
		return ;
	else if (__builtin_expect(id == -1, unexpected))
	{
		info.time_start = get_ms_time();
		pthread_mutex_init(&info.print_lock, NULL);
	}
	lock(&info.print_lock);
	_add_to_log(&info, id, msg);
	i = -1;
	while (++i < info.nb_logs)
		printf(CYAN "[" YELLOW "%3d.%03d" CYAN "] " RESET "%-3d %-17s\n",
			info.logs[i].sec, info.logs[i].ms, info.logs[i].id, info.logs[i].msg);
	printf("========================================================================\n");
	unlock(&info.print_lock);
}

/** */
__attribute__((hot)) void	info(
	const int id,
	const char *msg
)
{
	static t_time	time_start = 0;
	static t_mutex	print_lock = PTHREAD_MUTEX_INITIALIZER;
	int				time;
	int				sec;
	int				ms;

	// return ;
	info2(id, msg);
	if (__builtin_expect(!msg, unexpected))
		return ;
	else if (__builtin_expect(id == -1, unexpected))
	{
		time_start = get_ms_time();
		pthread_mutex_init(&print_lock, NULL);
	}
	lock(&print_lock);
	time = get_ms_time();
	sec = (time - time_start) / 1000;
	ms = (time - time_start) % 1000;
	printf(CYAN "[" YELLOW "%3d.%03d" CYAN "] " RESET "%-3d %-17s\n",
		sec, ms, id, msg);
	unlock(&print_lock);
}

#pragma endregion Functions