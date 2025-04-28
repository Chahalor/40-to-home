/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 10:12:18 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/28 15:21:37 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Headers

/* -----| Internal |----- */
// #include "_interface.h"

/* -----| Modules  |----- */
#include "interface.h"

#pragma endregion Headers
#pragma region Functions

#if DISPLAY_MODE == 1

/** */
__attribute__((always_inline, used)) static inline void	_init_info(
	const t_philo_data data
)
{
	printf(CURSOR_DOWN CURSOR_DOWN);
	printf("\
╔═══════════════════════════════════════════════════════════\
═════════════════════════════════╗\n\
║ Number of philos:	%-3d		 ║		\
Numbers of philos alive:	%-3d  ║\n\
║ Time to die:		%-5d		 ║		\
Numbers of philos eating:	0    ║\n\
║ Time to Eat:		%-5d		 ║		\
Numbers of philos sleeping:	0    ║\n\
║ Time to Sleep:	%-5d		 ║		\
Numbers of philos thinking:	0    ║\n\
║ Number of Meals:	%-5d		 ║		\
Numbers of philos dead:		0    ║\n\
╚═══════════════════════════════════════════════════════════\
═════════════════════════════════╝\n",
		data.nb_philo,
		data.nb_philo,
		data.time_to_die,
		data.time_to_eat,
		data.time_to_sleep,
		data.nb_meals);
}

/** */
__attribute__((always_inline, used)) static inline void	_init_log(void)
{
	register int	i;

	move_cursor(999, 1);
	printf("╚══════════════════════════════════════════════════════════════════\
══════════════════════════╝\n" CURSOR_UP);
	i = -1;
	while (++i < NB_LOG_COL)
		printf(CURSOR_UP "║                                                    \
                                        ║\n" CURSOR_UP);
	printf("╔══════════════════════════════════════════════════════════════════\
══════════════════════════╗\n");
}

/** */
__attribute__((always_inline, used)) inline void	init_display(
	const t_philo_data data
)
{
	printf(HEADER CLEAR_SCREEN);
	info2(-1, "beginning");
	(void)data;
	// _init_info(data);
	// _init_log();
}

#else

/** */
__attribute__((always_inline, used)) inline void	init_display(
	const t_philo_data data
)
{
	(void)data;
	printf(HEADER);
	display_philo(NULL, 0);
}

#endif

#pragma endregion Functions