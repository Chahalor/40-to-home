/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 10:11:51 by nduvoid           #+#    #+#             */
/*   Updated: 2025/03/18 15:55:02 by nduvoid          ###   ########.fr       */
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

/** */
int	main(int argc, const char *argv[])
{
	const t_args	args = parse_args(argc, argv);
	t_error		(*const algo[])(t_stack *, t_stack *) = {
		[e_turkish] = turkish,
		[e_random] = mein_random,
		[e_miracle] = miracle
	};
	t_stack			*stack_a;
	t_stack			*stack_b;

	if (args.error)
		exiting(args.error, "Error: invalid argument");
	print_args(&args);
	stack_a = args_to_stack('A', &args);
	stack_b = new('B', stack_a->max_size);
	print_stack(stack_a);
	print_stack(stack_b);
	if (!stack_a || !stack_b)
	{
		destroyer(stack_a);
		destroyer(stack_b);
		exiting(malloc_failed, "Error: malloc failed");
	}
	return (algo[args.algo](stack_a, stack_b));
}

#pragma endregion	/* Functions */