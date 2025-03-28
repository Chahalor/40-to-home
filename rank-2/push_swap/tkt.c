/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tkt.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 16:39:22 by nduvoid           #+#    #+#             */
/*   Updated: 2025/03/28 08:22:54 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "_algo.h"
#include <stdlib.h>

void	best_movements(t_stack *stack_a, t_stack *stack_b)
{
	int		i;
	int		best_pos;
	t_nb	*tmp;

	tmp = &stack_b->array[stack_b->size - 1];
	best_pos = -1;
	i = -1;
	while (tmp)
	{
		if (tmp->index > stack_a->array[0].index)
			best_pos = get_pos(*tmp, stack_b);
		tmp = &stack_b->array[++i];
	}
	if (best_pos == -1)
		return ;
	while (best_pos-- > 0)
		interaction(RB, &stack_a, &stack_b);
	while (best_pos++ < stack_b->size)
		interaction(RRB, &stack_a, &stack_b);
}

int	find_best_pos(const t_stack *stack, const t_lis lis)
{
	t_nb	*tmp;
	int		i;
	int		best_pos;

	best_pos = -1;
	tmp = &stack->array[stack->size - 1];
	i = -1;
	while (tmp)
	{
		if (tmp->index > lis.start || tmp->index < lis.start + lis.size)
			best_pos = get_pos(*tmp, stack);
		tmp = &stack->array[++i];
	}
	return (best_pos);
}

void	move_uncommons(t_stack **stack_a, t_stack **stack_b, const t_lis lis)
{
	int		i;
	int		best_pos;

	i = -1;
	while (++i < (*stack_a)->size)
	{
		best_pos = find_best_pos(*stack_a, lis);
		if (best_pos > (*stack_a)->size / 2)
			while (i++ < (*stack_a)->size)
				interaction(RA, stack_a, stack_b);
		else
			while (i-- > 0)
				interaction(RRA, stack_a, stack_b);
		interaction(PB, stack_a, stack_b);
	}
}

static void	algo2(t_stack *a_stk, t_stack *stack_b)
{
	t_lis	lis;

	lis = ft_get_lis2(a_stk);
	move_uncommons(a_stk, stack_b, lis);
	best_movements(a_stk, stack_b);
	ft_min_to_the_top(a_stk, a_stk, a_stk->inst);
}

static void	algo1(t_stack *a_stk, t_stack *stack_b)
{
	t_stack	*lis;

	lis = ft_get_lis1(a_stk);
	if (!lis)
		return ;
	ft_move_uncommons(a_stk, stack_b, lis);
	ft_clear_stacks(&lis, NULL);
	ft_best_movements(a_stk, stack_b);
	ft_min_to_the_top(a_stk, a_stk, a_stk->inst);
}

void	ft_lis_algorithm(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*stack_a2;
	t_stack	*stack_b2;

	stack_a2 = copy_stack(*stack_a);
	stack_b2 = copy_stack(*stack_b);
	if (!stack_a2 || !stack_b2)
	{
		destroyer(stack_a2);
		destroyer(stack_b2);
		return ;
	}
	algo2(stack_a2, stack_b2);
	algo1((*stack_a), stack_b);
}
