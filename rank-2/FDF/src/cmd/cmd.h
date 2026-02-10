/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 10:24:31 by nduvoid           #+#    #+#             */
/*   Updated: 2025/02/11 11:23:48 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMD_H
# define CMD_H

# pragma once

/* -----| Header |----- */
// Global
//...

// Local
# include "struct.h"
# include "type.h"
# include "libft.h"

// modules
// ...

/* -----| Define |----- */

# ifndef DEBUG
#  define DEBUG 0
# endif	// DEBUG

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

// cmd.c

void	cmd(t_fdf *data);

/* -----| Static |----- */
//...

/* -----| Extern |----- */
//...

/* -----| Inline |----- */
//...

#endif	// CMD_H