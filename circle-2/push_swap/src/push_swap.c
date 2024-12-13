/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 09:09:04 by nduvoid           #+#    #+#             */
/*   Updated: 2024/12/13 09:30:51 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

#if DEBUG == 1

/**
 * @file push_swap.c
 * @dir src/
 * @brief main function of the program push_swap on is debug mode
 * 
 * @example ./push_swap 1 5 3 => rra\nsa\n
 * @example ./push_swap 1 2 3 => nothing
 * @example ./push_swap 1 two 3 => Error\n
 * 
 * @param argc number of arguments
 * @param argv arguments
 * @return
 * 
 * - 0 if everything is ok
 * 
 * - 1 if there is a malloc error
 * 
 * - 2 if there is an argument error
 * 
 * - 3 if there is a stack error
 * 
 * @note if DEBUG is set to 0, the program will run an other main function
 */
int	main(int argc, const char **argv)
{
	t_all	*all;

	if (argc < 2)
		exiting(ARG_ERROR);
	all = init_all(argc, argv);
	// print_all(all);
	// radix(all);
	push_signi_to_b(all, 10, 1);
	print_all(all);
	sort_stack_b(all);
	print_all(all);
	free(all);
	return (GOOD);
}

#else

/**
 * @file push_swap.c
 * @dir src/
 * @brief main function of the program push_swap
 * 
 * @example ./push_swap 1 5 3 => rra\nsa\n
 * @example ./push_swap 1 2 3 => nothing
 * @example ./push_swap 1 two 3 => Error\n
 * 
 * @param argc number of arguments
 * @param argv arguments
 * @return
 * 
 * - 0 if everything is ok
 * 
 * - 1 if there is a malloc error
 * 
 * - 2 if there is an argument error
 * 
 * - 3 if there is a stack error
 * 
 * @note if DEBUG is set to 1, the program will run an other main function
 */
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