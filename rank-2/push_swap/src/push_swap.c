/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 10:11:51 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/04 12:59:03 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region "Header"

// Global
#include "types.h"
#include "config.h"
#include "libft.h"

// Modules
#include "parsing.h"
#include "stack.h"
#include "algo.h"
#include "utils.h"
#include "debug.h"

#pragma endregion	/* Header */
#pragma region "Functions"

/**
 * @author nduvoid <nduvoid@student.42mulhouse.fr>
 * @date 2025/03/13
 * @details: this program is part of the 42 cursus.
 * 
 * @brief The push_swap programis a sorting algorithm that sorts a stack of
 * integers using a series of operations. The Goal of the program is to sort
 * the stack in ascending order using the fewest number of operations possible.
 * 
 * This Program has 4 algorithms built in:
 * 
 * 1. Chunk: This algorithm sorts the stack using a series of chunks. It is
 *   the most efficient algorithm for sorting large stacks.
 * 
 * 2. Simple: This algorithm sorts the stack using a simple sorting algorithm.
 * 
 * 3. Random: This algorithm sorts the stack using a random sorting algorithm.
 * 
 * 4. Miracle: This algorithm wait a miracle to sort the stack.
 */
int	main(int argc, const char *argv[])
{
	const t_args	args = parse_args(argc, argv);
	t_stack			*stack_a;
	t_stack			*stack_b;

	t_error (*const algo[])(t_stack **, t_stack **) = {
[e_turkish] = turkish,
[e_chunk] = chunk_noris,
[e_random] = mein_random,
[e_miracle] = miracle
};
	if (args.error)
		exiting(args.error, "Error: invalid argument");
	stack_a = args_to_stack('A', &args);
	stack_b = new('B', stack_a->max_size);
	if (!stack_a || !stack_b)
	{
		destroyer(stack_a);
		destroyer(stack_b);
		exiting(malloc_failed, "Error: malloc failed");
	}
	algo[args.algo](&stack_a, &stack_b);
	stack_a = destroyer(stack_a);
	stack_b = destroyer(stack_b);
	return (succes);
}

#pragma endregion	/* Functions */