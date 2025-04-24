/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   states.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 13:54:03 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/24 08:45:53 by nduvoid          ###   ########.fr       */
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
__attribute__((hot)) int	global_manager(
	t_request request	/* the request to set           */
	// ,t_mutex *mutex		/* the mutex to lock the acces */
)
{
	static t_global_data	global_data = {0};
	static t_mutex			mutex_global = PTHREAD_MUTEX_INITIALIZER;
	int						result;

	lock(&mutex_global);
	result = -1;
	if (request == request_get_run)
		result = global_data.run;
	else if (unexpect(request == request_init))
	{
		global_data.run = true;
		result = global_data.run;
	}
	else if (unexpect(request == request_stop))
		global_data.run = false;
	unlock(&mutex_global);
	return (result);
}

#pragma endregion Functions