/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _launch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 14:36:21 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/14 17:10:32 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region "Headers"
// System
	// ...

// Global
#include "type.h"
#include "config.h"

// Modules
#include "_philosopher.h"
#include "philosopher.h"
#include "debug.h"

#pragma endregion "Headers"
#pragma region "Functions"

/** */
__attribute__((used, always_inline)) inline int	launch_thread(
	t_global *global,
	t_thread *main
)
{
	register int	i;
	t_mind			*mind;

	i = -1;	// this one works
	while (++i < global->data.nb_philo)
	{
		mind = (t_mind *)malloc(sizeof(t_mind));	// add this to the big alloc
		*mind = (t_mind){
			.philo = global->philos[i],
			.sleep_time = global->data.time_to_sleep
		};
		if (__builtin_expect(pthread_create(&global->philos[i]->thread, NULL,
				&single_mind, mind), unexpected))
			return (-1);
	}
	if (__builtin_expect(pthread_create(main, NULL, &check_death,
		global), unexpected))
		return (-1);
	return (0);
}

#pragma endregion "Functions"