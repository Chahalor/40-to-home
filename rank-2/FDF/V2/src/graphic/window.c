/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:45:06 by nduvoid           #+#    #+#             */
/*   Updated: 2025/02/07 09:09:49 by nduvoid          ###   ########.fr       */
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
__attribute__((unused)) void	put_pixel(t_image *img, t_point coord, t_uint color)
{
	int	pixel;

	if (coord.x < 0 || coord.x >= img->width || coord.y < 0
		|| coord.y >= img->height)
		return ;
	pixel = (coord.y * img->size_line + (coord.x * (img->bpp / 8)));
	if (pixel < 0 || pixel >= img->size_line * img->height)
		return ;
	*(unsigned int *)(img->addr + pixel) = color;
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
__attribute__((hot)) void	draw_line(t_fdf *fdf, t_point start, t_point end, void *ptr)
{
	t_point	sign;
	t_point	cur;
	int		error[2];

	sign = (t_point){get_sign(start.x, end.x), get_sign(start.y, end.y), 0};
	error[0] = abs(end.x - start.x) - abs(end.y - start.y);
	cur = start;
	while (cur.x != end.x || cur.y != end.y)
	{
		if ((cur.x > 0 && cur.x <= fdf->img->width && cur.y > 0 && cur.y <= fdf->img->height))
			*(unsigned int *)(ptr + (cur.y * fdf->img->size_line
				+ (cur.x * (fdf->img->bpp / 8)))) = interpolate(fdf, start.z, end.z);
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

__attribute__((hot)) void	draw_line2(t_fdf *fdf, t_point p1, t_point p2, void *buffer)
{
	t_point	delta;
	t_point	sign;
	t_point	cur;
	int		error[2];

	delta = (t_point){abs(p2.x - p1.x), abs(p2.y - p1.y), 0};
	sign = (t_point){get_sign(p1.x, p2.x), get_sign(p1.y, p2.y), 0};
	error[0] = delta.x - delta.y;
	cur = p1;
	while (cur.x != p2.x || cur.y != p2.y)
	{
		*(t_uint *)(buffer + (cur.y * fdf->img->size_line + cur.x * (fdf->img->bpp / 8))) = interpolate(fdf, p1.z, p2.z);
		error[1] = error[0] * 2;
		if (error[1] > -delta.y)
		{
			error[0] -= delta.y;
			cur.x += sign.x;
		}
		if (error[1] < delta.x)
		{
			error[0] += delta.x;
			cur.y += sign.y;
		}
	}
}
