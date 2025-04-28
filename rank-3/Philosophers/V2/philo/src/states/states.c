/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   states.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 13:54:03 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/28 09:42:14 by nduvoid          ###   ########.fr       */
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
__attribute__((always_inline, used)) static inline int	_destroy_global(
	t_global_data *global_data,
	t_mutex *mutex_global
)
{
	pthread_mutex_destroy(&global_data->print_lock);
	unlock(mutex_global);
	pthread_mutex_destroy(mutex_global);
	return (0);
}

/** */
__attribute__((always_inline, used)) static inline int	_init_global(
	t_global_data *global_data,
	t_mutex *mutex_global
)
{
	pthread_mutex_init(mutex_global, NULL);
	pthread_mutex_init(&global_data->print_lock, NULL);
	global_data->run = true;
	global_data->nb_finished = 0;
	return (global_data->run);
}

/** */
__attribute__((hot)) int	global_manager(
	t_request request
)
{
	static t_global_data	global_data = {0};
	static t_mutex			mutex_global = PTHREAD_MUTEX_INITIALIZER;
	int						result;

	if (__builtin_expect(request == request_init, unexpected))
		return (_init_global(&global_data, &mutex_global));
	result = 0;
	lock(&mutex_global);
	if (request == request_get_run)
		result = global_data.run;
	else if (request == request_get_finished)
		result = global_data.nb_finished;
	else if (request == request_add_finished)
		result = ++global_data.nb_finished;
	else if (__builtin_expect(request == request_start, unexpected))
		global_data.run = true;
	else if (__builtin_expect(request == request_stop, unexpected))
		global_data.run = false;
	else if (__builtin_expect(request == request_destroy, unexpected))
		return (_destroy_global(&global_data, &mutex_global));
	unlock(&mutex_global);
	return (result);
}

#pragma endregion Functions