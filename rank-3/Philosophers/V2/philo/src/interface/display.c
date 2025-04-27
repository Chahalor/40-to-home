/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 11:10:26 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/27 20:54:37 by nduvoid          ###   ########.fr       */
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

/**
 * @note: all '\n' are important
 */
void	display_philo(
	const t_philo *philo
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
	const int			row = LOG_HEIGHT * (philo->id / NB_LOG_COL);

	lock(&print_lock);
	move_cursor(row, col);
	printf(" +----------------------+\n");
	move_cursor(row + 1, col);
	printf(" | Philo: %-3d %9s |\n", philo->id, status_str[philo->status]);
	move_cursor(row + 2, col);
	printf(" | Meals: %-13d |\n", philo->nb_meals);
	move_cursor(row + 3, col);
	printf(" +----------------------+\n");
	unlock(&print_lock);
}

#pragma endregion Functions