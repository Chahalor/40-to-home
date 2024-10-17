/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memfunc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:59:30 by nduvoid           #+#    #+#             */
/*   Updated: 2024/10/17 14:23:40 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, unsigned long int n)
{
	unsigned long int	i;

	i = 0;
	while (i < n)
		((unsigned char *)s)[i++] = c;
	return (s);
}

void	*ft_memcpy(void *dest, const void *src, unsigned long int n)
{
	unsigned long int	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}

void	*ft_memchr(const void *s, int c, unsigned long int n)
{
	unsigned long int	i;

	i = 0;
	while (i < n)
	{
		if (((char *)s)[i] == c)
			return (&((unsigned char *)s)[i]);
		i++;
	}
	return (NULL);
}

int	ft_memcmp(const void *s1, const void *s2, unsigned long int n)
{
	unsigned long int	i;
	int					diff;

	i = 0;
	while (i < n)
	{
		diff = ((unsigned char *)s1)[i] - ((unsigned char *)s2)[i];
		if (diff != 0)
			return (diff);
		i++;
	}
	return (0);
}

void	*ft_memmove(void *dest, const void *src, unsigned long int n)
{
	unsigned long int	i;
	void				*tmp_arr;

	tmp_arr = ft_calloc(1, n);
	if (!tmp_arr)
		return (NULL);
	i = 0;
	ft_memcpy(tmp_arr, src, n);
	ft_memcpy(dest, tmp_arr, n);
	return (dest);
}
