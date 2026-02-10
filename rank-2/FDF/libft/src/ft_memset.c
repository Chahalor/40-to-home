/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:08:37 by nduvoid           #+#    #+#             */
/*   Updated: 2024/11/21 10:39:37 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Fills the first n bytes of the memory area pointed to by s
 * with the constant byte c.
 * 
 * @param s Pointer to the memory area.
 * @param c Constant byte to be copied.
 * @param n Number of bytes to be copied.
 * @return void* Pointer to the memory area s.
 */
void	*ft_memset(void *s, int c, unsigned long int n)
{
	unsigned long int	i;

	i = 0;
	while (i < n)
		((unsigned char *)s)[i++] = c;
	return (s);
}
