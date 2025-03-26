/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 13:37:11 by nduvoid           #+#    #+#             */
/*   Updated: 2025/03/26 13:37:04 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGO_H
# define ALGO_H

# pragma once

/* -----| Header |----- */
// System
//...

// Global
# include "config.h"
# include "types.h"

// Modules
# include "stack.h"

/* -----| Define |----- */
//...

/* -----| Macro |----- */
//...

/* -----| Typedef |----- */
//...

/* -----| Enum |----- */
//...

/* -----| Union |----- */
//...

/* -----| Struct |----- */
//...

/* -----| Prototype |----- */

t_error	turkish(t_stack **stack_a, t_stack **stack_b);
t_error	da_fuck(t_stack **stack_a, t_stack **stack_b);
t_error	mein_random(t_stack **stack_a, t_stack **stack_b);
t_error	miracle(t_stack **stack_a, t_stack **stack_b);

/* -----| Static |----- */
//...

/* -----| Extern |----- */
//...

/* -----| Inline |----- */
//...

#endif	/* ALGO_H */