/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:07:38 by nduvoid           #+#    #+#             */
/*   Updated: 2024/12/04 12:59:41 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sa(t_stack **stack)
{
	int	tmp;

	if ((*stack)->size < 2)
		return ;
	write(1, SA, 3);
	tmp = (*stack)->stack[0];
	(*stack)->stack[0] = (*stack)->stack[1];
	(*stack)->stack[1] = tmp;
}

void	sb(t_stack **stack)
{
	int	tmp;

	if ((*stack)->size < 2)
		return ;
	write(1, SB, 3);
	tmp = (*stack)->stack[0];
	(*stack)->stack[0] = (*stack)->stack[1];
	(*stack)->stack[1] = tmp;
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	int	tmp;

	if ((*stack_a)->size > 2)
	{
		tmp = (*stack_a)->stack[0];
		(*stack_a)->stack[0] = (*stack_a)->stack[1];
		(*stack_a)->stack[1] = tmp;
	}
	if ((*stack_b)->size > 2)
	{
		tmp = (*stack_b)->stack[0];
		(*stack_b)->stack[0] = (*stack_b)->stack[1];
		(*stack_b)->stack[1] = tmp;
	}
	write(1, SS, 3);
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	int	i;

	if ((*stack_b)->size < 1)
		return ;
	i = (*stack_a)->size;
	while (i > 0)
	{
		(*stack_a)->stack[i] = (*stack_a)->stack[i - 1];
		i--;
	}
	(*stack_a)->stack[0] = (*stack_b)->stack[0];
	(*stack_a)->size++;
	i = 0;
	while (i < (*stack_b)->size)
	{
		(*stack_b)->stack[i] = (*stack_b)->stack[i + 1];
		i++;
	}
	(*stack_b)->size--;
	write(1, PA, 3);
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	int	i;

	if ((*stack_a)->size < 1)
		return ;
	i = (*stack_b)->size;
	while (i > 0)
	{
		(*stack_b)->stack[i] = (*stack_b)->stack[i - 1];
		i--;
	}
	(*stack_b)->stack[0] = (*stack_a)->stack[0];
	(*stack_b)->size++;
	i = 0;
	while (i < (*stack_a)->size)
	{
		(*stack_a)->stack[i] = (*stack_a)->stack[i + 1];
		i++;
	}
	(*stack_a)->size--;
	write(1, PB, 3);
}
