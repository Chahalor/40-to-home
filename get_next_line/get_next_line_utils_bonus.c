/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 08:52:22 by nduvoid           #+#    #+#             */
/*   Updated: 2024/11/04 10:06:02 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

ssize_t	linelen(char *buffer, ssize_t start, ssize_t max)
{
	ssize_t	i;
	ssize_t	j;

	i = start;
	j = 0;
	while (buffer[i] != '\n' && j < max && buffer[i] != '\0')
	{
		i++;
		j++;
	}
	if (j < max)
		j++;
	return (j);
}

char	*gnl_substr(const char *buffer, ssize_t start, size_t size)
{
	char	*result;
	size_t	i;
	size_t	j;

	result = (char *)malloc(sizeof(char) * size);
	if (!result)
		return (NULL);
	i = start;
	j = 0;
	while (j < size && buffer[i])
	{
		result[j] = buffer[i];
		i++;
		j++;
	}
	result[j] = '\0';
	return (result);
}

ssize_t	get_buffer_use(t_fd lst_fd[MAX_FD])
{
	ssize_t	result;
	int		i;

	i = 0;
	result = 0;
	while (i < MAX_FD)
	{
		result += lst_fd[i].buffer_use;
		i++;
	}
	return (result);
}