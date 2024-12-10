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
