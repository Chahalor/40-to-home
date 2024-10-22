/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfunc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:51:56 by nduvoid           #+#    #+#             */
/*   Updated: 2024/10/21 09:20:06 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long int	ft_strlen(const char *s)
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;

	if (c == '\0')
		return (&((char *)s)[ft_strlen(s)]);
	i = 0;
	while (s[i])
		if (s[i++] == (unsigned char)c)
			return (&((char *)s)[i - 1]);
	return (NULL);
}

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
