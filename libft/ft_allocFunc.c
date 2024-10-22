/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_allocFunc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:15:43 by nduvoid           #+#    #+#             */
/*   Updated: 2024/10/21 15:55:16 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(unsigned long int nmemb, unsigned long int size)
{
	void	*arr;

	if (nmemb == 0)
		return (malloc(0));
	else if (size == 0)
		return (malloc(0));
	arr = malloc(nmemb * size);
	if (!arr)
		return (NULL);
	ft_memset(arr, '\0', size * nmemb);
	return (arr);
}

char	*ft_strdup(const char *s)
{
	char			*dup;
	unsigned int	i;
	unsigned int	slen;

	if (!s)
		return (NULL);
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
