/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 14:48:20 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/30 14:55:04 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Headers

/* -----| Internal |----- */
// #include "_process.h"

/* -----| Modules  |----- */
#include "process.h"

#pragma endregion Headers
#pragma region Functions

/** */
__attribute__((always_inline, used)) inline int	launch_simu(
	t_philo *philos,
	const t_args args
)
{
	philos[0].info(&philos[0], init);
	if (__builtin_expect(launch_process(philos, args), unexpected))
		return (-1);
}

#pragma endregion Functions