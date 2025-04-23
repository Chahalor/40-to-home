/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   states.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 13:54:03 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/23 14:48:16 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Headers

/* -----| Internal |----- */
	//...

/* -----| Modules  |----- */
#include "states.h"
#include "utils.h"

#pragma endregion Headers
#pragma region Functions

/** */
__attribute__((hot)) int	get_status(
	int	*status	/* the status to set */
)
{
	static int	*status_ptr = NULL;	// @todo: we need a mutex to protect this value

	if (unexpect(status))
		status_ptr = status;
	return (*status_ptr);
}

#pragma endregion Functions