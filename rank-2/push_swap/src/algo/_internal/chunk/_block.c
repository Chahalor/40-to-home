/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _block.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 10:28:19 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/03 13:45:38 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region "Header"
// System
	//...

// Global
	//...

// Modules
#include "_chunk.h"

#pragma endregion	/* Header */
#pragma region "Functions"

/**
 * @brief this function is used to calculate the size of the block
 * 
 * @param len the length of the stack
 * 
 * @return the size of the block
 */
__attribute__((always_inline, used))
unsigned int	_block_size(const unsigned int len)
{
	return (25 + len / 20);
}

/**
 * @brief this function is used to move a element of the actual block to the top
 * of the stack
 * 
 * @param stack the first stack
 * @param stack_b the second stack
 * @param start the start of the block
 * @param end the end of the block
 * 
 * @return 1 if the block is not empty, else 0
 */
__attribute__((hot))
unsigned char	_block(t_stack **stack, t_stack **stack_b, const int start,
	const int end)
{
	register int	i;

	i = -1;
	while (++i != (*stack)->size)
		if ((*stack)->array[i].index >= start && (*stack)->array[i].index < end)
			break ;
	if (i == (*stack)->size)
		return (0);
	if (i < (*stack)->size / 2)
		while (i-- > 0)
			interaction(RA, stack, stack_b);
	else
		while (((*stack)->size - i++) > 0)
			interaction(RRA, stack, stack_b);
	return (1);
}

#pragma endregion	/* Functions */