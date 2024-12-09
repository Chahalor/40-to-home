/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 13:17:25 by nduvoid           #+#    #+#             */
/*   Updated: 2024/12/09 13:17:25 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	if (s1[0] == '\0')
		return (-(unsigned char)s2[0]);
	else if (s2[0] == '\0')
		return ((unsigned char)s1[0]);
	i = 0;
	while (i < n)
	{
		if ((unsigned char)s1[i] < (unsigned char)s2[i] || s1[i] == '\0')
			return (-(unsigned char)s2[i]);
		else if ((unsigned char)s1[i] > (unsigned char)s2[i] || s2[i] == '\0')
			return ((unsigned char)s1[i]);
		i++;
	}
	return (0);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*arr;
	int		i;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if ((nmemb * size) / nmemb != size)
		return (NULL);
	arr = malloc(nmemb * size);
	if (!arr)
		return (NULL);
	i = 0;
	while (i < nmemb * size)
		((char *)arr)[i++] = 0;
	return (arr);
}
