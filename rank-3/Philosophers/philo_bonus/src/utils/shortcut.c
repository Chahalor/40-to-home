/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shortcut.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 13:17:24 by nduvoid           #+#    #+#             */
/*   Updated: 2025/05/07 12:31:09 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Headers

/* -----| Internal |----- */
	//...

/* -----| Modules  |----- */
#include "utils.h"

#pragma endregion Headers
#pragma region Functions

/**
 * @brief	wait for the semaphore
 * 
 * @param sem The semaphore to wait
 * 
 * @return int 1 if success, -1 if failed
 * 
 * @note i just a function to make the code more readable
*/
__attribute__((always_inline, used)) inline int	swait(
	sem_t *sem
)
{
	if (__builtin_expect(!sem, unexpected))
		return (-1);
	else
		return (sem_wait(sem));
}

/**
 * @brief	post the semaphore
 * 
 * @param sem The semaphore to post
 * 
 * @return int 1 if success, -1 if failed
 * 
 * @note i just a function to make the code more readable
*/
__attribute__((always_inline, used)) inline int	post(
	sem_t *sem
)
{
	if (__builtin_expect(!sem, unexpected))
		return (-1);
	else
		return (sem_post(sem));
}

#pragma endregion Functions