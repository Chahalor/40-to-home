/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 11:10:26 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/28 15:21:57 by nduvoid          ###   ########.fr       */
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
__attribute__((always_inline, used)) inline void	move_cursor(
	const int row,
	const int col
)
{
	printf("\033[%d;%dH", row, col);
}

#if DISPLAY_MODE == 0

/** */
__attribute__((hot)) void	display_philo(
	const t_philo *philo,
	const int info
)
{
	static const char	*status_str[] = {
		[thinking] = "is Thinking", [sleeping] = "is Sleeping", [forks] = "has taken a Forks",
		[eating] = "is Eating", [died] = "just Died"
	};
	static t_time		time_start = 0;
	int					time;
	int					sec;
	int					ms;

	if (__builtin_expect(!philo, unexpected))
	{
		time_start = get_ms_time();
		return ;
	}
	time = get_ms_time() - time_start;
	sec = time / 1000;
	ms = time % 1000;
	printf(CYAN "[" YELLOW "%3d.%03d" CYAN "] " RESET "%-3d %-17s\n",
		sec, ms, philo->id, status_str[info]);
}

#else

/** */
__attribute__((always_inline, used)) static inline char	*_get_color(
	const int info
)
{
	if (info == eating)
		return (GREEN);
	else if (info == sleeping)
		return (CYAN);
	else if (info == thinking)
		return (WHITE);
	else	if (__builtin_expect(info == died, unexpected))
		return (RED);
	else
		return (WHITE);
}

/** */
__attribute__((always_inline, used)) static inline void	_forks_status(
	const int status
)
{
	static const char	*status_str[] = {"🟥", "🟩"};

	(void)status;
	// if (status < forks)
	// 	return ;
	printf("   %s   %s |\n" RESET, status_str[0], status_str[1]);
}

/** */
__attribute__((hot)) void	display_philo(
	const t_philo *philo,
	const int info
)
{
	static const char	*status_str[] = {
		[thinking] = "Thinking", [sleeping] = "Sleepi+ng", [forks] = "Forks",
		[eating] = "Eating", [died] = "Dead"
	};
	static t_mutex		print_lock = PTHREAD_MUTEX_INITIALIZER;
	// static t_bool		a_dead_one = false;
	const int			col = 2 + LOG_WIDTH * (philo->id % NB_LOG_COL);
	const int			row = 2 + LOG_HEIGHT * (philo->id / NB_LOG_COL);
	const char			*color = _get_color(info);

	// if (__builtin_expect(a_dead_one, unexpected))
	// 	return ;
	// else if (__builtin_expect(info == died, unexpected))
	// 	a_dead_one = true;
	// return ;
	lock(&print_lock);
	move_cursor(row, col);
	printf(" %s+----------------------+\n" RESET, color);
	move_cursor(row + 1, col);
	printf(" %s| Philo: %-3d %9s |\n" RESET, color, philo->id,
		status_str[philo->status]);
	move_cursor(row + 2, col);
	printf(" %s| Meals: %-3d   %s   %s |\n" RESET, color, philo->nb_meals, "🟥", "🟩");
	move_cursor(row + 3, col);
	printf(" %s+----------------------+\n" RESET, color);
	info2(philo->id, status_str[philo->status]);
	unlock(&print_lock);
}

#endif	// DISPLAY_MODE

#pragma endregion Functions