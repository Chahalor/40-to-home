/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _sorting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 08:52:36 by nduvoid           #+#    #+#             */
/*   Updated: 2025/03/31 10:15:33 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region "Header"
// System
	//...

// Global
#include "libft.h"

// Modules
#include "_sorting.h"
#include "utils.h"

#pragma endregion	/* Header */
#pragma region "Functions"

/**
 * @brief	Converts a string to an instruction.
 * 
 * @param	s	The string to convert.
 * 
 * @return	The instruction corresponding to the string.
 */
__attribute__((hot, pure))
t_instruct	str_to_instruction(const char *s)
{
	static const char	*list_inst[] = {"pa\n", "pb\n", "sa\n", "sb\n", "ss\n",
		"rb\n", "ra\n", "rr\n", "rra\n", "rrb\n", "rrr\n", "sort\n", "none\n"};
	int					i;

	if (__builtin_expect(!s, unexpected))
		return (NONE);
	i = -1;
	while (++i < 11)
		if (ft_strncmp(s, list_inst[i], 3 + (i > 7)) == 0)
			return (i);
	return (NONE);
}

#pragma endregion	/* Functions */