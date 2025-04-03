/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 08:39:16 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/03 13:54:21 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_internal/_stack.h"

/**
 * @brief Rotate the stack by moving the first element to the end of the
 *  stack.
 * 
 * @param stackp The stack to rotate.
 * 
 * @return 1 if the stack was rotated, 0 otherwise.
 */
__attribute__((hot))
int	rotate(t_stack **stackp)
{
	t_nb	tmp;

	if (!stackp || !*stackp || (*stackp)->size < 2)
		return (0);
	tmp = (*stackp)->array[0];
	ft_memmove(&(*stackp)->array[0], &(*stackp)->array[1], ((*stackp)->size - 1)
		* sizeof(t_nb));
	(*stackp)->array[(*stackp)->size - 1] = tmp;
	return (1);
}

/**
 * @brief Rotate the stack by moving the last element to the top of the stack.
 * 
 * @param stackp The stack to rotate.
 * 
 * @return 1 if the stack was rotated, 0 otherwise.
 */
__attribute__((hot))
int	reverse_rotate(t_stack **stackp)
{
	t_nb	tmp;

	if (!stackp || !*stackp || (*stackp)->size < 2)
		return (0);
	tmp = (*stackp)->array[(*stackp)->size - 1];
	ft_memmove(&(*stackp)->array[1], &(*stackp)->array[0], ((*stackp)->size - 1)
		* sizeof(t_nb));
	(*stackp)->array[0] = tmp;
	return (1);
}

/**
 * @brief Rotate both stacks by moving the first element of each stack to
 * the end of the stack.
 * 
 * @param stack_a The first stack to rotate.
 * @param stack_b The second stack to rotate.
 * 
 * @return 1 if at least one stack was rotated, 0 otherwise.
 */
__attribute__((hot))
int	rotate_both(t_stack **stack_a, t_stack **stack_b)
{
	return (rotate(stack_a) || rotate(stack_b));
}

/**
 * @brief Reverse rotate both stacks by moving the last element of each
 * stack to the top of the stack.
 * 
 * @param stack_a The first stack to reverse rotate.
 * @param stack_b The second stack to reverse rotate.
 * 
 * @return 1 if at least one stack was reverse rotated, 0 otherwise.
*/
__attribute__((hot))
int	reverse_rotate_both(t_stack **stack_a, t_stack **stack_b)
{
	return (reverse_rotate(stack_a) || reverse_rotate(stack_b));
}
