/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 10:52:03 by nduvoid           #+#    #+#             */
/*   Updated: 2024/12/13 11:01:41 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#if DEBUG == 1

int	main(int argc, const char **argv)
{
	t_all	*all;

	if (argc < 2)
		exiting(ARG_ERROR);
	all = init_all(argc, argv);
	if (!all || is_sorted(all->stack_a))
		return (free(all), STACK_SORTED);
	radix(all);
	// push_signi_to_b(all, 10, 1);
	// print_all(all);
	// sort_stack_b(all);
	// print_all(all);
	// push_signi_to_b(all, 10, 2);
	// print_all(all);
	// sort_stack_b(all);
	// push_signi_to_b(all, 10, 3);
	// print_all(all);
	// sort_stack_b(all);
	print_all(all);
	free(all);
	return (GOOD);
}

#elif ALLOW_FLAG == 1

int	main(int argc, const char *argv[])
{
	char	*flag[NB_FLAGS];
	t_all	*all;

	if (argc < 2)
		exiting(ARG_ERROR);
	get_flags(argc, argv, flag);
	
}

#else

int	main(int argc, const char **argv)
{
	t_all	*all;

	if (argc < 2)
		exiting(ARG_ERROR);
	all = init_all(argc, argv);
	if (!all || is_sorted(all->stack_a))
		return (free(all), STACK_SORTED);
	radix(all);
	return (free(all), GOOD);
}

#endif