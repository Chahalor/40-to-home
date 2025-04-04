/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 08:34:20 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/04 13:31:47 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region "Header"
// System
#include <stdbool.h>
#include <stdlib.h>
// #include "libft.h"

// Global
//...

// Modules
#include "stack.h"
#include "parsing.h"
#include "sorting.h"
#include "utils.h"
#include "libft.h"
#include "debug.h"

#pragma endregion	/* Header */
#pragma region "Functions"

/**
 * @author nduvoid <nduvoid@student.42mulhouse.fr>
 * @date 2025/03/28
 * @details: this program is part of the 42 cursus.
 * 
 * @brief This Program is a tester for the push_swap program. It reads the
 * instructions from the standard input and applies them to the stacks.
 * It print OK if the stacks are sorted and KO if they are not.
 */
int	main(int argc, const char *argv[])
{
	const t_args	args = parse_args(argc, argv);
	t_stack			*stack_a;
	t_stack			*stack_b;
	t_instruct		*inst;

	if (args.error)
		exiting(args.error, RED "Error" RESET ": while parsing args");
	else if (args.len_stack == 0 && !args.stack)
		exiting(20, RED "Error" RESET ": no args to sort");
	stack_a = args_to_stack('A', &args);
	stack_b = new('B', args.len_stack);
	if (!stack_a || !stack_b)
	{
		destroyer(stack_a);
		destroyer(stack_b);
		exiting(21, RED "Error" RESET ": while creating stacks" );
	}
	inst = read_instructions();
	if (!inst)
	{
		destroyer(stack_a);
		destroyer(stack_b);
		exiting(22, RED "Error" RESET ": while reading instructions");
	}
	return (do_test(stack_a, stack_b, inst));
}

#pragma endregion	/* Functions */