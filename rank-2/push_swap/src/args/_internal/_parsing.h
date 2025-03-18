/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _parsing.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 10:29:22 by nduvoid           #+#    #+#             */
/*   Updated: 2025/03/18 16:13:13 by nduvoid          ###   ########.fr       */
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
# include "types.h"
# include "config.h"
# include "utils.h"
#include "algo.h"

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

t_algo	choose_algo(const char *algo, t_error *err);
void	parse_short_options(const int argc, const char **argv,
			int *i, t_args *args);
void	parse_long_options(const int argc, const char **argv,
			int *i, t_args *args);
t_error	check_stack(const char *stack);

int	*_parse_stack(const int argc, const char **argv, int *i, t_args *args);

/* -----| Static |----- */
//...

/* -----| Extern |----- */
//...

/* -----| Inline |----- */
//...

#endif	/* _PARSING_H */