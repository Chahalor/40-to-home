/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:42:42 by nduvoid           #+#    #+#             */
/*   Updated: 2024/11/21 10:38:32 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Copies up to size - 1 characters from the NUL-terminated string src
 * to dst, NUL-terminating the result.
 * 
 * @param dst The destination string.
 * @param src The source string.
 * @param size The size of the destination buffer.
 * @return unsigned long int The total length of the string they tried to create.
 */
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
