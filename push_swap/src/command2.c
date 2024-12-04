/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:38:40 by nduvoid           #+#    #+#             */
/*   Updated: 2024/12/04 12:55:02 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ra(t_stack *stack, t_bool w)
{
	int	tmp;
	int	i;

	if (stack->size < 2)
		return ;
	if (w == true)
		write(1, RA, 3);
	tmp = stack->stack[0];
	i = 0;
	while (i < stack->size - 1)
	{
		stack->stack[i] = stack->stack[i + 1];
		i++;
	}
	stack->stack[i] = tmp;
}

void	rb(t_stack *stack_b, t_bool w)
{
	int	tmp;
	int	i;

	if (stack_b->size < 2)
		return ;
	if (w)
		write(1, RB, 3);
	tmp = stack_b->stack[0];
	i = 0;
	while (i < stack_b->size - 1)
	{
		stack_b->stack[i] = stack_b->stack[i + 1];
		i++;
	}
	stack_b->stack[i] = tmp;
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	ra(stack_a, false);
	rb(stack_b, false);
	write(1, RR, 3);
}

void	rra(t_stack *stack, t_bool w)
{
	int	tmp;
	int	i;

	if (stack->size < 2)
		return ;
	if (w)
		write(1, RRA, 4);
	tmp = stack->stack[stack->size - 1];
	i = stack->size - 1;
	while (i > 0)
	{
		stack->stack[i] = stack->stack[i - 1];
		i--;
	}
	stack->stack[i] = tmp;
}

void	rrb(t_stack *stack_b, t_bool w)
{
	int	tmp;
	int	i;

	if (stack_b->size < 2)
		return ;
	if (w)
		write(1, RRB, 4);
	tmp = stack_b->stack[stack_b->size - 1];
	i = stack_b->size - 1;
	while (i > 0)
	{
		stack_b->stack[i] = stack_b->stack[i - 1];
		i--;
	}
	stack_b->stack[i] = tmp;
}
