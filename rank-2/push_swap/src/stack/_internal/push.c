/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 08:45:32 by nduvoid           #+#    #+#             */
/*   Updated: 2025/03/17 09:09:44 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_internal/_stack.h"

/**
 * @brief Push the first element of stack_a to the top of stack_b.
 * @todo
*/
__attribute__((hot, leaf))
void	push(t_stack *stack_a, t_stack *stack_b)
{
	register t_nb	tmp;

	if (stack_a == NULL || stack_b == NULL || stack_a->size < 1)
		return ;
	tmp = stack_a->array[0];
	stack_a->size--;
	stack_b->size++;
	stack_b->array[stack_b->size - 1] = tmp;
	rotate(stack_a);
	rotate(stack_b);
}
