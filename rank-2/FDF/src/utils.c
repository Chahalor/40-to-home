/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 14:42:56 by nduvoid           #+#    #+#             */
/*   Updated: 2024/12/13 15:06:01 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	exiting(int code, char *message)
{
	if (message)
		write(2, message, ft_strlen(message));
	else
		write(2, "Error\n", 6);
	exit(code);
}


static int	is_space(int c)
{
	if (c == ' ' || c == '\f' || c == '\n' || c == '\r' || c == '\t'
		|| c == '\v')
		return (1);
	return (0);
}

/**
 * @brief Convert a string to an integer
 * 
 * @param nptr The string to convert
 * @return The integer value of the string
 */
t_type	fdf_atoi(const char *nptr)
{
	t_type			r;
	unsigned int	i;
	int				neg;

	neg = 1;
	r = 0;
	i = 0;
	while (is_space(nptr[i]))
		i++;
	if (nptr[i] == '-')
	{
		neg = -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (nptr[i] && ft_isdigit(nptr[i]))
	{
		r = r * 10 + (nptr[i] - 48);
		i++;
	}
	return (r * neg);
}