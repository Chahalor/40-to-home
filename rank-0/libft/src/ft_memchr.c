/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:06:35 by nduvoid           #+#    #+#             */
/*   Updated: 2024/11/21 10:40:10 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Locates the first occurrence of c (converted to an unsigned char)
 * in string s.
 * 
 * @param s String to be analyzed.
 * @param c Character to be located.
 * @param n Number of bytes to be analyzed.
 * @return void* Pointer to the located character or NULL
 * if the character does not appear in the string.
 */
void	*ft_memchr(const void *s, int c, unsigned long int n)
{
	unsigned long int	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
			return (&((unsigned char *)s)[i]);
		i++;
	}
	return (NULL);
}
