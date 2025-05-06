/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shortcut.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 13:17:24 by nduvoid           #+#    #+#             */
/*   Updated: 2025/05/06 08:46:50 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Headers

/* -----| Internal |----- */
	//...

/* -----| Modules  |----- */
#include "utils.h"

#pragma endregion Headers
#pragma region Functions

/** */
__attribute__((always_inline, used)) inline int	swait(
	sem_t *sem
)
{
	if (__builtin_expect(!sem, unexpected))
		return (-1);
	else
		return (sem_wait(sem));
}

/** */
__attribute__((always_inline, used)) inline int	post(
	sem_t *sem
)
{
	if (__builtin_expect(!sem, unexpected))
		return (-1);
	else
		return (sem_post(sem));
}

/** */
__attribute__((always_inline, used)) inline int	launch(
	t_thread *thread,
	void *(*start_routine)(void *),
	void *arg
)
{
	return (pthread_create(thread, NULL, start_routine, arg));
}

/** */
__attribute__((always_inline, used)) inline int	join(
	t_thread *thread
)
{
	return (pthread_join(*thread, NULL));
}

#pragma endregion Functions