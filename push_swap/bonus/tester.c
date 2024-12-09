/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 09:53:45 by nduvoid           #+#    #+#             */
/*   Updated: 2024/12/09 09:53:45 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

t_stack	*init_stacks(int argc, char **argv)
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
			exit(ARG_ERROR);
		}
		stacks->stack_a[i - 1] = ft_atoi(argv[i]);
	}
	return (stacks);
}

char	**read_instructions(int fd)
{
	char	*line;
	char	**instructions;
	int		size;
	int		i;

	size = 2;
	instructions = (char **)ft_calloc(size, sizeof(char *));
	if (!instructions)
		exit(MALLOC_ERROR);
	line = get_next_line(fd);
	i = 0;
	while (line)
	{
		instructions[i++] = line;
		if (i == size)
		{
			size *= 2;
			instructions = (char **)ft_calloc(size, sizeof(char *));
			if (!instructions)
				exit(MALLOC_ERROR);
		}
	}
}


int	main(int argc, char **argv)
{
	t_stack	*stacks;
	char	**instructions;

	stacks = init_stacks(argc, argv);
	instructions = read_instructions(0);
	if (!instructions)
	{
		write(2, "Error\n", 6);
		return (free(stacks->stack_a), free(stacks->stack_b), MALLOC_ERROR);
	}
	if (testing(stacks->stack_a, stacks->stack_b, instructions))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free(stacks->stack_a);
	free(stacks->stack_b);
	free(instructions);
	return (GOOD);
}
