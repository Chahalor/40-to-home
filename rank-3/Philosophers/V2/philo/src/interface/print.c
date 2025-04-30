/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 20:25:18 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/30 16:37:55 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Headers

/* -----| Internal |----- */
#include "_interface.h"

/* -----| Modules  |----- */
#include "interface.h"

#pragma endregion Headers
#pragma region Functions

/**
 * @brief	Add a log to the info struct.
 * 
 * @param	info Pointer to the info struct.
 * @param	id   The id of the philosopher.
 * @param	msg  The message to log.
 * 
 * @return	None
*/
__attribute__((always_inline, used)) static inline void	_add_to_log(
	t_info *info,
	const int id,
	const char *msg
)
{
	const t_time	current = get_ms_time();
	const int		index = (info->start + info->nb_logs) % MAX_LOGS;

	info->logs[index].msg = msg;
	info->logs[index].sec = (current - info->time_start) / 1000;
	info->logs[index].ms = (current - info->time_start) % 1000;
	info->logs[index].id = id;
	if (__builtin_expect(info->nb_logs < MAX_LOGS, expected))
		++info->nb_logs;
	else
		info->start = (info->start + 1) % MAX_LOGS;
}

// __attribute__((always_inline, used)) static inline void	_add_to_log(
// 	t_info *info,
// 	const int id,
// 	const char *msg
// )
// {
// 	register int	i;
// 	const t_time	current = get_ms_time();

// 	if (__builtin_expect(!msg, unexpected))
// 		return ;
// 	else if (__builtin_expect(info->nb_logs >= MAX_LOGS, expected))
// 	{
// 		i = 0;
// 		while (++i < info->nb_logs)
// 			info->logs[i - 1] = info->logs[i];
// 		--info->nb_logs;
// 	}
// 	info->logs[info->nb_logs].msg = msg;
// 	info->logs[info->nb_logs].sec = (current - info->time_start) / 1000;
// 	info->logs[info->nb_logs].ms = (current - info->time_start) % 1000;
// 	info->logs[info->nb_logs].id = id;
// 	++info->nb_logs;
// }

/** */
__attribute__((hot)) void	info2(
	const int id,
	const char *msg
)
{
	static t_info	info = {0};
	register int	i;
	register int	index;

	if (__builtin_expect(id == -1, unexpected))
	{
		info.time_start = get_ms_time();
		return ;
	}
	else if (__builtin_expect(!msg, unexpected))
		return ;
	_add_to_log(&info, id, msg);
	move_cursor(16 * LOG_HEIGHT + 4, 1);
	i = -1;
	while (++i < info.nb_logs)
	{
		index = (info.start + i) % MAX_LOGS;
		printf(CYAN "[" YELLOW "%3d.%03d" CYAN "] " RESET "%-3d %-17s\n",
			info.logs[index].sec,
			info.logs[index].ms,
			info.logs[index].id,
			info.logs[index].msg);
	}
}

#pragma endregion Functions