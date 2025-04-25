/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   states.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 13:54:03 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/25 19:43:50 by nduvoid          ###   ########.fr       */
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
	t_request request
)
{
	static t_global_data	global_data = {0};
	static t_mutex			mutex_global = PTHREAD_MUTEX_INITIALIZER;
	int						result;

	if (request == request_init)
	{
		pthread_mutex_init(&mutex_global, NULL);
		global_data.run = true;
		global_data.nb_finished = 0;
		printf("global_manager: init\n"); // rm
		return (global_data.run);
	}
	result = 0;
	lock(&mutex_global);
	if (request == request_get_run)
		result = global_data.run;
	else if (request == request_get_finished)
		result = global_data.nb_finished;
	else if (request == request_add_finished)
		result = ++global_data.nb_finished;
	else if (__builtin_expect(request == request_stop, unexpected))
		global_data.run = false;
	else if (__builtin_expect(request == request_destroy, unexpected))
	{
		unlock(&mutex_global);	// important to unlock before destroy
		return (pthread_mutex_destroy(&mutex_global));
	}
	unlock(&mutex_global);
	return (result);
}


#pragma endregion Functions