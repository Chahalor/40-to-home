/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 08:39:16 by nduvoid           #+#    #+#             */
/*   Updated: 2025/03/31 10:21:53 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_internal/_stack.h"

/**
 * @brief	Rotate the stack to the top. The first element becomes the last one.
 * 
 * @param	stackp	The stack to rotate.
 * 
 * @return	void
 */
__attribute__((hot))
void	rotate(t_stack **stackp)
{
	t_nb	tmp;

	if (!stackp || !*stackp || (*stackp)->size < 2)
		return ;
	tmp = (*stackp)->array[0];
	ft_memmove(&(*stackp)->array[0], &(*stackp)->array[1], ((*stackp)->size - 1)
		* sizeof(t_nb));
	(*stackp)->array[(*stackp)->size - 1] = tmp;
}

/**
 * @brief	Reverse rotate the stack to the top. The last element becomes the
 * first one.
 * 
 * @param	stackp	The stack to reverse rotate.
 * 
 * @return	void
 */
__attribute__((hot))
void	reverse_rotate(t_stack **stackp)
{
	t_nb	tmp;

	if (!stackp || !*stackp || (*stackp)->size < 2)
		return ;
	tmp = (*stackp)->array[(*stackp)->size - 1];
	ft_memmove(&(*stackp)->array[1], &(*stackp)->array[0], ((*stackp)->size - 1)
		* sizeof(t_nb));
	(*stackp)->array[0] = tmp;
}

/**
 * @brief	Swap the first two elements of the stack.
 * 
 * @param	stackp	The stack to swap.
 * 
 * @return	void
*/
__attribute__((hot))
void	rotate_both(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
}

/**
 * @brief	Swap the first two elements of the stack.
 * 
 * @param	stackp	The stack to swap.
 * 
 * @return	void
*/
__attribute__((hot))
void	reverse_rotate_both(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
}
