/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _turk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 12:48:09 by mjuncker          #+#    #+#             */
/*   Updated: 2025/04/01 15:35:41 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stack.h"
#include "utils.h"
#include "parsing.h"
#include "debug.h"
#include "_turk.h"

/** */
__attribute__((always_inline, cold, used))
inline void	sort_3(t_stack **stack_a, t_stack **stack_b)
{
	const int			top = (*stack_a)->array[0].value;
	const int			mid = (*stack_a)->array[1].value;
	const int			bot = (*stack_a)->array[2].value;
	const int			swap = ((top > mid) << 2) | ((mid > bot) << 1)
		| (top > bot);
	const t_instruct	moves[8][2] = {{NONE, NONE}, {SA, NONE}, {RRA, SA},
		{RRA, NONE}, {SA, NONE}, {RA, NONE}, {RRA, NONE}, {SA, RRA}};
	interaction(moves[swap][0], stack_a, stack_b);
	interaction(moves[swap][1], stack_a, stack_b);
}

void	end(t_stack *a, t_stack *b)
{
	if (a)
		destroyer(a);
	if (b)
		destroyer(b);
	exit(0);
}
/** */
__attribute__((cold))
int	_turk(t_stack **a, t_stack **b)
{
	if ((*a)->size <= 3)
		return (sort_3(a, b), 1);
	print_debug("after sort_3()");
	while (pass(a, b, (*a)->size))
		; // print_stack(*a);
	print_debug("after pass()");
	final_pass(a, b);
	print_debug("after final_pass()");
	return (0);
}
