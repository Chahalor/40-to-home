/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 10:36:28 by nduvoid           #+#    #+#             */
/*   Updated: 2024/12/09 10:36:28 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

t_bool	is_digits(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (FALSE);
		i++;
	}
	return (TRUE);
}

static int	is_space(int c)
{
	if (c == ' ' || c == '\f' || c == '\n' || c == '\r' || c == '\t'
		|| c == '\v')
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int		r;
	size_t	i;
	int		neg;

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

t_bool	in_array(int *array, int size, int value)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (array[i] == value)
			return (TRUE);
		i++;
	}
	return (FALSE);
}

void	extand_instruct(char ***instructions, char *line, int size)
{
	char	**new;

	new = (char **)malloc(sizeof(char *) * 2);
	if (!new)
	{
		free(*instructions);
		instructions = NULL;
		return ;
	}
	new[0] = line;
	new[1] = NULL;
	*instructions[size] = new;
}