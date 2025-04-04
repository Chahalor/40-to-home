/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   level.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 10:58:34 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/04 11:15:12 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "list.h"

t_error_level *errors_storage(const int level)
{
	static t_error_level	*error_list[MAX_ERROR_LEVEL] = {NULL};

	if (level < 0 || level >= MAX_ERROR_LEVEL)
		return (NULL);
	return (error_list[level]);
}

t_error_level	*get_bottom(t_error_level *list)
{
	t_error_level	*bottom;

	bottom = list;
	while (bottom->next)
		bottom = bottom->next;
	return (bottom);
}

int	add_error(const char *msg, const int code, const int level)
{
	t_error_level	*error_list;
	t_error_level		*new_error;

	if (level < 0 || level >= MAX_ERROR_LEVEL)
		return (-1);
	error_list = errors_storage(level);
	if (!error_list)
	{
		error_list = (t_error_level *)malloc(sizeof(t_error_level));
		if (!error_list)
			return (-1);
		*error_list = (t_error_level){
			.message = NULL, .next = NULL,
			.level = level, .code = code};
	}
	else
	{
		new_error = malloc(sizeof(t_error_level));
		if (!new_error)
			return (-1);
		*new_error = (t_error_level){.message = msg, .next = NULL,
			.level = level, .code = code};
		get_bottom(error_list)->next = new_error;
	}
}
