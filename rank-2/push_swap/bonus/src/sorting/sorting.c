/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 08:43:16 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/03 15:22:09 by nduvoid          ###   ########.fr       */
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

/**
 * * @brief	Exits the program with an error message.
 * 
 * * @param	line	The line to free.
 * * @param	inst	The instructions to free.
 * * @param	msg	The error message to print.
 * 
 * * * @return	void
 */
__attribute__((cold, used, always_inline))
void inline	exit_error(char *line, t_instruct *inst, const char *msg)
{
	ft_printf(RED "Error" RESET ": %s\n└── %s", msg, line);
	if (line)
		free(line);
	if (inst)
		free(inst);
	exiting(22, NULL);
}

/**
 * * @brief	Reads the instructions from the standard input.
 *
 * * @param	void
 * 
 * * @return	The instructions read from the standard input.
 */
__attribute__((cold, malloc))
t_instruct	*read_instructions(void)
{
	t_instruct	*inst;
	char		*line;
	int			i;
	int			nb_alloc;

	inst = (t_instruct *)mallocing(sizeof(t_instruct) * 64);
	line = get_next_line(STDIN_FILENO);
	nb_alloc = 1;
	i = -1;
	while (line)
	{
		inst[++i] = str_to_instruction(line);
		if (inst[i] == NONE)
			exit_error(line, inst, "invalide instruction");
		if (i == nb_alloc * 64 - 1)
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

/**
 * @brief	Executes the instructions on the stacks and checks if the
 * stacks are sorted.
 * 
 * @param	stack_a	The first stack.
 * @param	stack_b	The second stack.
 * @param	instruct	The instructions to execute.
 * 
 * @return	0 if the stacks are sorted, 1 otherwise.
*/
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