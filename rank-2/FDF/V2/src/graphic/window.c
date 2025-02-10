/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:45:06 by nduvoid           #+#    #+#             */
/*   Updated: 2025/02/10 15:50:09 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/**
 * @brief This function will interpolate the color between two points.
 * 
 * @param fdf The fdf structure.
 * @param z1 The z value of the first point.
 * @param z2 The z value of the second point.
 * 
 * @return t_uint The interpolated color.
 */
__attribute__((hot)) static t_uint	interpolate(t_fdf *fdf, int z1, int z2)
{
	if (fdf->map->max == fdf->map->min)
		return (fdf->pos->color1);
	return (fdf->pos->color1 * (z2 - z1) / (fdf->map->max - fdf->map->min)
		+ fdf->pos->color2);
}

/**
 * @brief This function will draw a line between two points.
 * 
 * @param fdf The fdf structure.
 * @param start The start point.
 * @param end The end point.
 * 
 * @return void
 */
__attribute__((hot)) void	draw_line(t_fdf *fdf, t_point start, t_point end,
	void *ptr)
{
	t_point	sign;
	t_point	cur;
	int		error[2];

	sign = (t_point){get_sign(start.x, end.x), get_sign(start.y, end.y), 0};
	error[0] = abs(end.x - start.x) - abs(end.y - start.y);
	cur = start;
	while (cur.x != end.x || cur.y != end.y)
	{
		if ((cur.x > 0 && cur.x < fdf->img->width && cur.y > 0 && cur.y \
			< fdf->img->height))
			*(unsigned int *)(ptr + (cur.y * fdf->img->size_line + (cur.x \
				* (fdf->img->bpp / 8)))) = interpolate(fdf, start.z, end.z);
		error[1] = error[0] * 2;
		if (error[1] > -abs(end.y - start.y))
		{
			error[0] -= abs(end.y - start.y);
			cur.x += sign.x;
		}
		if (error[1] < abs(end.x - start.x))
		{
			error[0] += abs(end.x - start.x);
			cur.y += sign.y;
		}
	}
}
