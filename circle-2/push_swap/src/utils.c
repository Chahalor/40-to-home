/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 11:26:27 by nduvoid           #+#    #+#             */
/*   Updated: 2024/12/11 15:06:17 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	exiting(int code)
{
	write(2, "Error\n", 6);
	exit(code);
}

int	get_max(t_stack *stack)
{
	int	max;
	int	i;

	max = stack->stack[0];
	i = 1;
	while (i < stack->size)
	{
		if (stack->stack[i] > max)
			max = stack->stack[i];
		i++;
	}
	return (max);
}

int	get_poss(t_stack *stack, int max)
{
	int	i;

	i = 0;
	while (stack->stack[i] != max && i < stack->size)
		i++;
	{
		if (stack->stack[i] == max)
			return (i);
		i++;
	}
	return (-1);
}

int	get_expo(int max)
{
	int	expo;

	expo = 1;
	while (max / 10 > 0)
	{
		max /= 10;
		expo *= 10;
	}
	return (expo);
}