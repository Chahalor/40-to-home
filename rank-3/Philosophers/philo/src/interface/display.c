/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 11:10:26 by nduvoid           #+#    #+#             */
/*   Updated: 2025/06/18 14:10:32 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Headers

/* -----| Internal |----- */
#include "_interface.h"
#include "philosophers.h"

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
 * @brief	Initialize the raw data structure for logging.
 * 
 * @param	Void
 * 
 * @return	Initialized raw data structure.
 */
__attribute__((always_inline, used)) static inline t_raw_data	_init_raw_data(
)
{
	return ((t_raw_data){
		.status_str = {
			[thinking] = "is thinking", [sleeping] = "is sleeping", \
			[forks] = "has taken a fork", [eating] = "is eating", \
			[died] = RED "died" RESET
		},
		.format = {
			CYAN "[" YELLOW "%3d.%03d" CYAN "] " RESET "%-3d %-11s %s\n", \
			CYAN "[" YELLOW "%3d.%03d" CYAN "] " RESET "%-3d %-17s\n", \
			CYAN "[" YELLOW "%3d.%03d" CYAN "] " RESET "%-3d %-17s (%d)\n" \
		},
		.print_lock = PTHREAD_MUTEX_INITIALIZER,
		.print = true,
		.start_time = get_ms_time(),
	});
}

/**
 * @brief	Raw log function to display the philosopher's status.
 * 
 * @param	philo Pointer to the philosopher.
 * @param	info  The status of the philosopher.
 * 
 * @return	Void
 * 
 * @note	- Use ANSI escape codes to format the output.
 * @note	- This function should be initialized before any use.
*/
__attribute__((hot)) void	raw_log(
	const t_philo *philo,
	const int info
)
{
	static t_raw_data	data = {0};
	int					time;
	int					sec;
	int					ms;

	if (__builtin_expect(info == init, unexpected))
	{
		data = _init_raw_data();
		return ;
	}
	lock(&data.print_lock);
	if (__builtin_expect(data.print != true, unexpected))
		return ((void)(unlock(&data.print_lock)));
	data.print = (data.print != false && info != died);
	time = get_ms_time() - data.start_time;
	sec = time / 1000;
	ms = time % 1000;
	if (_UNLIKELY(info == thinking))
		printf(data.format[info],
			sec, ms, philo->id, data.status_str[info], get_random_thougth());
	else
		printf(data.format[(info == eating) + 1],
			sec, ms, philo->id, data.status_str[info], philo->nb_meals);
	unlock(&data.print_lock);
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
	const t_philo *philo,
	const int info
)
{
	static const char	*status_str[] = {
	[thinking] = "Thinking", [sleeping] = "Sleeping", [forks] = "Forks",
	[eating] = "Eating", [died] = "Dead"};
	static t_mutex		print_lock = PTHREAD_MUTEX_INITIALIZER;
	const int			col = 2 + LOG_WIDTH * (philo->id % NB_LOG_COL);
	const int			row = 2 + LOG_HEIGHT * (philo->id / NB_LOG_COL);
	const char			*color = _get_color(info);

	lock(&print_lock);
	if (info < init)
	{
		printf("\033[%d;%dH %s+----------------------+\n"
			"\033[%d;%dH %s| Philo: %-3d %9s |\n"
			"\033[%d;%dH %s| Meals: %s%-14d%s|\n"
			"\033[%d;%dH %s+----------------------+\n" RESET,
			row, col, color,
			row + 1, col, color, philo->id, status_str[philo->status],
			row + 2, col, color, YELLOW, philo->nb_meals, color,
			row + 3, col, color
			);
	}
	unlock(&print_lock);
}

#pragma endregion Functions