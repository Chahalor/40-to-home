/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 10:28:50 by nduvoid           #+#    #+#             */
/*   Updated: 2025/05/09 10:31:06 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Headers

/* -----| Internal |----- */
	//...

/* -----| Modules  |----- */
#include "parsing.h"
#include "process.h"
#include "semaphores.h"
#include "interface.h"
#include "utils.h"
#include "debug.h"

#pragma endregion Headers
#pragma region Functions

/**
 * @brief			print the end of the simulation
 * 
 * @param args		The programm arguments
 * @param status	The simulation status
 * 
 * @returns			void
 * 
 * @details	-1 if the simulation failed to launch
 * 			+0 if the simulation finished without meals
 * 			+1 if a philosopher died
 */
__attribute__((always_inline, used)) static inline void	_end_of_main(
	const t_args args,
	const int status
)
{
	if (args.display)
		move_cursor(2 + (args.data.nb_philo + 1) * 4, 1);
	if (__builtin_expect(status == -1, unexpected))
		printf(RED ERROR RESET "Failed to launch the simulation\n");
	else if (__builtin_expect(!args.data.nb_meals, unexpected))
		printf("you know what they say, " YELLOW "no meal no life" RESET "\n");
}

/**
 * @author	nduvoid <nduvoid@student.42mulhouse.fr>
 * @date	2025/04/23
 * @name	Philo_bonus
 * 
 * @file	main.c
 * @dir		src
 * 
 * @brief This Program is a simulation of the dining philosophers problem.
 * 
 * - The simulation is done using semaphores and processes.
 * 
 * - This program is a bonus project for the 42 school.
 * 
 * @param	argc		The number of arguments
 * @param	argv		The arguments
 * 
 * @return	0 if the simulation finished without errors
 * @return	-1 if the simulation failed to launch
 * @return	-2 if the simulation failed to parse the arguments
 * @return	-3 if the simulation failed to initialize
 */
int	main(int argc, const char **argv)
{
	const t_args	args = parse_args(argc, argv);
	t_semaphores	semaphores;
	t_philo			*philosophers;
	int				simu_status;

	if (__builtin_expect(args.error || args.help, unexpected))
		return (-(1 + args.help));
	if (__builtin_expect(init_all(&semaphores, &philosophers, args) == -1,
			unexpected))
		return (-3);
	simu_status = launch_simu(philosophers, args, &semaphores);
	_end_of_main(args, simu_status);
	destroy_philos(&philosophers);
	close_semaphores(&semaphores);
	return (0);
}

#pragma endregion Functions