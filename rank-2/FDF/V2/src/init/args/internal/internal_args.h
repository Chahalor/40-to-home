/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internal_args.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 12:13:41 by nduvoid           #+#    #+#             */
/*   Updated: 2025/02/10 12:17:16 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERNAL_ARGS_H
# define INTERNAL_ARGS_H

# pragma once

/* -----| Header |----- */
// Global
 //...

// Local
# include "fdf.h"
# include "type.h"
# include "struct.h"

// Modules
 //...

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
// args_parsing.c

void	parseur_v2(int argc, const char *argv[], t_args *args);

// args_utils.c

int	vl(const int argc, const char *argv[], int pos, int nb_args);
int	is_valid_soption(const int argc, const char *argv[], int pos, int nb_args);

/* -----| Static |----- */
//...

/* -----| Extern |----- */
//...

/* -----| Inline |----- */
//...

#endif	// INTERNAL_ARGS_H