/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:10:22 by nduvoid           #+#    #+#             */
/*   Updated: 2024/11/21 10:39:03 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Locates the first occurrence of c (converted to an unsigned char)
 * in the string pointed to by s.
 * 
 * @param s String to be searched.
 * @param c Character to be located.
 * @return char* Pointer to the located character in the string.
 */
char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;

	i = 0;
	while (s[i])
		if (s[i++] == (unsigned char)c)
			return (&((char *)s)[i - 1]);
	if (s[i++] == (unsigned char)c)
		return (&((char *)s)[i - 1]);
	return (NULL);
}
