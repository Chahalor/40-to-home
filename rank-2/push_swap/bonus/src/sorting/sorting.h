/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 08:52:37 by nduvoid           #+#    #+#             */
/*   Updated: 2025/03/28 10:53:15 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORTING_H
# define SORTING_H

#include "stack.h"

t_instruct	*read_instructions(void);
int			do_test(t_stack *stack_a, t_stack *stack_b, t_instruct *instruct);

#endif	/* SORTING_H */