/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _check.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 13:29:16 by nduvoid           #+#    #+#             */
/*   Updated: 2025/05/06 16:04:55 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Headers

/* -----| Internal |----- */
#include "_process.h"

/* -----| Modules  |----- */
#include "process.h"

#pragma endregion Headers
#pragma region Functions


/** */
__attribute__((always_inline, used)) inline int	_look_for_death(
	t_philo *philo
)
{
	register int	i;
	register int	result;

	if (__builtin_expect(!philo, unexpected))
		return (-1);
	result = 0;
	i = -1;
	while (++i < philo->data.nb_philo - 1)
		result += philo[i].status == died;
	return (result);
}

/** */
__attribute__((cold)) void	*_check_meals(
	void *arg
)
{
	const t_check	*check = (t_check *)arg;
	register int	i;

	if (__builtin_expect(!check, unexpected))
		return (NULL);
	i = -1;
	while (++i < check->nb_philo)
		swait(check->finished);
	post(check->run);
	printf("All philosophers finished (%d)\n", i);	// rm
	return (NULL);
}

#pragma endregion Functions