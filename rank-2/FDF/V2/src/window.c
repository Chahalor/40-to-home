/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:45:06 by nduvoid           #+#    #+#             */
/*   Updated: 2025/01/21 14:59:51 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_pixel(t_image *img, t_point pos, t_uint color)
{
	int		pixel;

	pixel = (pos.y * img->size_line + (pos.x * (img->bpp / 8)));
	if (pixel < 0 || pixel >= img->size_line * img->height)
		return ;
	*(unsigned int *)(img->addr + pixel) = color;
}

void	draw_line(t_fdf *fdf, t_point start, t_point end, t_color color)
{
	// t_point	delta;
	// t_point	sign;
	// t_point	cur;
	// int		error[2];

	// delta.x = abs(end.x - start.x);
	// delta.y = abs(end.y - start.y);
	// sign.x = start.x < end.x ? 1 : -1;
	// sign.y = start.y < end.y ? 1 : -1;
	// error[0] = delta.x - delta.y;
	// cur = start;
	// while (cur.x != end.x || cur.y != end.y)
	// {
	// 	put_pixel(fdf->img, cur, color);
	// 	error[1] = error[0] * 2;
	// 	if (error[1] > -delta.y)
	// 	{
	// 		error[0] -= delta.y;
	// 		cur.x += sign.x;
	// 	}
	// 	if (error[1] < delta.x)
	// 	{
	// 		error[0] += delta.x;
	// 		cur.y += sign.y;
	// 	}
	// }
	(void)fdf;
	(void)start;
	(void)end;
	(void)color;
}

void	draw_projection(t_fdf *fdf, t_color col_start, t_color col_end)
{
	int	x;
	int	y;

	(void)col_end;
	x = -1;
	while (++x < fdf->map->height)
	{
		y = -1;
		while (++y < fdf->map->width)
		{
			put_pixel(fdf->img, fdf->map->iso_map[x][y], col_start);
			if (y < fdf->map->width - 1)
				draw_line(fdf, fdf->map->iso_map[x][y], fdf->map->iso_map[x][y + 1], col_start);
			if (x < fdf->map->height - 1)
				draw_line(fdf, fdf->map->iso_map[x][y], fdf->map->iso_map[x + 1][y], col_start);
		}
	}
}
