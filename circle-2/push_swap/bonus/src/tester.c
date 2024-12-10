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

#include "../header/tester.h"

#if ALLOW_FILE == 1
# include <fcntl.h>

int	main(int argc, const char *argv[])
{
	t_stack	*stacks;
	char	**instructions;

	if (ft_strcmp(argv[1], "-f") == 0 && argc > 3)
	{
		stacks = init_stacks(argc - 2, argv + 2);
		instructions = read_instructions(open(argv[2], O_RDONLY));
	}
	else
	{
		stacks = init_stacks(argc, argv);
		instructions = read_instructions(0);
	}
	if (!instructions)
	{
		write(2, "Error\n", 6);
		return (free(stacks), MALLOC_ERROR);
	}
	if (testing(stacks, instructions))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free(stacks);
	free_instructions(instructions);
	return (GOOD);
}

#else

int	main(int argc, char **argv)
{
	t_stack	*stacks;
	char	**instructions;

	stacks = init_stacks(argc, argv);
	instructions = read_instructions(0);
	if (!instructions)
	{
		write(2, "Error\n", 6);
		return (free(stacks), MALLOC_ERROR);
	}
	if (testing(stacks, instructions))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free(stacks);
	free_instructions(instructions);
	return (GOOD);
}

#endif

char	**read_instructions(int fd)
{
	int		size;
	char	**instructions;
	char	*line;
	int		i;

	size = 2;
	instructions = (char **)ft_calloc(size, sizeof(char *));
	instructions[size - 1] = NULL;
	if (!instructions)
		exit(MALLOC_ERROR);
	line = get_next_line(fd);
	i = 0;
	while (line && line[0] != '\n')
	{
		if (!is_instruction(line))
			return (free_instructions(instructions), free(line), NULL);
		instructions[i++] = line;
		if (i == size)
		{
			size += 1;
			instructions = extand_instruct(instructions, size);
		}
		line = get_next_line(fd);
	}
	return (free(line), instructions);
}

t_bool	testing(t_stack *stacks, char **instructs)
{
	int	i;

	i = 0;
	while (instructs[i])
	{
		do_instructions(stacks, instructs[i]);
		free(instructs[i]);
		instructs[i] = NULL;
		i++;
	}
	if (stacks->size_b || !is_sorted(stacks->stack_a, stacks->size_a))
		return (FALSE);
	return (TRUE);
}
