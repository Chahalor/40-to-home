/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 08:45:32 by nduvoid           #+#    #+#             */
/*   Updated: 2025/03/20 12:19:07 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_internal/_stack.h"

/**
 * @brief Push the first element of stack_a to the top of stack_b.
 * @todo
*/
__attribute__((hot, leaf))
void	push(t_stack **stack_1, t_stack **stack_2)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		i;
	int		j;

	stack_a = *stack_1;
	stack_b = *stack_2;
	if (stack_a == NULL || stack_b == NULL || stack_a->size < 1
		|| stack_b->size + 1 < stack_b->max_size)
		return ;
	j = -1;
	while (++j < stack_b->size + 1)
		stack_b->array[j + 1] = stack_b->array[j];
	stack_b->array[0] = stack_a->array[0];
	i = -1;
	while (++i < stack_a->size - 1)
		stack_a->array[i] = stack_a->array[i + 1];
	stack_a->size--;
	stack_b->size++;
	return ;
}
