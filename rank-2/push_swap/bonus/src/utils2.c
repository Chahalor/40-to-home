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

#include "../header/tester.h"

/**
 * @brief compare two strings
 * 
 * @param s1: the first string
 * @param s2: the second string
 * @return
 * 
 * - 0 if the two strings are equal
 * 
 * - the difference between the two strings
 */
int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	if (!s1 || !s2)
		return (-1);
	if (s1[0] == '\0')
		return (-(unsigned char)s2[0]);
	else if (s2[0] == '\0')
		return ((unsigned char)s1[0]);
	i = 0;
	while (s1[i] || s2[i])
	{
		if ((unsigned char)s1[i] < (unsigned char)s2[i] || s1[i] == '\0')
			return (-(unsigned char)s2[i]);
		else if ((unsigned char)s1[i] > (unsigned char)s2[i] || s2[i] == '\0')
			return ((unsigned char)s1[i]);
		i++;
	}
	return (0);
}

/**
 * @brief allocate memory and set it to 0
 * 
 * @param nmemb: number of elements
 * @param size: size of each element
 * @return
 * 
 * - void*: the allocated memory
 * 
 * - NULL if an error occurs (malloc)
 */
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*arr;
	size_t	i;

	if (nmemb == 0 || size == 0)
		return (NULL);
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
