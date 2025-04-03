/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 08:35:16 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/03 13:54:56 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_internal/_stack.h"

/**
 * * @brief Swap the first two elements of the stack.
 * 
 * * @param stackp The stack to swap.
 * 
 * * @return 1 if the stack was swapped, 0 otherwise.
 */
__attribute__((hot, leaf))
int	swap(t_stack **stackp)
{
	register t_nb	tmp;

	if (!stackp || !*stackp || (*stackp)->size < 2)
		return (0);
	tmp = (*stackp)->array[0];
	(*stackp)->array[0] = (*stackp)->array[1];
	(*stackp)->array[1] = tmp;
	return (1);
}

/**
 * @brief Swap the first two elements of both stacks.
 * 
 * @param stack_a The first stack.
 * @param stack_b The second stack.
 * 
 * @return 1 if the stacks were swapped, 0 otherwise.
*/
__attribute__((hot))
int	swap_both(t_stack **stack_a, t_stack **stack_b)
{
	return (swap(stack_a) || swap(stack_b));
}
