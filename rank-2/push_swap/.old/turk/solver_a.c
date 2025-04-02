/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 10:30:26 by mjuncker          #+#    #+#             */
/*   Updated: 2025/04/01 13:23:29 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_turk.h"

int	get_ra(t_stack **a, int elt)
{
	t_stack		*cpy;
	int			size;
	int			tmp;
	t_inst_set	set;
	int			i;

	cpy = *a;
	set.ra = 0;
	size = cpy->size;
	tmp = cpy->array[0].value;
	i = 1;
	while (i > 0)
	{
		if (tmp < elt && cpy->array[i].value > elt)
			break ;
		set.ra++;
		tmp = cpy->array[i].value;
		i += 1;
		i += (i < cpy->size) - i * (i >= cpy->size);
	}
	if (set.ra > size / 2)
		set.ra = (size - set.ra) * -1;
	return (set.ra);
}

int	get_min_max(t_inst_set *set, int elt, t_stack **a)
{
	const t_nb	min = (*a)->array[get_min_pos(*a)];
	const t_nb	max = (*a)->array[get_max_pos(*a)];

	if (min.value > elt)
	{
		set->ra = find_index(*a, min) ;//(ft_lstchr_n(*a, tmp));
		return (1);
	}
	else if (max.value < elt)
	{
		set->ra = find_index(*a, max) ;//(ft_lstchr_n(*a, tmp) + 1);
		return (1);
	}
	return (0);
}

void	sort_a(t_stack **a, t_stack **b)
{
	t_inst_set	set;
	int			elt;

	sort_3(a, b);
	while ((*b)->size)
	{
		elt = (*b)->array[0].value;
		set = (t_inst_set){0, 0, 0, 0};
		if (get_min_max(&set, elt, a) == 0)
			set.ra = get_ra(a, elt);
		set = get_rr(set);	// c est gut
		exec_set(a, b, set);	// c est gut
		interaction(PA, a, b);
	}
}
