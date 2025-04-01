/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _parsing.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 10:29:22 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/01 16:07:45 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _PARSING_H
# define _PARSING_H

# pragma once

/* -----| Header |----- */
// System
# include <errno.h>
# include <stdbool.h>

// Libs
# include "libft.h"

// Local
# include "stack.h"

/* -----| Define |----- */

# define PARSING_ALLOC_SIZE 1024

/* -----| Macro |----- */
//...

/* -----| Typedef |----- */

typedef struct s_nb		t_nb;

/* -----| Enum |----- */
//...

/* -----| Union |----- */
//...

/* -----| Struct |----- */
//...

/* -----| Prototype |----- */

void	parse_short_options(const int argc, const char **argv,
			int *i, t_args *args);
void	parse_long_options(const int argc, const char **argv,
			int *i, t_args *args);
int		check_stack(const char *stack);

t_nb	*_parse_stack(const int argc, const char **argv, int *i, t_args *args);

/* -----| Static |----- */
//...

/* -----| Extern |----- */
//...

/* -----| Inline |----- */
//...

#endif	/* _PARSING_H */