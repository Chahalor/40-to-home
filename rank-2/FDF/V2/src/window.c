/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:45:06 by nduvoid           #+#    #+#             */
/*   Updated: 2025/01/27 15:23:58 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_pixel(t_image *img, t_point pos, t_uint color)
{
	int	pixel;

	pixel = (pos.y * img->size_line + (pos.x * (img->bpp / 8)));
	if (pixel < 0 || pixel >= img->size_line * img->height)
		return ;
	*(unsigned int *)(img->addr + pixel) = color;
}

void	draw_line(t_fdf *fdf, t_point start, t_point end, t_color color)
{
	t_point	delta;
	t_point	sign;
	t_point	cur;
	int		error[2];

	delta.x = abs(end.x - start.x);
	delta.y = abs(end.y - start.y);
	sign.x = start.x < end.x ? 1 : -1;
	sign.y = start.y < end.y ? 1 : -1;
	error[0] = delta.x - delta.y;
	cur = start;
	while (cur.x != end.x || cur.y != end.y)
	{
		put_pixel(fdf->img, cur, color);
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

/** @todo */
void	draw_projection(t_fdf *fdf, t_color col_start, t_color col_end)
{
	int	x;
	int	y;
	int	screenx;
	int	screeny;

	(void)col_end;
	x = -1;
	while (++x < fdf->map->height - 1)
	{
		y = -1;
		while (++y < fdf->map->width - 1)
		{
			screenx = fdf->map->iso_map[x][y].x * fdf->pos->zoom / ZOOM_FACTOR + fdf->pos->paddingx;
			screeny = fdf->map->iso_map[x][y].y * fdf->pos->zoom / ZOOM_FACTOR + fdf->pos->paddingy;
			put_pixel(fdf->img, (t_point){screenx, screeny, 0}, col_start);
			if (y + 1 < fdf->map->width - 1)
				draw_line(fdf, (t_point){screenx, screeny, 0},
					(t_point){fdf->map->iso_map[x][y + 1].x * fdf->pos->zoom / ZOOM_FACTOR + fdf->pos->paddingx,
					fdf->map->iso_map[x][y + 1].y * fdf->pos->zoom / ZOOM_FACTOR + fdf->pos->paddingy, 0}, col_start);
		}
		if (x + 1 < fdf->map->height - 1)
			draw_line(fdf,
			(t_point){screenx, screeny, 0},
			(t_point){fdf->map->iso_map[x + 1][y].x * fdf->pos->zoom / ZOOM_FACTOR + fdf->pos->paddingx,
			fdf->map->iso_map[x + 1][y].y * fdf->pos->zoom / ZOOM_FACTOR + fdf->pos->paddingy, 0}, col_start);
	}
	mlx_put_image_to_window(fdf->mlx->mlx, fdf->mlx->win, fdf->img->img, 0, 0);
}

void	zoom_model(t_fdf *fdf, int zoom)
{
	draw_projection(fdf, black, black);
	fdf->pos->zoom += zoom;
	draw_projection(fdf, red, blue);
}

void	rotate_model(t_fdf *fdf, double rotationx, double rotationy)
{
	draw_projection(fdf, black, black);
	fdf->pos->rotationx += rotationx;
	fdf->pos->rotationy += rotationy;
	fdf->map->iso_map = isometric(fdf, fdf->map, fdf->map->iso_map);
	if (!fdf->map->iso_map)
		exiting(fdf, mlx_error, "cannot rotate model");
	draw_projection(fdf, red, blue);
}

void	translat_model(t_fdf *fdf, int x, int y)
{
	draw_projection(fdf, black, black);
	fdf->pos->paddingx += x;
	fdf->pos->paddingy += y;
	draw_projection(fdf, red, blue);
}
