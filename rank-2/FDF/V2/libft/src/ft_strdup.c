/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 13:59:41 by nduvoid           #+#    #+#             */
/*   Updated: 2024/11/21 10:38:59 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Allocates sufficient memory for a copy of the string s,
 * does the copy, and returns a pointer to it.
 * 
 * @param s String to be copied.
 * @return char* Pointer to the copy of the string.
 */
char	*ft_strdup(const char *s)
{
	char			*dup;
	unsigned int	i;
	unsigned int	slen;

	slen = ft_strlen(s);
	dup = (char *)malloc(sizeof(char) * (slen + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
