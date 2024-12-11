/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 09:09:04 by nduvoid           #+#    #+#             */
/*   Updated: 2024/12/11 15:30:41 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

#if DEBUG == 1

/**
 * @todo everything
 */
int	main(int argc, const char **argv)
{
	t_all	*all;

	if (argc < 2)
		exiting(ARG_ERROR);
	all = init_all(argc, argv);
	print_all(all);
	radix(all);
	// print_all(all);
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
	if (!all)
		return (STACK_SORTED);
	radix(all);
	free(all);
	return (GOOD);
}

#endif