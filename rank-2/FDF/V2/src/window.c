/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:45:06 by nduvoid           #+#    #+#             */
/*   Updated: 2025/01/30 10:37:07 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
		put_pixel(fdf->img, fdf->pos, cur, calc_line_color(fdf, start, end, cur));
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

/** @todo */
void	draw_line_2(t_fdf *fdf, int x, int y, int mode)
{
	t_point	start;
	t_point	end;
	t_point	coord;
	int		sign[2];
	int		err[2];
	double	percent;

	if (mode == 0)
	{
		start = calculate_coord(fdf->map->iso_map[x][y], fdf->pos->zoom,
			fdf->pos->paddingx, fdf->pos->paddingy);
		end = calculate_coord(fdf->map->iso_map[x][y + 1], fdf->pos->zoom,
			fdf->pos->paddingx, fdf->pos->paddingy);
	}
	else
	{
		start = calculate_coord(fdf->map->iso_map[x][y], fdf->pos->zoom,
			fdf->pos->paddingx, fdf->pos->paddingy);
		end = calculate_coord(fdf->map->iso_map[x + 1][y ], fdf->pos->zoom,
			fdf->pos->paddingx, fdf->pos->paddingy);
	}
	sign[0] = get_sign(start.x, end.x);
	sign[1] = get_sign(start.y, end.y);
	err[0] = abs(end.x - start.x) - abs(end.y - start.y);
	coord = start;
	while (coord.x != end.x || coord.y != end.y)
	{
		percent = (coord.x - start.x) / (double)(end.x - start.x);
		put_pixel(fdf->img, fdf->pos, coord, (fdf->pos->color1 + fdf->pos->color2) * (1 + percent));
		err[1] = err[0] * 2;
		if (err[1] > -abs(end.y - start.y))
		{
			err[0] -= abs(end.y - start.y);
			coord.x += sign[0];
		}
		if (err[1] < abs(end.x - start.x))
		{
			err[0] += abs(end.x - start.x);
			coord.y += sign[1];
		}
	}
}
