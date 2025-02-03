/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:45:06 by nduvoid           #+#    #+#             */
/*   Updated: 2025/02/03 16:34:34 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/**
 * @brief This function will put a pixel in the image.
 * 
 * @param img The image.
 * @param pos The position of the camera.
 * @param coord The coordinates of the pixel.
 * @param color The color of the pixel.
 * 
 * @return void
 */
void	put_pixel(t_image *img, t_pos *pos, t_point coord, t_uint color)
{
	t_point	screen;
	int		pixel;

	(void)pos;
	screen = coord;
	pixel = (screen.y * img->size_line + (screen.x * (img->bpp / 8)));
	if (pixel < 0 || pixel >= img->size_line * img->height)
		return ;
	*(unsigned int *)(img->addr + pixel) = color;
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
void	draw_line(t_fdf *fdf, t_point start, t_point end, t_uint colors[2])
{
	t_point	sign;
	t_point	cur;
	int		error[2];

	(void)colors;
	sign = (t_point){get_sign(start.x, end.x), get_sign(start.y, end.y), 0};
	error[0] = abs(end.x - start.x) - abs(end.y - start.y);
	cur = start;
	while (cur.x != end.x || cur.y != end.y)
	{
		put_pixel(fdf->img, fdf->pos, calculate_coord(cur, fdf->pos->zoom, fdf->pos->paddingx, fdf->pos->paddingy), calc_line_color(fdf, start, end, cur));
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
