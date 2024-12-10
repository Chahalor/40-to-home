/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:38:40 by nduvoid           #+#    #+#             */
/*   Updated: 2024/12/05 13:04:31 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

extern t_stack *stack_a;
extern t_stack *stack_b;

void	ra(t_bool w)
{
	int		tmp;
	int		i;
	t_stack	*stack;

	stack = stack_a;
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

void	rb(t_bool w)
{
	int		tmp;
	int		i;

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

void	rr()
{
	ra(false);
	rb(false);
	write(1, RR, 3);
}

void	rra(t_bool w)
{
	int		tmp;
	int		i;

	if (stack_a->size < 2)
		return ;
	if (w)
		write(1, RRA, 4);
	tmp = stack_a->stack[stack_a->size - 1];
	i = stack_a->size - 1;
	while (i > 0)
	{
		stack_a->stack[i] = stack_a->stack[i - 1];
		i--;
	}
	stack_a->stack[i] = tmp;
}

void	rrb(t_bool w)
{
	int		tmp;
	int		i;

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
