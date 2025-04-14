/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 13:55:35 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/14 11:33:28 by nduvoid          ###   ########.fr       */
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
	if (__builtin_expect(global->philos != NULL, expected))
		terminator(global->philos, global->data.nb_philo);
	pthread_mutex_destroy(&global->print_lock);
	pthread_mutex_destroy(&global->data_lock);
}

__attribute__((always_inline, used)) static inline int	init_main(
	t_global *global,
	t_thread *thread,
	const t_philo_data *data
)
{
	if (__builtin_expect(!global || !thread || !data, unexpected))
		return (1);
	global->data = *data;
	global->philos = build_philos(global->data);
	if (__builtin_expect(!global->philos, unexpected))
		return (2);
	else if (__builtin_expect(pthread_mutex_init(&global->print_lock, NULL)
		|| pthread_mutex_init(&global->data_lock, NULL), unexpected))
		return (3);
	*thread = 0;
	global->data.running = true;
	return (0);
}

/** */
int	main(int argc, const char *argv[])
{
	const t_args	args = parse_args(argc, argv);
	t_global		global;
	t_thread		main_tread;

	if (args.error || args.help != false)
		return (args.error);
	if (__builtin_expect(init_main(&global, &main_tread, &args.data), unexpected))
	{
		destructor(&global);
		ft_error("Failed to init main");
		printf(PADD "failed to init main\n");
		return (ENOMEM);
	}
	// print_debug("Main successfully initialized");	//rm
	hive_mind(&global, &main_tread);
	pthread_join(main_tread, NULL);
	destructor(&global);
	return (0);
}

#pragma endregion "Functions"