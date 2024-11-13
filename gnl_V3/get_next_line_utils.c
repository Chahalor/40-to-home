/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 12:06:12 by nduvoid           #+#    #+#             */
/*   Updated: 2024/11/13 12:03:39 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t	min(size_t val1, size_t val2)
{
	if (val1 > val2)
		return (val2);
	return (val1);
}

char	*gnl_strdup(char *s, size_t max)
{
	char	*result;
	size_t	i;

	result = (char *)malloc(sizeof(char) * (min(ft_strlen(s), max) + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (s[i] && i < max)
	{
		result[i] = s[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

size_t	gnl_strlcpy(char *dest, const char *src, size_t max)
{
	size_t	i;

	if (max == 0 || !src || !dest)
		return (0);
	i = 0;
	while (src[i] && i < max)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (i);
}
