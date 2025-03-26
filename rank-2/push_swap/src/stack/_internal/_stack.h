/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _stack.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 14:33:50 by nduvoid           #+#    #+#             */
/*   Updated: 2025/03/26 13:56:55 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _STACK_H
# define _STACK_H

#include <stdlib.h>
#include "types.h"
#include "libft.h"

// utils

void	get_index(t_nb *array, const int size);
void	_sort_stack(t_stack **stack);

// stack manipulation

void	swap(t_stack **stack);
void	swap_both(t_stack **stack_a, t_stack **stack_b);
void	rotate(t_stack **stack);
void	reverse_rotate(t_stack **stack);
void	rotate_both(t_stack **stack_a, t_stack **stack_b);
void	reverse_rotate_both(t_stack **stack_a, t_stack **stack_b);
void	push(t_stack **stack_a, t_stack **stack_b);

// utility

#endif	/* STACK_H */