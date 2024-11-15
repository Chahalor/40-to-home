/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 18:35:00 by nduvoid           #+#    #+#             */
/*   Updated: 2024/11/15 14:07:23 by nduvoid          ###   ########.fr       */
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

size_t	line_len(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	return (i++);
}

void	gnl_strcpy(char *dest, const char *src, size_t start)
{
	size_t	i;

	if (!src)
		return ;
	i = 0;
	while (src[start])
		dest[i++] = src[start++];
	dest[i] = '\0';
}

char	*gnl_strdup(char *s, size_t max)
{
	size_t	len;
	char	*result;
	size_t	i;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (i < len && i < max)
	{
		result[i] = s[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}
