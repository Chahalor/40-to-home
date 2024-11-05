/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:02:03 by nduvoid           #+#    #+#             */
/*   Updated: 2024/11/05 15:40:54 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

ssize_t	linelen(char buffer[BUFFER_SIZE], ssize_t max)
{
	ssize_t	i;

	i = 0;
	while (i < max && buffer[i] != '\n')
		i++;
	return (i);
}

void	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len_src;

	len_src = ft_strlen(src);
	if (size == 0)
		return ;
	i = 0;
	while (i < size - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	i;
	size_t	j;

	if (src[0] == '\0')
		return (0);
	dst_len = ft_strlen(dst);
	i = 0;
	while (dst[i])
		i++;
	j = 0;
	while (src[j] && (j + i + 1) < (size))
	{
		dst[i + j] = src[j];
		j++;
	}
	if (j < size)
		dst[i + j] = '\0';
	if (size <= dst_len)
		return (ft_strlen(src) + size);
	return (ft_strlen(src) + dst_len);
}
