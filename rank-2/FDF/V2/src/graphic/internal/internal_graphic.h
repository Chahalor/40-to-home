/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internal_graphic.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 17:39:34 by nduvoid           #+#    #+#             */
/*   Updated: 2025/02/10 17:52:40 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERNAL_GRAPHIC_H
# define INTERNAL_GRAPHIC_H

# pragma once

/* -----| Header |----- */
// Global
 ///...

// Local
# include "struct.h"

// modules
# include "graphic.h"

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
//...

/* -----| Static |----- */
//...

/* -----| Extern |----- */
//...

/* -----| Inline |----- */

/**
 * @brief This function draw the last line of the map. aka the last X of the
 * array
 * 
 * @param fdf The fdf structure.
 * 
 * @return void
 */
__attribute__((hot)) static inline void	draw_last_line(t_fdf *fdf)
{
	t_point	current;
	t_point	next;
	int		y;
	
	y = -1;
	while (++y < fdf->map->width - 1)
	{
		current = calc_c(fdf->map->iso_map[fdf->map->height - 1][y], fdf->pos);
		next = calc_c(fdf->map->iso_map[fdf->map->height - 1][y + 1], fdf->pos);
		draw_line(fdf, current, next, fdf->img->addr);
	}
}

#endif // INTERNAL_GRAPHIC_H