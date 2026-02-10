/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 12:54:08 by nduvoid           #+#    #+#             */
/*   Updated: 2025/02/27 09:50:49 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdint.h>

/**
 * @brief Sets the first n bytes of the block of memory pointed by s to zero.
 * 
 * @param s Pointer to the block of memory to fill.
 * @param n Number of bytes to be set to zero.
 * @return void
 */
void	ft_bzero(void *ptr, size_t len)
{
	uint8_t			*p;
	const uint64_t	zero[4] = {0, 0, 0, 0};
	const size_t	step = 32;

	p = (uint8_t *)ptr;
	while (((uintptr_t)p % step) && len)
	{
		*p++ = 0;
		--len;
	}
	while (len >= step)
	{
		*(uint64_t *)(p + 0) = zero[0];
		*(uint64_t *)(p + 8) = zero[1];
		*(uint64_t *)(p + 16) = zero[2];
		*(uint64_t *)(p + 24) = zero[3];
		p += step;
		len -= step;
	}
	while (len--)
		*p++ = 0;
}

// void	ft_bzero(void *s, unsigned long int n)
// {
// 	unsigned long int	i;

// 	i = 0;
// 	while (i < n)
// 		((unsigned char *)s)[i++] = 0;
// }