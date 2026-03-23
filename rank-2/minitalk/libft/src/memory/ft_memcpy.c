/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:07:42 by nduvoid           #+#    #+#             */
/*   Updated: 2024/11/21 10:39:50 by nduvoid          ###   ########.fr       */
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
void	*ft_memcpy(void *dest, const void *src, unsigned long int n)
{
	unsigned long int	i;

	if (!dest && !src && n)
		return (NULL);
	i = 0;
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}
