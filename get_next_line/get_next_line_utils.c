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

ssize_t	linelen(char *buffer, ssize_t max)
{
	ssize_t	i;

	i = 0;
	while (buffer[i] != '\n' && i < max && buffer[i] != '\0')
		i++;
	if (i < max)
		i++;
	return (i);
}

char	*gnl_strdup(const char *buffer, ssize_t size)
{
	char	*result;
	ssize_t	i;

	result = (char *)malloc(sizeof(char) * size);
	if (!result || !buffer)
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