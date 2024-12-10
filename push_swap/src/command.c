/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:07:38 by nduvoid           #+#    #+#             */
/*   Updated: 2024/12/06 08:59:06 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

extern t_stack *stack_a;
extern t_stack *stack_b;

void	sa()
{
	int		tmp;
	t_stack	**stack;

	stack = &stack_a;
	if ((*stack)->size < 2)
		return ;
	write(1, SA, 3);
	tmp = (*stack)->stack[0];
	(*stack)->stack[0] = (*stack)->stack[1];
	(*stack)->stack[1] = tmp;
}

void	sb()
{
	int		tmp;
	t_stack	**stack;

	stack = &stack_b;
	if ((*stack)->size < 2)
		return ;
	write(1, SB, 3);
	tmp = (*stack)->stack[0];
	(*stack)->stack[0] = (*stack)->stack[1];
	(*stack)->stack[1] = tmp;
}

void	ss()
{
	int		tmp;

	if (stack_a->size > 2)
	{
		tmp = stack_a->stack[0];
		stack_a->stack[0] = stack_a->stack[1];
		stack_a->stack[1] = tmp;
	}
	if (stack_b->size > 2)
	{
		tmp = stack_b->stack[0];
		stack_b->stack[0] = stack_b->stack[1];
		stack_b->stack[1] = tmp;
	}
	write(1, SS, 3);
}

void	pa()
{
	int	i;

	if (stack_b->size < 1)
		return ;
	i = stack_a->size - 1;
	while (i > 0)
	{
		stack_a->stack[i] = stack_a->stack[i - 1];
		i--;
	}
	stack_a->stack[0] = stack_b->stack[0];
	stack_a->size++;
	i = 0;
	while (i < stack_b->size - 2)
	{
		stack_b->stack[i] = stack_b->stack[i + 1];
		i++;
	}
	stack_b->size--;
	write(1, PA, 3);
}

void	pb()
{
	int	i;

	if (stack_a->size < 1)
		return ;
	i = stack_b->size - 1;
	while (i > 0)
	{
		stack_b->stack[i] = stack_b->stack[i - 1];
		i--;
	}
	stack_b->stack[0] = stack_a->stack[0];
	stack_b->size++;
	i = 0;
	while (i < stack_a->size - 2)
	{
		stack_a->stack[i] = stack_a->stack[i + 1];
		i++;
	}
	stack_a->size--;
	write(1, PB, 3);
}
