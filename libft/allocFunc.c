/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocFunc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:15:43 by nduvoid           #+#    #+#             */
/*   Updated: 2024/10/17 14:55:37 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(unsigned long int nmemb, unsigned long int size)
{
	void	*arr;

	if (nmemb == 0)
		return (NULL);
	else if (size == 0)
		return (malloc(1));
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

	slen = ft_strlen(s);
	dup = malloc(sizeof(char) * (slen + 1));
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
