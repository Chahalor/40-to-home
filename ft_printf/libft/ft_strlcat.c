/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 13:43:35 by nduvoid           #+#    #+#             */
/*   Updated: 2024/10/23 13:52:56 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	i;
	size_t	j;

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
