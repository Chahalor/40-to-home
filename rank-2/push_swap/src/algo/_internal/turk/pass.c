/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pass.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 09:30:39 by mjuncker          #+#    #+#             */
/*   Updated: 2025/04/01 15:40:57 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_turk.h"

/** */
__attribute__((cold))
void	final_pass(t_stack **a, t_stack **b)
{
	const int			min_pos = get_min_pos(*a);
	const t_nb			min = (*a)->array[min_pos];
	const t_instruct	inst = RA + 2 * (min_pos > (*a)->size / 2);
	int					i;

	print_debug("final_pass()");
	while ((*b)->size > 0)
		interaction(PA, a, b);
	print_debug("after PA()");
	i = -1;
	while ((*a)->array[0].value != min.value)
	{
		// ft_printf("min_pos = %d, i=%d, min.value=%d\n", min_pos, i,
		// 	min.value);
		interaction(inst, a, b);
	}
}

/** */
__attribute__((hot))
void	exec_set(t_stack **a, t_stack **b, t_inst_set set)
{
	while (set.ra != 0 || set.rb != 0 || set.rr != 0)
	{
		print_debug("loop of the hell");
		if (set.rr)
			interaction(RR + 3 * (set.ra > 0), a, b);
		if (set.ra)
			interaction(RA + 2 * (set.ra > 0), a, b);
		if (set.rb)
			interaction(RB + 4 * (set.rb > 0), a, b);
		set = (t_inst_set){
			.ra = set.ra - (set.ra > 0) + (set.ra < 0),
			.rb = set.rb - (set.rb > 0) + (set.rb < 0),
			.rr = set.rr - (set.rr > 0) + (set.rr < 0),
			.weight = set.weight
		};
	}
}

/** */
__attribute__((hot))
int	pass(t_stack **a, t_stack **b, const int original_size)
{
	if ((*b)->size == 0)
	{
		interaction(PB, a, b);
		interaction(PB, a, b);
	}
	if (original_size < REVERSE_MAX && (*a)->size == 3)
		return (sort_a(a, b), 0);
	exec_set(a, b, get_best_set(a, b));
	print_debug("after exec_set()");	// rm
	interaction(PA, a, b);
	if ((*b)->size == 0)
		return (0);
	return (1);
}
