/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 09:09:04 by nduvoid           #+#    #+#             */
/*   Updated: 2024/12/11 11:28:20 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/**
 * @todo everything
 */
int	main(int argc, const char **argv)
{
	t_all	*all;

	if (argc < 2)
		exiting(ARG_ERROR);
	all = init_stacks(argc, argv);
	// sorting algorithm
	free(all);
	return (GOOD);
}
