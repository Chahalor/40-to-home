/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 15:43:22 by nduvoid           #+#    #+#             */
/*   Updated: 2024/12/09 15:43:22 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/tester.h"

/**
 * @brief initialize the stacks
 * 
 * - use an contiguous memory allocation to store the two stacks
 * so we can free them in one time
 * 
 * - for each argument, we check if it's a digit
 * if not we free the memory and exit with an error
 * 
 * @param argc: number of arguments
 * @param argv: arguments
 * @return 
 * 
 * - t_stack*: the two stacks and their sizes
 * 
 * - NULL if an error occurs (malloc)
 * 
 * - exit with an error if an argument is not a digit
 */
t_stack	*init_stacks(int argc, const char **argv)
{
	t_stack	*stacks;
	int		i;

	stacks = (t_stack *)ft_calloc(sizeof(t_stack) + sizeof(int *) + sizeof(int),
			2 * argc + 2);
	if (!stacks)
		exit(MALLOC_ERROR);
	stacks->stack_a = (int *)(stacks + 1);
	stacks->stack_b = stacks->stack_a + argc;
	stacks->size_a = argc - 1;
	stacks->size_b = 0;
	i = 0;
	while (++i < argc)
	{
		if (!is_digits(argv[i]))
		{
			free(stacks);
			write(2, "Error\n", 6);
			exit(ARG_ERROR);
		}
		stacks->stack_a[i - 1] = ft_atoi(argv[i]);
	}
	return (stacks);
}

/**
 * @brief check if the stack is sorted in ascending order
 * 
 * @example 1 2 3 4 5 => TRUE
 * @example 1 2 3 5 4 => FALSE
 * 
 * @param stack: the stack
 * @param size: the size of the stack
 * @return
 * 
 * - TRUE if the stack is sorted
 * 
 * - FALSE if the stack is not sorted
 */
t_bool	is_sorted(int *stack, int size)
{
	int	i;

	i = 0;
	while (++i < size)
	{
		if (stack[i - 1] > stack[i])
			return (FALSE);
	}
	return (TRUE);
}
