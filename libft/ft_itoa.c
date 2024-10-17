/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 09:14:00 by marvin            #+#    #+#             */
/*   Updated: 2024/10/17 12:45:08 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_malloc_size(int n)
{
	int	i;
	int	neg;

	neg = 0;
	if (n < 0)
		neg = 1;
	i = 0;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i + neg);
}

static char	*reverse_char(char *s, size_t size)
{
	size_t	i;
	size_t	j;
	char	buffer;

	i = 0;
	j = size;
	while (i < size / 2 + 1)
	{
		buffer = s[i];
		s[i] = s[j];
		s[j] = buffer;
		i++;
		j--;
	}
	return (s);
}

char	*ft_itoa(int n)
{
	int		r_size;
	char	*result;
	char	neg;
	int		i;

	neg = 0;
	if (n < 0)
	{
		neg = 1;
		n *= -1;
	}
	r_size = get_malloc_size(n);
	result = (char *)malloc(sizeof(char) * r_size);
	if (!result)
		return (NULL);
	result[r_size] = '\0';
	i = 0;
	while (n)
	{
		result[i++] = (n % 10) + 48;
		n /= 10;
	}
	if (neg)
		result[r_size] = '-';
	return (reverse_char(result, r_size));
}
