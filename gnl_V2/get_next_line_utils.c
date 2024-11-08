/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:02:03 by nduvoid           #+#    #+#             */
/*   Updated: 2024/11/08 17:03:33 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	nl_in(char buffer[BUFFER_SIZE], size_t max)
{
	size_t	i;

	i = 0;
	while (i < max)
	{
		if (buffer[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*gnl_stockdup(char **stock, size_t start, size_t stocksize)
{
	char	*result;
	size_t	i;
	size_t	j;

	if (stocksize < start)
		return (NULL);
	result = (char *)malloc(sizeof(char) * (stocksize - start + 1));
	if (!result)
		return (NULL);
	i = start;
	j = 0;
	while (i < stocksize)
		result[j++] = (*stock)[i++];
	result[i] = '\0';
	free(*stock);
	return (result);
}
