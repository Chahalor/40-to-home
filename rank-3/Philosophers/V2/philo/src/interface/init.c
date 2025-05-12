/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 10:12:18 by nduvoid           #+#    #+#             */
/*   Updated: 2025/05/12 17:28:50 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Headers

/* -----| Internal |----- */
#include "_interface.h"

/* -----| Modules  |----- */
#include "interface.h"

#pragma endregion Headers
#pragma region Functions

/** */
__attribute__((always_inline, used)) inline void	init_display(
	const t_philo_data data,
	const t_philo *restrict random_one,
	const int display
)
{
	(void)data;
	if (display == 1)
	{
		printf(HEADER CLEAR_SCREEN);
		random_one->info(random_one, init);
		move_cursor(999, 1);
	}
	else
	{
		printf(HEADER);
		random_one->info(random_one, init);
	}
}

#pragma endregion Functions