/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internal_graphic.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 17:39:34 by nduvoid           #+#    #+#             */
/*   Updated: 2025/02/27 11:45:18 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERNAL_GRAPHIC_H
# define INTERNAL_GRAPHIC_H

# pragma once

/* -----| Header |----- */
// Global
# include <math.h>
# include <fcntl.h>
# include <stdlib.h>
# include "libft.h"
# include "mlx.h"
# include "mlx_int.h"

// Local
# include "struct.h"
# include "config.h"
# include "type.h"
# include "utils.h"
# include "algo.h"
# include "cmd.h"
# include "graphic.h"

// modules
//...

/* -----| Define |----- */
//...

/* -----| Macro |----- */
//...

/* -----| Union |----- */
//...

/* -----| Struct |----- */
//...

/* -----| Prototype |----- */

// window.c

void	draw_line(t_fdf *fdf, t_point start, t_point end, void *ptr);

// model.c

void	draw_projection(t_fdf *fdf);
void	zoom_model(t_fdf *fdf, int zoom);
void	rotate_model(t_fdf *fdf, double rotationx, double rotationy);
void	translat_model(t_fdf *fdf, int x, int y);

/* -----| Static |----- */
//...

/* -----| Extern |----- */
//...

/* -----| Inline |----- */

/**
 * @brief This function will verify if the pixel is in the image.
 * 
 * @param point The point to verify.
 * @param img The image.
 * 
 * @return int 1 if the pixel is in the image, 0 otherwise.
*/
__attribute__((hot)) static inline int	is_valid_pixel(t_point point,
	t_image *img)
{
	return (point.x >= 0
		&& point.x < img->width
		&& point.y >= 0
		&& point.y < img->height);
}

/**
 * @brief add the padding and the zoom to the point.
 * 
 * @param pt The point.
 * @param pos The position.
 * 
 * @return t_point The new point.
 */
__attribute__((hot)) static inline t_point	calc_c(t_point pt, t_pos *pos)
{
	return ((t_point){
		.x = pt.x * pos->zoom + pos->paddingx,
		.y = pt.y * pos->zoom + pos->paddingy,
		.z = pt.z});
}

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
	if (fdf->map->height == 1 && fdf->map->width == 1)
	{
		current = calc_c(fdf->map->iso_map[0][0], fdf->pos);
		next = (t_point){current.x + 1, current.y, current.z};
		draw_line(fdf, current, next, fdf->img->addr);
	}
}

#endif // INTERNAL_GRAPHIC_H