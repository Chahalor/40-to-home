/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 09:14:00 by marvin            #+#    #+#             */
/*   Updated: 2024/10/18 12:35:10 by nduvoid          ###   ########.fr       */
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

char	*exeption(int n)
{
	char	*r;

	if (n == 0)
	{
		r = (char *)malloc(sizeof(char) * 2);
		ft_strlcpy(r, "0", 2);
		return (r);
	}
	r = (char *)malloc(sizeof(char) * 12);
	ft_strlcpy(r, "-2147483648", 12);
	return (r);
}

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

// int	main(void)
// {
// 	int	nb = 0;
// 	char	*r = ft_itoa(nb);
// 	write(1, r, ft_strlen(r));
// 	write(1, "\n", 1);
// 	free(r);
// 	return (0);
// }