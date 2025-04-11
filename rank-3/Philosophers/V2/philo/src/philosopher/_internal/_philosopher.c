/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _philosopher.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 14:56:49 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/11 14:57:05 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region "Headers"

/* --- Global --- */
# include "config.h"
# include "type.h"

/* --- Intern --- */
#include "_philosopher.h"
#include "philosopher.h"

#pragma endregion "Headers"
#pragma region "Functions"

/** */
__attribute__((used, always_inline)) inline t_philo	*init_mutex(
	t_philo *philosophers,
	const t_data data
)
{
	register int	i;

	i = -1;
	while (++i < data.nb_philo)
	{
		if (__builtin_expect(pthread_mutex_init(philosophers[i].lock, NULL)
			|| pthread_mutex_init(philosophers[i].left_fork, NULL)
			|| pthread_mutex_init(philosophers[i].right_fork, NULL),
			unexpected))
			return (reaper(philosophers, i), NULL);
	}
	return (philosophers);
}

#pragma endregion "Functions"