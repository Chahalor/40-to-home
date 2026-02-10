/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internal_cmd.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 12:06:39 by nduvoid           #+#    #+#             */
/*   Updated: 2025/02/11 11:24:55 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERNAL_CMD_H
# define INTERNAL_CMD_H

# pragma once

/* -----| Header |----- */
// Global
//...

// Local
# include "struct.h"
# include "type.h"
# include "libft.h"

// modules
//...

// module
# include "algo.h"
# include "debug.h"
# include "graphic.h"
# include "utils.h"

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

// parsing.c

t_cmd	parse_input(char *line);

/* -----| Static |----- */
//...

/* -----| Extern |----- */
//...

/* -----| Inline |----- */

/**
 * @brief change the algorithm used to calculate the projection.
 * 
 * @param fdf The fdf structure.
 * @param type The type of the projection.
 * 
 * @return void
 */
__attribute__((unused, cold)) static inline void	change_algo(t_fdf *fdf,
	int type)
{
	if (type <= 0)
		fdf->algo = calculate_iso;
	else
		fdf->algo = calculate_rev;
	projection(fdf, fdf->map, fdf->map->iso_map);
	draw_projection(fdf);
}

/**
 * @brief Get the length of a command.
 * 
 * @param cmd The command.
 * 
 * @return int The length of the command.
 */
__attribute__((cold)) static inline int	len_cmd(char **cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
		i++;
	return (i);
}

#endif	// INTERNAL_CMD_H