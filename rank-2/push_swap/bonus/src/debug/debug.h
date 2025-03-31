/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 12:21:49 by nduvoid           #+#    #+#             */
/*   Updated: 2025/03/31 09:29:15 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_H
# define DEBUG_H

# pragma once

/* -----| Header |----- */
// System
	//...

// Global
# include "libft.h"

// Modules
# include "stack.h"
# include "parsing.h"

/* -----| Define |----- */

# ifndef DEBUG
#  define DEBUG 0
# endif	/* DEBUG */

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

void	print_stack(const t_stack *stack);
void	print_args(const t_args *args);

/* -----| Static |----- */
//...

/* -----| Extern |----- */
//...

/* -----| Inline |----- */
//...

#endif	/* DEBUG_H */