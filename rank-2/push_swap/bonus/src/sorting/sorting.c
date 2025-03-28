/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 08:43:16 by nduvoid           #+#    #+#             */
/*   Updated: 2025/03/28 15:33:02 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region "Header"
// System
	//...

// Global
	//...

// Modules
#include "stack.h"
#include "_sorting.h"
#include "utils.h"
#include "libft.h"
#include "debug.h"

#pragma endregion	/* Header */
#pragma region "Functions"

/** */
__attribute__((cold, malloc))
t_instruct	*read_instructions(void)
{
	t_instruct	*inst;
	char		*line;
	int			i;
	int			nb_alloc;

	inst = malloc(sizeof(t_instruct) * 64);
	if (!inst)
		return (NULL);
	line = get_next_line(STDIN_FILENO);
	nb_alloc = 0;
	i = -1;
	while (line)
	{
		inst[++i] = str_to_instruction(line);
		if (inst[i] == NONE)
		{
			ft_printf("instruction: %s\n", line);
			free(line);
			free(inst);
			exiting(22, RED "Error" RESET ": invalid instruction");
		}
		if (i == nb_alloc * 64)
		{
			inst = reallocing(inst, sizeof(t_instruct) * nb_alloc * 64,
				sizeof(t_instruct) * (nb_alloc + 1) * 64);
			++nb_alloc;
		}
		free(line);
		line = get_next_line(STDIN_FILENO);
	}
	inst[++i] = NONE;
	return (inst);
}
/** */
__attribute__((cold))
int	do_test(t_stack *stack_a, t_stack *stack_b, t_instruct *instruct)
{
	int		i;

	i = -1;
	while (instruct[++i] != NONE)
		interaction(instruct[i], &stack_a, &stack_b);
	if (is_sorted(stack_a) && stack_b->size == 0)
		ft_printf(GREEN "OK\n" RESET);
	else
		ft_printf(RED "KO\n" RESET);
	print_stack(stack_a);
	print_stack(stack_b);
	destroyer(stack_a);
	destroyer(stack_b);
	free(instruct);
	return (0);
}

#pragma endregion	/* Functions */