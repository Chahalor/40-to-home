/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _stack.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 14:33:50 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/02 13:26:52 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _STACK_H
# define _STACK_H

#include <stdlib.h>
#include "types.h"
#include "libft.h"

// utils

void	get_index(t_nb *array, const int size);
int		_sort_stack(t_stack **stack);

// stack manipulation

int	swap(t_stack **stack);
int	swap_both(t_stack **stack_a, t_stack **stack_b);
int	rotate(t_stack **stack);
int	reverse_rotate(t_stack **stack);
int	rotate_both(t_stack **stack_a, t_stack **stack_b);
int	reverse_rotate_both(t_stack **stack_a, t_stack **stack_b);
int	push(t_stack **stack_a, t_stack **stack_b);

// utility

#endif	/* STACK_H */