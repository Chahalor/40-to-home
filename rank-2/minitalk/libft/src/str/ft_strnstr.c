/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:12:24 by nduvoid           #+#    #+#             */
/*   Updated: 2024/11/21 10:41:52 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Locates the first occurrence of the null-terminated string little
 * in the string big, where not more than len characters are searched.
 * 
 * @param big The string to be searched.
 * @param little The string to search for.
 * @param len The number of characters to search.
 * @return char* A pointer to the first occurrence in big of the entire
 */
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t			i;
	unsigned int	j;

	if (little[0] == '\0')
		return ((char *)big);
	i = 0;
	while (i < len && big[i] != '\0')
	{
		j = 0;
		while (big[i + j] == little[j] && little[j] && i + j < len
			&& big[i + j])
			j++;
		if (ft_strlen(little) == j)
			return (&((char *)big)[i]);
		i++;
	}
	return (NULL);
}
