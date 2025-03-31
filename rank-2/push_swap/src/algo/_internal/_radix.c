/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _radix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 13:06:34 by nduvoid           #+#    #+#             */
/*   Updated: 2025/03/31 13:12:55 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region "Header"
// System
# include <stdlib.h>

// Global
#include "libft.h"

// Modules
#include "stack.h"
#include "_algo.h"
#include "debug.h"

#pragma endregion	/* Header */
#pragma region "Functions"


/** */
__attribute__((cold))
int	_radix(t_stack **stack_a, t_stack **stack_b)
{
	int	mask;

	mask = 0b1;
	while (mask < (*stack_a)->max_size)
	{
		if ((*stack_a)->array[0].index & mask)
			interaction(RA, stack_a, stack_b);
		else
			interaction(PB, stack_a, stack_b);
		mask *= 10;
	}
	return (0);
}

#pragma endregion	/* Functions */