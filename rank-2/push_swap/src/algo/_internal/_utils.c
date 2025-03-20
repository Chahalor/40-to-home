/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _utils.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 08:29:46 by nduvoid           #+#    #+#             */
/*   Updated: 2025/03/20 12:46:01 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region "Header"
// System
#include <stdlib.h>

// Global
#include "types.h"

// Modules
	//...

#pragma endregion	/* Header */
#pragma region "Functions"

/** */
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

#pragma endregion	/* Functions */