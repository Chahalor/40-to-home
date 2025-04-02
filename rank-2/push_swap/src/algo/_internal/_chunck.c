/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _chunck.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 10:19:26 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/02 18:03:22 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region "Header"
// System
	//...

// Global
	//...

// Modules
#include "stack.h"
#include "_algo.h"
#include "chunk/_chunk.h"
#include "utils.h"

#pragma endregion	/* Header */
#pragma region "Functions"

__attribute__((always_inline, used))
void	small(t_stack **stack_a, t_stack **stack_b)
{
	if ((*stack_a)->size <= 3)
		return (sort_3(stack_a, stack_b));
	else
		return (_four_or_five(stack_a, stack_b));
}

__attribute__((always_inline, used))
void	split(t_stack **stack_a, t_stack **stack_b)
{
	const int		size = (*stack_a)->size;
	int	block;
	register int	start;
	register int	end;

	block = _block_size((*stack_a)->size);
	end = block;
	start = 0;
	while (start < size)
	{
		while (TRUE)
		{
			if (!_block(stack_a, stack_b, start, end))
				break ;
			interaction(PB, stack_a, stack_b);
			/*if (start + block < (*stack_a)->size && ((*stack_b)->size > 3 
				&& (*stack_b)->array[0].value < start + ((end - start) / 2)))
				interaction(RR, stack_a, stack_b);
			else*/
			if ((*stack_b)->size > 3 && (*stack_b)->array[0].value \	// je vais essayer de voir si c est pas plus opti de RR ici (c est sur que sa l es mais faut trouver comment le voir)
				< start + ((end - start) / 2))
				interaction(RB, stack_a, stack_b);
		}
		start += block;
		end += block;
	}
}

// t_actions	get_actions(t_stack **stack_a, t_stack **stack_b)
// {
// 	t_actions	cheapest;
// 	int			cost_move_to_a;
// 	int			cost_move_in_a;
// 	int			i;

// 	i = -1; 
// 	while (++i < (*stack_b)->size)
// 	{
// 		cost_move_in_a = get_rotation_cost(get_right_index((*stack_b)->array[i],
// 			stack_a), (*stack_a)->size);
// 		cost_move_to_a = get_rotation_cost(i, (*stack_b)->size);
// 	}

	
// 	return (cheapest);
// }

__attribute__((always_inline, used))
void	big(t_stack **stack_a, t_stack **stack_b)
{
	// t_cost	cost;
	int	pos_max;
	// t_actions	actions;

	while ((*stack_b)->size > 0)
	{
		pos_max = get_max_pos(*stack_b);	// sa sa fait du 650 pour 100 et 5700 pour 500
		if (pos_max > (*stack_b)->size / 2)
		{
			while (pos_max++ < (*stack_b)->size)
				interaction(RRB, stack_a, stack_b);
		}
		else
		{
			while (pos_max-- > 0)
				interaction(RB, stack_a, stack_b);
		}
		interaction(PA, stack_a, stack_b);
		/* ----- */

		// actions = get_actions(stack_a, stack_b);
		// while (actions.multiple.number-- > 0)
		// 	interaction(actions.multiple.instuct, stack_a, stack_b);
		// while (actions.only_a.number-- > 0)
		// 	interaction(actions.only_a.instuct, stack_a, stack_b);
		// while (actions.only_b.number-- > 0)
		// 	interaction(actions.only_b.instuct, stack_a, stack_b);
		// interaction(PA, stack_a, stack_b);
		
		/* ----- */
		/*cost = _best(stack_a, stack_b);
		// ft_printf("Cost: {cost_a: %d, cost_b: %d, total: %d, pos_a: %d, pos_b: %d, val: %d}\n",
		// 	cost.cost_a, cost.cost_b, cost.total, cost.pos_a, cost.pos_b,
		// 	cost.val);
		while (cost.cost_a-- > 0 && cost.cost_b-- > 0)
		{
			interaction(RA, stack_a, stack_b);
			interaction(RB, stack_a, stack_b);
		}
		while (cost.cost_a++ < 0 && cost.cost_b++ < 0)
		{
			interaction(RRA, stack_a, stack_b);
			interaction(RRB, stack_a, stack_b);
		}
		while (cost.cost_a-- > 0)
			interaction(RA, stack_a, stack_b);
		while (cost.cost_a++ < 0)
			interaction(RRA, stack_a, stack_b);
		while (cost.cost_b-- > 0)
			interaction(RB, stack_a, stack_b);
		while (cost.cost_b++ < 0)
			interaction(RRB, stack_a, stack_b);
		interaction(PA, stack_a, stack_b);*/
	}
}

/** */
__attribute__((always_inline, used))
void	correct(t_stack **stack, t_stack **stack_b)
{
	register int	min;
	register int	i;

	min = 0;
	i = -1;
	while (++i != (*stack)->size)
		if ((*stack)->array[i].value < (*stack)->array[min].value)
			min = i;
	if (min <= (*stack)->size / 2)
		while (min--)
			interaction(RA, stack, stack_b);
	else
		while (min++ < (*stack)->size)
			interaction(RRA, stack, stack_b);
}

int	_chunk(t_stack **stack_a, t_stack **stack_b)
{
	if ((*stack_a)->size <= 5)
		small(stack_a, stack_b);
	else
	{
		split(stack_a, stack_b);
		// ft_printf("separatore\n");
		big(stack_a, stack_b);
		correct(stack_a, stack_b);
	}
	print_stack(*stack_a);
	print_stack(*stack_b);
	return (0);
}

#pragma endregion	/* Functions */