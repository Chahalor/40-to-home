/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _data.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 10:13:52 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/10 19:48:08 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region "Headers"
// System
#include <sys/time.h>
#include <unistd.h>

// Global
#include "type.h"
#include "config.h"

// Modules
#include "_philosopher.h"
#include "utils.h"

#pragma endregion "Headers"
#pragma region "Functions"

/** */
__attribute__((cold)) t_global	*store_global(
	t_global *global
)
{
	static t_global	*data = NULL;

	if (__builtin_expect(global != NULL, unexpected))
		data = global;
	else if (__builtin_expect(data == NULL, unexpected))
		return (NULL);
	return (data);
}

/** */
__attribute__((hot)) int	get_data(
	const t_info request
)
{
	static t_global	*data = NULL;
	int				value;

	if (__builtin_expect(request == setup, unexpected))
	{// @todo change the order to place the most requested first
		data = store_global(NULL);
		return (0);
	}
	// printf("get_data()");	// rm
	pthread_mutex_lock(&data->data_lock);
	if (request == time_to_die)
		value = (data->data.time_to_die);
	else if (request == time_to_eat)
		value = (data->data.time_to_eat);
	else if (request == time_to_sleep)
		value =  (data->data.time_to_sleep);
	else if (request == nb_meals)
		value = (data->data.nb_meals);
	else if (request == state)
		value = (data->data.running);
	else if (request == start_time)
		value = (data->data.start_time);
	else
		value = (-1);
	pthread_mutex_unlock(&data->data_lock);
	return (value);
}

/** */
__attribute__((hot)) void	lock_print(
	void
)
{
	t_global	*global;

	global = store_global(NULL);
	if (__builtin_expect(!global, unexpected))
		return ;
	else
		pthread_mutex_lock(&global->print_lock);
}

/** */
__attribute__((hot)) void	unlock_print(
	void
)
{
	t_global	*global;

	global = store_global(NULL);
	if (__builtin_expect(!global, unexpected))
		return ;
	else
		pthread_mutex_unlock(&global->print_lock);
}

#pragma endregion "Functions"