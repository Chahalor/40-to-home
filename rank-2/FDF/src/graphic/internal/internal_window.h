/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internal_window.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 11:38:58 by nduvoid           #+#    #+#             */
/*   Updated: 2025/02/11 11:51:45 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERNAL_WINDOW_H
# define INTERNAL_WINDOW_H

# pragma once

/* -----| Header |----- */
// Global
# include <math.h>

// Local
# include "struct.h"
# include "type.h"

// modules
# include "internal_graphic.h"

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

// window.c

void	draw_line(t_fdf *fdf, t_point start, t_point end, void *ptr);

/* -----| Static |----- */
//...

/* -----| Extern |----- */
//...

/* -----| Inline |----- */

/**
 * @brief this function will return the sign of the difference between a and b.
 * 
 * @param a The first number.
 * @param b The second number.
 * 
 * @return int -1 if a > b, 1 otherwise.
 */
__attribute__((hot)) static inline int	get_s(int a, int b)
{
	if (a > b)
		return (-1);
	return (1);
}

/**
 * @brief This function will interpolate the color between two points.
 * 
 * @param fdf The fdf structure.
 * @param z1 The z value of the first point.
 * @param z2 The z value of the second point.
 * 
 * @return t_uint The interpolated color.
 */
__attribute__((hot)) static inline t_uint	calc_pixel(t_point cur,
	t_image *img)
{
	return (((cur.y * img->size_line + (cur.x * (img->bpp / 8)))));
}

/**
 * @brief This function will calculate the distance between two points.
 * 
 * @param start The start point.
 * @param end The end point.
 * 
 * @return int The distance between the two points.
 */
__attribute__((hot)) static inline int	get_dist(t_point start, t_point end)
{
	return (sqrt(pow(end.x - start.x, 2) + pow(end.y - start.y, 2)));
}

#endif	// INTERNAL_WINDOW_H