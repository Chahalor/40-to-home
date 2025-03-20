/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turkish.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 14:27:41 by nduvoid           #+#    #+#             */
/*   Updated: 2025/03/20 12:50:51 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region "Header"
// System
# include <stdlib.h>

// Global
#include "libft.h"

// Modules
#include "stack.h"
#include "_algo.h"
#include "debug.h"

#pragma endregion	/* Header */
#pragma region "Functions"

/** 
 * @todo: rename this function
*/
__attribute__((cold))
static void	quick_sort(t_stack **stack)
{
	(void)stack;
	ft_printf("quick_sort" RED "TODO\n" RESET);
}

__attribute__((hot))
static void	two_to_move(int *a_current, int *b_current,
	const int a_wanted, const int b_wanted) 
{
	static t_stack	**stack_a = NULL;
	static t_stack	**stack_b = NULL;

	ft_printf("  ├──two_to_move\n  | └──");
	(void)a_wanted;	// c est sus sa
	if (__builtin_expect(!stack_a || !stack_b, unexpected))
	{
		stack_a = quick_acces(NULL, 'A');
		stack_b = quick_acces(NULL, 'B');
	}
	if (*a_current > (*stack_a)->size / 2 && b_wanted < (*stack_b)->size / 2 && (*a_current)-- && (*b_current)--)
		interaction(RRR, stack_a, stack_b);
	else if (*a_current < (*stack_a)->size / 2 && b_wanted > (*stack_b)->size / 2 && (++(*a_current), ++(*b_current)))
		interaction(RR + 0 * (++(*a_current), ++(*b_current)), stack_a, stack_b);
	else if (*a_current > (*stack_a)->size / 2 && --(*a_current))
		interaction(RRA, stack_a, stack_b);
	else if (b_wanted < (*stack_b)->size / 2 && ++(*b_current))
		interaction(RB, stack_a, stack_b);
	else if (++(*a_current))
		interaction(RA, stack_a, stack_b);
	if (*a_current > (*stack_a)->size)
		*a_current = 0;
	else if (*a_current < 0)
		*a_current = (*stack_a)->size - 1;
	if (*b_current > (*stack_b)->size)
		*b_current = 0;
	else if (*b_current < 0)
		*b_current = (*stack_b)->size - 1;
}

/** */
__attribute__((hot))
static void a_to_move(int *a_current, const int a_wanted)
{
	static t_stack	**stack_a = NULL;
	static t_stack	**stack_b = NULL;

	ft_printf("  ├──a_to_move\n  | └──");
	if (!*stack_a || !*stack_b)
	{
		stack_a = quick_acces(NULL, 'A');
		stack_b = quick_acces(NULL, 'B');
	}
	if (*a_current > (*stack_a)->size / 2 && a_wanted < (*stack_a)->size / 2)
	{
		interaction(RRA, stack_a, stack_b);
		++(*a_current);
	}
	else if (*a_current < (*stack_a)->size / 2)
	{
		interaction(RA, stack_a, stack_b);
		--(*a_current);
	}
	else
	{
		interaction(RRA, stack_a, stack_b);
		++(*a_current);
	}
	if (*a_current > (*stack_a)->size)
		*a_current = 0;
	else if (*a_current < 0)
		*a_current = (*stack_a)->size - 1;
}

static void b_to_move(int *b_current, const int b_wanted)
{
	static t_stack	**stack_a = NULL;
	static t_stack	**stack_b = NULL;

	ft_printf("  ├──b_to_move.\n  | └──");
	if (__builtin_expect(!stack_a || !stack_b, unexpected))
	{
		stack_a = quick_acces(NULL, 'A');
		stack_b = quick_acces(NULL, 'B');
	}
	if (b_wanted < (*stack_b)->size / 2 && b_wanted < (*stack_b)->size / 2)
		interaction(RB + 0 * ++(*b_current), stack_a, stack_b);
	else if (b_wanted > (*stack_b)->size / 2)
		interaction(RRB + 0 * --(*b_current), stack_a, stack_b);
	else
		interaction(RB + 0 * ++(*b_current), stack_a, stack_b);
}

/** */
__attribute__((hot))
static void	sort_one(t_stack **stack_a, t_stack **stack_b)
{
	const int	a_wanted = 0;
	int			b_wanted;
	int			a_curent_pos;
	int			b_curent_pos;

	a_curent_pos = get_max_pos(*stack_a);
	b_curent_pos = 0;
	b_wanted = get_right_index((*stack_b)->array[b_curent_pos], *stack_b);
	ft_printf("a_curent_pos: %d, a_wanted= %d, b_current = %d, b_wanted = %d\n", a_curent_pos, a_wanted, b_curent_pos, b_wanted);	// rm
	print_stack(*stack_a);	// rm
	print_stack(*stack_b);	// rm
	while (a_curent_pos != a_wanted || b_curent_pos != b_wanted)
	{
		if (a_curent_pos != a_wanted && b_curent_pos != b_wanted)
			two_to_move(&a_curent_pos, &b_curent_pos, a_wanted, b_wanted);
		else if (a_curent_pos != a_wanted)
			a_to_move(&a_curent_pos, a_wanted);
		else
			b_to_move(&b_curent_pos, b_wanted);
	}
}

/** */
__attribute__((hot))
int	_turkish(t_stack **stack_a, t_stack **stack_b)
{
	if (is_sorted(*stack_a))
		return (0);
	quick_acces(stack_a, 'A');
	quick_acces(stack_b, 'B');
	interaction(PB, stack_a, stack_b);
	interaction(PB, stack_a, stack_b);
	while (!is_sorted(*stack_a) && (*stack_a)->size > 0)
		sort_one(stack_a, stack_b);
	ft_printf("after sort_one\n");		// rm
	quick_sort(stack_b);
	ft_printf("after quick_sort\n");	// rm
	while ((*stack_b)->size > 0)
		interaction(PA, stack_a, stack_b);
	return (0);
}

#pragma endregion	/* Functions */