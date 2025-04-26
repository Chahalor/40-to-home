/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shortcut.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 13:17:24 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/26 12:29:38 by nduvoid          ###   ########.fr       */
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
__attribute__((always_inline, used)) inline int	lock(
	t_mutex *mutex
)
{
	return (pthread_mutex_lock(mutex));
}

/** */
__attribute__((always_inline, used)) inline int	unlock(
	t_mutex *mutex
)
{
	return (pthread_mutex_unlock(mutex));
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

/** */
__attribute__((always_inline, used)) inline int	destroy(
	t_mutex *mutex
)
{
	return (pthread_mutex_destroy(mutex));
}

#pragma endregion Functions