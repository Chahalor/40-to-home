/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 09:14:00 by marvin            #+#    #+#             */
/*   Updated: 2024/11/21 10:40:46 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nb_len(int n)
{
	int	len;

	len = 0;
	if (n < 0)
		len = 1;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static char	*exeption(int n)
{
	char	*r;

	if (n == 0)
	{
		r = (char *)malloc(sizeof(char) * 2);
		if (!r)
			return (NULL);
		ft_strlcpy(r, "0", 2);
		return (r);
	}
	r = (char *)malloc(sizeof(char) * 12);
	if (!r)
		return (NULL);
	ft_strlcpy(r, "-2147483648", 12);
	return (r);
}

/**
 * @brief Allocates and returns a string representing the integer
 * received as an argument.
 * 
 * @param n Integer to be converted.
 * @return char* Pointer to the string representing the integer.
 */
char	*ft_itoa(int n)
{
	char			*r;
	int				len;
	unsigned int	nb;

	if (n == 0 || n == -2147483647 - 1)
		return (exeption(n));
	len = nb_len(n);
	r = (char *)malloc(sizeof(char) * (len + 1));
	if (!r)
		return (NULL);
	r[len] = '\0';
	nb = n;
	if (n < 0)
		nb = -n;
	if (n < 0)
		r[0] = '-';
	while (r[--len] != '-' && len >= 0)
	{
		r[len] = nb % 10 + '0';
		nb /= 10;
	}
	return (r);
}
