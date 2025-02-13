/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:11:59 by nduvoid           #+#    #+#             */
/*   Updated: 2024/11/21 10:42:03 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Locates the last occurrence of the character c in the string s.
 * 
 * @param s String to be searched.
 * @param c Character to be found.
 * @return char* A pointer to the last occurrence of c in s.
 */
char	*ft_strrchr(const char *s, int c)
{
	unsigned int	i;

	i = ft_strlen(s);
	while (i > 0)
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i--;
	}
	if (s[0] == (char)c)
		return ((char *)&s[0]);
	return (NULL);
}
