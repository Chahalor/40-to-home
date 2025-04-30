/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 10:28:50 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/30 13:59:58 by nduvoid          ###   ########.fr       */
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

/** */
__attribute__((always_inline, used)) static inline void	_end_of_main(
	const t_args args,
	const int status
)
{
	if (args.display)
		move_cursor(2 + (args.data.nb_philo + 1) * 4, 1);
	if (status == 1)
		printf("A philosopher " RED "died" RESET " (RIP bozo)\n");
	else if (__builtin_expect(status == -1, unexpected))
		printf(RED ERROR RESET "Failed to launch the simulation\n");
	else if (__builtin_expect(!args.data.nb_meals, unexpected))
		printf("you know what they say, " YELLOW "no meal no life" RESET "\n");
	else
		printf("All philosophers finished alive (nice)\n");
}

/** */
int	main(int argc, const char **argv)
{
	const t_args	args = parse_args(argc, argv);
	t_mutex			*forks;
	t_philo			*philosophers;
	int				simu_status;

	if (__builtin_expect(args.error || args.help, unexpected))
		return (1 + args.help);
	init_all(&forks, &philosophers, args.data, args.display);
	simu_status = launch_simu(philosophers, args.data, args.display);
	_end_of_main(args, simu_status);
	destroy_mutex(&forks, args.data.nb_philo * 3);
	destroy_philos(&philosophers);
	return (0);
}

#pragma endregion Functions