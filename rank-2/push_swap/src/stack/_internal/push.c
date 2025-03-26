/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 08:45:32 by nduvoid           #+#    #+#             */
/*   Updated: 2025/03/26 13:54:12 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_internal/_stack.h"

/**
 * @brief Push the first element of stack_1 to the top of stack_2.
 * 
 * @param stack_1 The first stack.
 * @param stack_2 The second stack.
 * 
 * @return void
 * 
 * @note The function will not do anything if stack_1 is empty
 *  or if stack_2 is full.
*/
__attribute__((hot))
void push(t_stack **stack_1, t_stack **stack_2)
{
	if (!stack_1 || !stack_2 || !(*stack_1) || !(*stack_2))
		return ;
	if ((*stack_1)->size < 1 || (*stack_2)->size >= (*stack_2)->max_size)
		return ;
	if ((*stack_2)->size > 0)
		ft_memmove(&(*stack_2)->array[1], &(*stack_2)->array[0], (*stack_2)->size * sizeof(t_nb));
	(*stack_2)->array[0] = (*stack_1)->array[0];
	if ((*stack_1)->size > 1)
		ft_memmove(&(*stack_1)->array[0], &(*stack_1)->array[1], ((*stack_1)->size - 1) * sizeof(t_nb));
	(*stack_1)->size--;
	(*stack_2)->size++;
}
