/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strFunc2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:42:42 by nduvoid           #+#    #+#             */
/*   Updated: 2024/10/17 13:26:59 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long int	ft_strlcpy(char *dst, const char *src,
								unsigned long int size)
{
	unsigned long int	i;
	size_t				len_src;

	len_src = ft_strlen(src);
	if (size == 0)
		return (len_src);
	i = 0;
	while (i < size - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

unsigned long int	strlcat(char *dst, const char *src,
					unsigned long int size)
{
	unsigned int	i;
	unsigned int	len_dst;

	len_dst = ft_strlen(dst);
	i = 0;
	while (i < size && src[i] != '\0')
	{
		dst[len_dst + i] = src[i];
		i++;
	}
	if (i < size)
		dst[len_dst + i] = '\0';
	return (len_dst + i);
}
