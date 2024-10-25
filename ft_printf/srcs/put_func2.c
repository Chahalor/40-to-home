/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_func2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 08:55:00 by nduvoid           #+#    #+#             */
/*   Updated: 2024/10/25 09:02:10 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	writeuint(unsigned int uint)
{
	char		buffer[10];
	__int8_t	i;

	if (uint == 0)
		return (write(1, "0", 1));
	i = 9;
	while (uint > 0)
	{
		buffer[i--] = '0' + uint % 10;
		uint /= 10;
	}
	return (write(1, &buffer[i + 1], 9 - i));
}

int	writelhex(int nb)
{
	char	buffer[16];
	int		size_print;
	__int8_t	i;
	int			wout;

	if (nb == -2147483647 - 1)
		return (write(1, "80000000", 8));

	size_print = 0;
	if (nb == 0)
	{
		if (write(1, "0", 1) == -1)
			return (-1);
		return (size_print + 1);
	}
	i = 15;
	while (nb > 0)
	{
		buffer[i--] = LHEX_CHAR[nb % 16];
		nb /= 16;
	}
	wout = write(1, &buffer[i + 1], 15 - i);
	if (wout == -1)
		return (-1);
	return (size_print + wout);
}

int	writeuhex(int nb)
{
	char	buffer[16];
	int		size_print;
	__int8_t	i;
	int			wout;

	if (nb == -2147483647 - 1)
		return (write(1, "80000000", 8));
	size_print = 0;
	if (nb == 0)
	{
		if (write(1, "0", 1) == -1)
			return (-1);
		return (size_print + 1);
	}
	i = 15;
	while (nb > 0)
	{
		buffer[i--] = UHEX_CHAR[nb % 16];
		nb /= 16;
	}
	wout = write(1, &buffer[i + 1], 15 - i);
	if (wout == -1)
		return (-1);
	return (size_print + wout);
}
