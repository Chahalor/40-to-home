/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 10:12:18 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/28 10:28:49 by nduvoid          ###   ########.fr       */
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
__attribute__((always_inline, used)) static inline void	_init_info(
	t_info *info
)
{
	printf("╔══════════════════════════════════════════════════════════════════\
		══════════════════════════╗\n");

	printf("║║║");


	printf("╚══════════════════════════════════════════════════════════════════\
		══════════════════════════╝\n");
}

__attribute__((always_inline, used)) static inline void	_init_philo_display(
	register const int nb_philo
)
{
	register int i;

	i = -1;
	while (++i < nb_philo)
		display_philo(i, thinking);
}

__attribute__((always_inline, used)) static inline void	_init_log(
	
)
{
	register int i;

	move_cursor(999, 1);
	printf("╚══════════════════════════════════════════════════════════════════\
		══════════════════════════╝\n");
	i = -1;
	while (++i < NB_LOG_COL)
	{
		printf(CURSOR_UP);
		printf("║");
	}
	printf("╔══════════════════════════════════════════════════════════════════\
		══════════════════════════╗\n");
}

/** */
__attribute__((always_inline, used)) inline void	init_display(
	void
)
{
	move_cursor(0, 0);
	printf("\033[2J");
	move_cursor(0, 0);
}

#pragma endregion Functions