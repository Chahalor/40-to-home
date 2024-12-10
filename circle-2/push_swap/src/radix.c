/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 10:21:06 by nduvoid           #+#    #+#             */
/*   Updated: 2024/12/06 08:40:15 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

extern t_stack	*stack_a;
extern t_stack	*stack_b;

int	max_value(t_stack *stack)
{
	int	i;
	int	max;

	max = stack->stack[0];
	i = 0;
	while (i < stack->size)
	{
		if (stack->stack[i] > max)
			max = stack->stack[i];
		i++;
	}
	return (max);
}

void	count_sort(int expo)
{
	int	i;
	int	j;

	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < stack_a->size)
		{
			if (stack_a->stack[0] / expo % 10 == i)
				pb();
			else
			{
				ra(true);
				j++;
			}
		}
		i++;
	}
	while (stack_b->size)
		pa();
}

void	radix_sort(void)
{
	int	max;
	int	expo;

	max = max_value(stack_a);
	expo = 1;
	while (max / expo > 0)
	{
		count_sort(expo);
		expo *= 10;
	}
}
