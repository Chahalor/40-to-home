/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 12:57:37 by mjuncker          #+#    #+#             */
/*   Updated: 2025/04/01 11:53:12 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_turk.h"

/** */
__attribute__((leaf))
int	get_rb_inner(t_stack *b, const int elt)
{
	int	tmp;
	int	rb;
	int	i;

	rb = 0;
	tmp = b->array[0].value;//ft_atoi(ft_lstlast(b)->content);
	i = 1;
	while (i > 0)
	{
		if (tmp < elt && b->array[i].value > elt)
			break ;
		++rb;
		tmp = b->array[i].value;
		i += (i < b->size) - i * (i >= b->size);
	}
	if (rb > b->size / 2)
		rb = (b->size - rb) * -1;
	return (rb);
}

int	get_rb(t_stack *b, const int elt)
{
	const int	min_pos = get_min_pos(b);
	const int	min = b->array[min_pos].value;
	const int	max_pos = get_max_pos(b);
	const int	max = b->array[max_pos].value;

	if (min > elt)
		return ((min_pos > b->size / 2) * ((b->size - min_pos - 1) * -1) +
				!(min_pos > b->size / 2) * (min_pos + 1));
	else if (max < elt)
		return ((max_pos > b->size / 2) * ((b->size - max_pos - 1) * -1) +
				!(max_pos > b->size / 2) * (max_pos + 1));
	else
		return (get_rb_inner(b, elt));
}

t_inst_set	get_rr(t_inst_set set)
{
	int	tmp;

	if (set.rb > 0 && set.ra > 0)
	{
		tmp = min(set.ra, set.rb);
		set.rr = tmp;
		set.ra -= tmp;
		set.rb -= tmp;
	}
	if (set.ra < 0 && set.rb < 0)
	{
		tmp = max(set.ra, set.rb);
		set.rr = tmp;
		set.ra -= tmp;
		set.rb -= tmp;
	}
	return (set);
}

t_inst_set	get_instruction_set(t_stack *a, t_stack *b, const int idx, const int elt)
{
	t_inst_set	set;
	const int	pos_elt = find_index(a, (t_nb){elt, -1});

	set.rb = 0;
	set.rr = 0;
	if (pos_elt > a->size / 2)
		set.ra = (a->size - pos_elt) * -1;
	else
		set.ra = idx;
	set.rb = get_rb(b, elt);
	set = get_rr(set);
	set.weight = ft_abs(set.ra) + ft_abs(set.rb) + ft_abs(set.rr) + 1;
	return (set);
}

t_inst_set	get_best_set(t_stack **a, t_stack **b)
{
	t_inst_set	best_set;
	t_inst_set	set;
	int			i;

	best_set.weight = INT_MAX;
	i = 1;
	while (i > 0)
	{
		set = get_instruction_set(*a, *b, i, (*a)->array[0].value);
		if (set.weight < best_set.weight)
			best_set = set;
		i += (i < (*a)->size) - i * (i >= (*a)->size);
	}
	return (best_set);
}
