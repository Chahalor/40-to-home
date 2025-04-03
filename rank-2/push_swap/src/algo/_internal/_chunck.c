/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _chunck.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 10:19:26 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/03 13:55:42 by nduvoid          ###   ########.fr       */
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

/**
 * @brief hard coded way to sort small stack
 * 
 * @param stack_a the first stack
 * @param stack_b the second stack
 * 
 * @return void
 */
__attribute__((always_inline, used))
static inline void	small(t_stack **stack_a, t_stack **stack_b)
{
	if ((*stack_a)->size <= 3)
		return (sort_3(stack_a, stack_b));
	else
		return (four_or_five(stack_a, stack_b));
}

/**
 * @brief this function split the element of stack_a into blocks of size
 *  block_size and push them to stack_b
 * 
 * @param stack_a the first stack
 * @param stack_b the second stack
 * 
 * @return void
 */
__attribute__((always_inline, unused))
static inline void	split(t_stack **stack_a, t_stack **stack_b)
{
	const int		size = (*stack_a)->size;
	const int		block = _block_size(size);
	register int	start;
	register int	end;

	end = block;
	start = 0;
	while (start < size)
	{
		while (TRUE)
		{
			if (!_block(stack_a, stack_b, start, end))
				break ;
			interaction(PB, stack_a, stack_b);
			if ((*stack_b)->size > 3 && (*stack_b)->array[0].index
				< (start + ((end - start)) / 2))
				interaction(RB, stack_a, stack_b);
		}
		start += block;
		end += block;
	}
}

/**
 * @brief this function push all the elements of stack_b to stack_a
 * 
 * @param stack_a the first stack
 * @param stack_b the second stack
 * 
 * @return void
 */
__attribute__((always_inline, used))
static inline void	big(t_stack **stack_a, t_stack **stack_b)
{
	register int	pos_max;

	while ((*stack_b)->size > 0)
	{
		pos_max = get_max_pos(*stack_b);
		if (pos_max > (*stack_b)->size / 2)
			while (pos_max++ < (*stack_b)->size)
				interaction(RRB, stack_a, stack_b);
		else
			while (pos_max-- > 0)
				interaction(RB, stack_a, stack_b);
		interaction(PA, stack_a, stack_b);
	}
}

/**
 * @brief correct the stack_a by putting the minimum element at the top of the
 *  stack
 * 
 * @param stack_a the first stack
 * @param stack_b the second stack
 * 
 * @return void
 */
__attribute__((always_inline, used))
static inline void	correct(t_stack **stack, t_stack **stack_b)
{
	register int	min;
	register int	i;

	min = 0;
	i = -1;
	while (++i != (*stack)->size)
		if ((*stack)->array[i].index < (*stack)->array[min].index)
			min = i;
	if (min <= (*stack)->size / 2)
		while (min--)
			interaction(RA, stack, stack_b);
	else
		while (min++ < (*stack)->size)
			interaction(RRA, stack, stack_b);
}

/**
 * @brief this function is the main function for the chunk algorithm
 * 
 * @param stack_a the first stack
 * @param stack_b the second stack
 * 
 * @return 0 if the stack is sorted or empty, else the result of the algorithm
 * 
 * @details how it works:
 * 
 * 1. split the stack into blocks of size block_size (magic number tkt)
 * 
 * 2. push the blocks to stack_b
 * 
 * 3. move all the elements of stack_b to stack_a
 * 
 * 4. put the minimum element of stack_a at the top of the stack
 */
__attribute__((cold))
int	_chunk(t_stack **stack_a, t_stack **stack_b)
{
	if ((*stack_a)->size < 6)
		small(stack_a, stack_b);
	else
	{
		push_to_b(stack_a, stack_b);
		big(stack_a, stack_b);
		correct(stack_a, stack_b);
	}
	return (0);
}

#pragma endregion	/* Functions */