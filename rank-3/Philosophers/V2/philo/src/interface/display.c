/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 11:10:26 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/28 10:12:36 by nduvoid          ###   ########.fr       */
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

/** */
__attribute__((always_inline, used)) static inline char	*_get_color(
	const int info
)
{
	if (info == died)
		return (RED);
	else if (info == eating)
		return (GREEN);
	else if (info == sleeping)
		return (CYAN);
	else
		return (WHITE);
	
}

/**
 * @note: all '\n' are important
 */
void	display_philo(
	const t_philo *philo,
	const int info
)
{
	static const char	*status_str[] = {
		[thinking] = "Thinking",
		[sleeping] = "Sleeping",
		[forks] = "Forks",
		[eating] = "Eating",
		[died] = "Dead",
	};
	static t_mutex		print_lock = PTHREAD_MUTEX_INITIALIZER;
	const int			col = 2 + LOG_WIDTH * (philo->id % NB_LOG_COL);
	const int			row = 2 + LOG_HEIGHT * (philo->id / NB_LOG_COL);
	char				*color;

	lock(&print_lock);
	color = _get_color(info);
	move_cursor(row, col);
	printf(" %s+----------------------+\n" RESET, color);
	move_cursor(row + 1, col);
	printf(" %s| Philo: %-3d %9s |\n" RESET, color, philo->id, status_str[philo->status]);
	move_cursor(row + 2, col);
	printf(" %s| Meals: %-13d |\n" RESET, color, philo->nb_meals);
	move_cursor(row + 3, col);
	printf(" %s+----------------------+\n" RESET, color);
	unlock(&print_lock);
}

#pragma endregion Functions