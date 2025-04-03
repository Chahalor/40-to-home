/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 13:29:10 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/03 13:37:36 by nduvoid          ###   ########.fr       */
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

#pragma endregion	/* Header */
#pragma region "Functions"

/**
 * @brief this function is the interface function for the defaut algorithm
 * of the push_swap project.
 * 
 * @param stack_a the first stack
 * @param stack_b the second stack
 * 
 * @return 0 if the stack is sorted or empty, else the result of the algorithm
*/
__attribute__((cold))
t_error	chunk_noris(t_stack **stack_a, t_stack **stack_b)
{
	if ((is_sorted(*stack_a) && (*stack_a)->size > 0) || (*stack_a)->size == 0)
		return (0);
	else
		return (_chunk(stack_a, stack_b));
}

/**
 * @brief this function is the interface function for the turkish algorithm
 * 
 * @param stack_a the first stack
 * @param stack_b the second stack
 * 
 * @return 0 if the stack is sorted or empty, else the result of the algorithm
 */
__attribute__((cold))
t_error	turkish(t_stack **stack_a, t_stack **stack_b)
{
	if ((is_sorted(*stack_a) && (*stack_a)->size > 0) || (*stack_a)->size == 0)
		return (0);
	else
		return (_turkish(stack_a, stack_b));
}

/**
 * @brief this is a troll function that sort the stack using random instructions
 * 
 * @param stack_a the first stack
 * @param stack_b the second stack
 * 
 * @return 0 if the stack is sorted or empty, else the result of the algorithm
 */
__attribute__((hot))
t_error	mein_random(t_stack **stack_a, t_stack **stack_b)
{
	int		seed;

	if ((is_sorted(*stack_a) && (*stack_a)->size > 0) || (*stack_a)->size == 0)
		return (0);
	seed = (size_t)((*stack_a)->array);
	while (!is_sorted(*stack_a))
	{
		seed ^= (seed >> (size_t) &(*stack_a)->array[0]) ^ (seed << 7) \
		^ (seed >> 4);
		interaction(seed % RRR, stack_a, stack_b);
		seed = (seed % 10) + 1;
	}
	return (0);
}

/**
 * @brief this is a serious function that wait a miracle to sort the stack
 * 
 * @param stack_a the first stack
 * @param stack_b the second stack
 * 
 * @return 0 if the stack is sorted or empty, else the result of the algorithm
 */
__attribute__((hot))
t_error	miracle(t_stack **stack_a, t_stack **stack_b)
{
	(void)stack_b;
	ft_printf("were waiting for the miracle...\n");
	if (is_sorted(*stack_a) || (*stack_a)->size == 0)
	{
		ft_printf("the miracle is here! No, the stack is just already  \
			sorted\n");
		return (0);
	}
	while (!is_sorted(*stack_a))
		;
	ft_printf("wait wait guys, do we just saw a miracle ???\n");
	return (0);
}

#pragma endregion	/* Functions */