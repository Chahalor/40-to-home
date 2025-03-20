/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 10:11:51 by nduvoid           #+#    #+#             */
/*   Updated: 2025/03/20 13:32:19 by nduvoid          ###   ########.fr       */
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
#include "vizualizer.h"
#include "utils.h"
#include "debug.h"

#pragma endregion	/* Header */
#pragma region "Functions"

/** */
int	main(int argc, const char *argv[])
{
	const t_args	args = parse_args(argc, argv);
	t_error		(*const algo[])(t_stack **, t_stack **) = {
		[e_turkish] = turkish,
		[e_random] = mein_random,
		[e_miracle] = miracle
	};
	t_stack			*stack_a;
	t_stack			*stack_b;

	if (args.error)
		exiting(args.error, "Error: invalid argument");
	stack_a = args_to_stack('A', &args);
	stack_b = new('B', stack_a->max_size);
	// print_stack(stack_a);	// rm
	// print_stack(stack_b);	// rm
	if (!stack_a || !stack_b)
	{
		destroyer(stack_a);
		destroyer(stack_b);
		exiting(malloc_failed, "Error: malloc failed");
	}
	(void)algo[args.algo];
	interaction(PB, &stack_a, &stack_b);	//rm
	// algo[args.algo](&stack_a, &stack_b);
	show_stacks(stack_a, stack_b);
	stack_a = destroyer(stack_a);
	stack_b = destroyer(stack_b);
	return (succes);
}

#pragma endregion	/* Functions */