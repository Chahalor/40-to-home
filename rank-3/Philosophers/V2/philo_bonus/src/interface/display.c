/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 11:10:26 by nduvoid           #+#    #+#             */
/*   Updated: 2025/05/06 16:00:38 by nduvoid          ###   ########.fr       */
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
 * @brief	Move the cursor to the specified position.
 * 
 * @param	row The row to move the cursor to.
 * @param	col The column to move the cursor to.
 * 
 * @return	None
 * 
 * @note	Use ANSI escape codes to move the cursor.
*/
__attribute__((always_inline, used)) inline void	move_cursor(
	const int row,
	const int col
)
{
	printf("\033[%d;%dH", row, col);
}

/**
 * @brief	Raw log function to display the philosopher's status.
 * 
 * @param	philo Pointer to the philosopher.
 * @param	info  The status of the philosopher.
 * 
 * @return	None
*/
__attribute__((hot)) void	raw_log(
	const void *ptr,
	const int info
)
{
	static t_raw_data	data = {.status_str = { \
			[thinking] = "is Thinking", [sleeping] = "is Sleeping", \
			[forks] = "has taken a Forks", [eating] = "is Eating", \
			[died] = "just " RED "Died" RESET},
		.format = {CYAN "[" YELLOW "%3d.%03d" CYAN "] " RESET "%-3d %-17s\n", \
			CYAN "[" YELLOW "%3d.%03d" CYAN "] " RESET "%-3d %-17s (%d)\n"},
		.start_time = 0, .print_lock = NULL};
	int					time;
	int					sec;
	int					ms;

	if (__builtin_expect(info == init, unexpected))
		return (data.start_time = get_ms_time(),
			(void)(data.print_lock = (sem_t *)ptr));
	swait(data.print_lock);
	time = get_ms_time() - data.start_time;
	sec = time / 1000;
	ms = time % 1000;
	swait(((t_philo *)ptr)->lock);
	printf(data.format[info == eating],
		sec, ms, ((t_philo *)ptr)->id, data.status_str[info], ((t_philo *)ptr)->nb_meals);
	post(((t_philo *)ptr)->lock);
	if (__builtin_expect(info != died, expected))
		post(data.print_lock);
}

/**
 * @brief	Get the color for the philosopher's status.
 * 
 * @param	info The status of the philosopher.
 * 
 * @return	The color for the philosopher's status.
 */
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
	else if (__builtin_expect(info == died, unexpected))
		return (RED);
	else
		return (WHITE);
}

/**
 * @brief	Display the philosopher's status in a formatted way.
 * 
 * @param	philo Pointer to the philosopher.
 * @param	info  The status of the philosopher.
 * 
 * @return	None
*/
__attribute__((hot)) void	display_philo(
	const void *data,
	const int info
)
{
	static const char	*status_str[] = {
	[thinking] = "Thinking", [sleeping] = "Sleeping", [forks] = "Forks",
	[eating] = "Eating", [died] = "Dead"};
	const t_philo		*philo = (const t_philo *)data;
	const int			col = 2 + LOG_WIDTH * (philo->id % NB_LOG_COL);
	const int			row = 2 + LOG_HEIGHT * (philo->id / NB_LOG_COL);
	const char			*color = _get_color(info);

	if (__builtin_expect(info < init, expected))
	{
		printf("\033[%d;%dH %s+----------------------+\n"
			"\033[%d;%dH %s| Philo: %-3d %9s |\n"
			"\033[%d;%dH %s| Meals: %s%-3d%s           |\n"
			"\033[%d;%dH %s+----------------------+\n" RESET,
			row, col, color,
			row + 1, col, color, philo->id, status_str[philo->status],
			row + 2, col, color, YELLOW, philo->nb_meals, color,
			row + 3, col, color
			);
	}
}

#pragma endregion Functions