/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _utils.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 08:29:46 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/03 13:50:25 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region "Header"
// System
#include <stdlib.h>

// Global
#include "types.h"

// Modules
#include "_algo.h"
#include "stack.h"

#pragma endregion	/* Header */
#pragma region "Functions"

/**
 * @brief this function is used to get the address of the stack_a and
 * stack_b. It act like a singleton.
 * 
 * @param stack the stack to store
 * @param who the stack to store
 * 
 * @return the address of the stack
 */
__attribute__((hot))
t_stack	**quick_acces(t_stack **stack, const char who)
{
	static t_stack	**stack_a = NULL;
	static t_stack	**stack_b = NULL;

	if (who == 'A')
	{
		if (!stack_a)
			stack_a = stack;
		else
			return (stack_a);
	}
	else if (who == 'B')
	{
		if (!stack_b)
			stack_b = stack;
		else
			return (stack_b);
	}
	else
		return (NULL);
	return (NULL);
}

/**
 * @brief find the cheapest way to push the element at the wanted position
 * 
 * @param pos the current position of the element
 * @param len the length of the stack
 * 
 * @return the cost of the rotation
*/
__attribute__((hot, leaf, pure))
int	get_rotation_cost(const int pos, const int len)
{
	if (pos <= len / 2)
		return (pos);
	return (-(len - pos));
}

#pragma endregion	/* Functions */