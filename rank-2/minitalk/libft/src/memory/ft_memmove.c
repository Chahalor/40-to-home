/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:08:08 by nduvoid           #+#    #+#             */
/*   Updated: 2024/11/21 10:39:45 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Copies n bytes from memory area src to memory area dest.
 * 
 * @param dest Pointer to the destination array
 * where the content is to be copied.
 * @param src Pointer to the source of data to be copied.
 * @param n Number of bytes to copy.
 * @return void* dest
 */
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;

	if (!dest && !src)
		return (NULL);
	if (((unsigned char *)src) < ((unsigned char *)dest)
		&& ((unsigned char *)src) < ((unsigned char *)dest) + n)
	{
		i = n;
		while (i-- > 0)
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		return (dest);
	}
	i = 0;
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}
