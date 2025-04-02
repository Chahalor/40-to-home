/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _block.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 10:28:19 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/02 17:12:50 by nduvoid          ###   ########.fr       */
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

__attribute__((always_inline, used))
unsigned int	_block_size(const unsigned int len)
{
	if (len <= 100)
		return (25);
	else if (len <= 250)
		return (30);
	else if (len <= 350)
		return (35);
	else if (len <= 450)
		return (40);
	else
		return (55);
}

__attribute__((hot))
unsigned char	_block(t_stack **stack, t_stack **stack_b, const int start,
	const int end)
{
	register int	i;

	i = -1;
	while (++i != (*stack)->size)
		if ((*stack)->array[i].value >= start && (*stack)->array[i].value < end)
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