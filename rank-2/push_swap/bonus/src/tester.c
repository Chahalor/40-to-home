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

/**
 * @brief main function of the tester
 * 
 * - in the case where the -f flag is present and read file is allow, 
 * the program will read the instructions from the file
 * 
 * @example ./tester -f file_name <stack_a>
 * @example ./tester <stack_a> & instruction in the stdin
 * 
 * @param argc: number of arguments
 * @param argv: arguments
 * @return 
 * 
 * - 0 if the program ends correctly
 * 
 * - 2 if an non-valide args is given
 * 
 * - 3 if an error occurs during the reading of the instructions
 * 
 * - 4 if an error occurs during the allocation of memory
 * 
 * - 5 if an error occurs during the reading of the file
*/
int	main(int argc, const char *argv[])
{
	t_stack	*stacks;
	char	**instructions;
	int		fd;

	if (ft_strcmp(argv[1], "-f") == 0 && argc > 3)
	{
		fd = open(argv[2], O_RDONLY);
		stacks = init_all(argc - 2, argv + 2);
		instructions = read_instructions(fd);
	}
	else
	{
		fd = -1;
		stacks = init_all(argc, argv);
		instructions = read_instructions(0);
	}
	if (!instructions)
	{
		write(2, "Error\n", 6);
		return (free(stacks), MALLOC_ERROR);
	}
	testing(stacks, instructions);
	close(fd);
	return (free(stacks), free_instructions(instructions), GOOD);
}

#else

/**
 * @brief main function of the tester
 * - in this case, ALLOW_FILE is set to 0, the program will read 
 * the instructions from the stdin
 * 
 * @example ./tester <stack_a> & instruction in the stdin
 * @example ./tester 1 5 3 && rra sa ^D >> "OK\n"
 * 
 * @param argc: number of arguments
 * @param argv: arguments
 * @return
 * 
 * - 0 if the program ends correctly
 * 
 * - 2 if an non-valide args is given
 * 
 * - 3 if an error occurs during the reading of the instructions
 * 
 * - 4 if an error occurs during the allocation of memory
 * 
 * - 5 if an error occurs during the reading of the file
 */
int	main(int argc, const char **argv)
{
	t_stack	*stacks;
	char	**instructions;

	stacks = init_all(argc, argv);
	instructions = read_instructions(0);
	if (!instructions)
	{
		write(2, "Error\n", 6);
		return (free(stacks), MALLOC_ERROR);
	}
	testing(stacks, instructions);
	free(stacks);
	free_instructions(instructions);
	return (GOOD);
}

#endif

/**
 * @brief read the instructions inside the file Descriptor using GNL
 * 
 * - the function read the instructions line by line
 * 
 * - the function break when it read a new line (two consecutive presse on ENTER)
 * 
 * @param fd: file descriptor
 * @return
 * 
 * - char**: the instructions
 * 
 * - NULL if what read is not an instruction
 */
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

/**
 * @brief test the instructions
 * 
 * - the function will execute the instructions one by one
 * 
 * - if the stack_b is not empty or the stack_a is not sorted, 
 * the function will print "KO\n" and return False
 * 
 * - else the function will print "OK\n" and return True
 * 
 * @param stacks: the two stacks and their sizes 
 * @param instructs: the instructions
 * @return
 * 
 * - TRUE if the stack_a is sorted and the stack_b is empty
 * 
 * - FALSE if the stack_a is not sorted or the stack_b is not empty
 */
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
	if (stacks->size_b <= 0 || !is_sorted(stacks->stack_a, stacks->size_a))
	{
		write(1, "KO\n", 3);
		return (FALSE);
	}
	write(1, "KO\n", 3);
	return (TRUE);
}
