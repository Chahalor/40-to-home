/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:02:03 by nduvoid           #+#    #+#             */
/*   Updated: 2024/11/07 15:20:18 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	get_line_len(char *s, size_t max)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != '\n' && i < max)
		i++;
	if (s[i] == '\n')
		i++;
	return (i);
}

char	*gnl_strdup(char *buffer, ssize_t size)
{
	char	*result;
	ssize_t	i;

	result = (char *)malloc(sizeof(char) * (size + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (i < size)
	{
		result[i] = buffer[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

ssize_t	get_nl_pos(char buffer[BUFFER_SIZE])
{
	ssize_t	i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}


size_t	gnl_strcpy(const char buffer[BUFFER_SIZE], char *dest, size_t max)
{
	size_t	i;

	i = 0;
	while (i < max)
	{
		dest[i] = buffer[i];
		i++;
	}
	i++;
}

size_t	get_stock_size(char *stock)
{
	size_t	i;

	i = 0;
	while (stock[i])
		i++;
	return (i);
}
