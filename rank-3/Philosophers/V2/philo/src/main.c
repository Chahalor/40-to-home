/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 10:28:50 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/28 15:20:24 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Headers

/* -----| Internal |----- */
	//...

/* -----| Modules  |----- */
#include "parsing.h"
#include "threads.h"
#include "utils.h"
#include "debug.h"

#pragma endregion Headers
#pragma region Functions

int	main(int argc, const char **argv)
{
	const t_args	args = parse_args(argc, argv);
	t_mutex			*forks;
	t_philo			*philosophers;

	if (__builtin_expect(args.error || args.help, unexpected))
		return (1);
	init_all(&forks, &philosophers, args.data);
	launch_simu(philosophers, args.data);
	// move_cursor(2 + (args.data.nb_philo + 1) * 4, 1);
	// printf("Simulation finished\n");
	destroy_mutex(&forks, args.data.nb_philo * 3);
	destroy_philos(&philosophers);
	return (0);
}

#pragma endregion Functions