/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 13:55:35 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/08 16:11:39 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region "Headers"
// System
#include <errno.h>

// Global
#include "type.h"

// Modules
#include "parsing.h"
#include "philosopher/philosopher.h"	// rm the direct path, vs code is making an inexisting error
#include "debug.h"
#include "formating.h"

#pragma endregion "Headers"
#pragma region "Functions"

/** */
__attribute__((always_inline, used)) static inline void	destructor(
	t_global *global
)
{
	if (__builtin_expect(global->philos, expected))
		terminator(global->philos, global->data.nb_philo);
	pthread_mutex_destroy(&global->print_lock);
}

/** */
int	main(int argc, const char *argv[])
{
	const t_args	args = parse_args(argc, argv);
	t_global		global;
	t_philo			**philos;

	if (args.error || args.help)
		return (args.error);
	print_args(&args);
	print_debug("|----------------------------------|");	//rm
	global.philos = build_philos(args.data);
	if (!global.philos)
	{
		ft_error("Failed to build philosophers");
		printf(PADD "failed to build philosophers\n");
		return (ENOMEM);
	}
	else if (__builtin_exptect(pthread_mutex_init(&global.print_lock, NULL),
		unexpected))
		return (ft_error("Failed to init mutex"), ENOMEM);
	else if (__builtin_exptect(pthread_mutex_init(&global.data_lock, NULL),
		unexpected))
		return (ft_error("Failed to init mutex"), ENOMEM);
	global.data = args.data;
	int i = -1;
	while (++i < global.data.nb_philo)	// debug
		print_philo(global.philos[i]);
	// while (???)
	// {
	// 	// philosophers day i suppose
	// }
	destructor(&global);
	return (0);
}

#pragma endregion "Functions"