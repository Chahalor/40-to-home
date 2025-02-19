/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 12:54:08 by nduvoid           #+#    #+#             */
/*   Updated: 2024/11/21 10:28:17 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Sets the first n bytes of the block of memory pointed by s to zero.
 * 
 * @param s Pointer to the block of memory to fill.
 * @param n Number of bytes to be set to zero.
 * @return void
 */
void	ft_bzero(void *s, unsigned long int n)
{
	unsigned long int	i;

	i = 0;
	while (i < n)
		((unsigned char *)s)[i++] = 0;
}
