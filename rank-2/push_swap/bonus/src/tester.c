/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 08:34:20 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/01 16:39:52 by nduvoid          ###   ########.fr       */
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

#pragma endregion	/* Header */
#pragma region "Functions"

int	main(int argc, const char *argv[])
{
	const t_args	args = parse_args(argc, argv);
	t_stack			*stack_a;
	t_stack			*stack_b;
	t_instruct		*inst;

	if (args.error)
		exiting(args.error, RED "Error" RESET ": while parsing args");
	stack_a = args_to_stack('A', &args);
	stack_b = new('B', stack_a->max_size);
	inst = read_instructions();
	if (!stack_a || !stack_b || !inst)
	{
		destroyer(stack_a);
		destroyer(stack_b);
		exiting(21, RED "Error" RESET ": while creating stacks" );
	}
	return (do_test(stack_a, stack_b, inst));
}

#pragma endregion	/* Functions */