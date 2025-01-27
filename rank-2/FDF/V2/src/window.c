/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:45:06 by nduvoid           #+#    #+#             */
/*   Updated: 2025/01/27 20:50:02 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_pixel(t_image *img, t_point pos, t_color color)
{
	int	pixel;

	pixel = (pos.y * img->size_line + (pos.x * (img->bpp / 8)));
	if (pixel < 0 || pixel >= img->size_line * img->height)
		return ;
	*(unsigned int *)(img->addr + pixel) = rgb_to_uint(color);
}

void	draw_line(t_fdf *fdf, t_point start, t_point end, t_color color)
{
	t_point	delta;
	t_point	cur;
	int		error[2];

	delta.x = abs(end.x - start.x);
	delta.y = abs(end.y - start.y);
	error[0] = delta.x - delta.y;
	cur = start;
	while (cur.x != end.x || cur.y != end.y)
	{
		put_pixel(fdf->img, cur, color);
		error[1] = error[0] * 2;
		if (error[1] > -delta.y)
		{
			error[0] -= delta.y;
			cur.x += get_sign(start.x, end.x);
		}
		if (error[1] < delta.x)
		{
			error[0] += delta.x;
			cur.y += get_sign(start.y, end.y);
		}
	}
}

/** @todo */
void	draw_projection(t_fdf *fdf, t_color col_start, t_color col_end)
{
	int	x;
	int	y;

	(void)col_end;
	x = -1;
	while (++x < fdf->map->height - 1)
	{
		y = -1;
		while (++y < fdf->map->width - 1)
		{
			put_pixel(fdf->img, calculate_coord(fdf->map->iso_map[x][y],
				fdf->pos->zoom, fdf->pos->paddingx, fdf->pos->paddingy),
				calculate_color(fdf->map->min, fdf->map->max,
					fdf->map->map[x][y], fdf->colors->colors));
			if (y + 1 < fdf->map->width - 1)
				draw_line(fdf, calculate_coord(fdf->map->iso_map[x][y],
				fdf->pos->zoom, fdf->pos->paddingx, fdf->pos->paddingy),
					calculate_coord(fdf->map->iso_map[x][y + 1],
				fdf->pos->zoom, fdf->pos->paddingx, fdf->pos->paddingy),
				col_start);
		}
		if (x + 1 < fdf->map->height - 1)
		{
			y = -1;
			while (++y < fdf->map->width - 1)
				draw_line(fdf, calculate_coord(fdf->map->iso_map[x][y],
					fdf->pos->zoom, fdf->pos->paddingx, fdf->pos->paddingy),
					calculate_coord(fdf->map->iso_map[x + 1][y],
					fdf->pos->zoom, fdf->pos->paddingx, fdf->pos->paddingy),
					col_start);
		}
	}
	mlx_put_image_to_window(fdf->mlx->mlx, fdf->mlx->win, fdf->img->img, 0, 0);
}

void	zoom_model(t_fdf *fdf, int zoom)
{
	draw_projection(fdf, (t_color){.a = 0, .r = 0, .b = 0, .g = 0}, (t_color){.a = 0, .r = 0, .b = 0, .g = 0});
	fdf->pos->zoom += zoom;
	draw_projection(fdf, fdf->colors->red,  fdf->colors->blue);
}

void	rotate_model(t_fdf *fdf, double rotationx, double rotationy)
{
	draw_projection(fdf, (t_color){.a = 0, .r = 0, .b = 0, .g = 0}, (t_color){.a = 0, .r = 0, .b = 0, .g = 0});
	fdf->pos->rotationx += rotationx;
	fdf->pos->rotationy += rotationy;
	fdf->map->iso_map = isometric(fdf, fdf->map, fdf->map->iso_map);
	if (!fdf->map->iso_map)
		exiting(fdf, mlx_error, "cannot rotate model");
	draw_projection(fdf,  fdf->colors->red,  fdf->colors->blue);
}

void	translat_model(t_fdf *fdf, int x, int y)
{
	draw_projection(fdf, (t_color){.a = 0, .r = 0, .b = 0, .g = 0}, (t_color){.a = 0, .r = 0, .b = 0, .g = 0});
	fdf->pos->paddingx += x;
	fdf->pos->paddingy += y;
	draw_projection(fdf,  fdf->colors->red,  fdf->colors->blue);
}
