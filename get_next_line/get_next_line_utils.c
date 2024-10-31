/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 10:50:55 by nduvoid           #+#    #+#             */
/*   Updated: 2024/10/30 10:50:55 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

ssize_t	linelen(char *buffer, ssize_t start, ssize_t max)
{
	ssize_t	i;

	i = start;
	while (buffer[i] != '\n' && i < max && buffer[i] != '\0')
		i++;
	if (i < max)
		i++;
	return (i - start);
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
