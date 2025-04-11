/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 13:55:35 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/11 15:32:20 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region "Headers"
// System
#include <errno.h>

// Global
#include "type.h"

// Modules
#include "parsing.h"
#include "thread.h"
#include "philosopher.h"
#include "debug.h"
#include "formating.h"

#pragma endregion "Headers"
#pragma region "Functions"

/** */
int	main(int argc, const char *argv[])
{
	const t_args	args = parse_args(argc, argv);
	t_thread		*threads;
	t_philo			*philosophers;

	if (__builtin_expect(args.error || args.help != false, unexpected))
		return (args.error);
	threads = (t_thread *)malloc(sizeof(t_thread) * (args.data.nb_philo + 2));
	philosophers = build_philos(args.data);
	if (!threads || !philosophers)
	{
		free(threads);
		free(philosophers);
		printf(RED ERROR RESET "malloc failed\n" PADD "threads/philo alloc\n");
		return (ENOMEM);
	}
	return (start_simulation(philosophers, threads, args.data));
}

#pragma endregion "Functions"