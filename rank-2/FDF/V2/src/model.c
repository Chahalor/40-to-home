/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   model.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:53:22 by nduvoid           #+#    #+#             */
/*   Updated: 2025/01/30 10:37:29 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


/** @todo */
void	draw_projection(t_fdf *fdf)
{
	int	x;
	int	y;

	x = -1;
	while (++x < fdf->map->height - 1)
	{
		y = -1;
		while (++y < fdf->map->width - 1)
		{
			put_pixel(fdf->img, fdf->pos, calculate_coord(fdf->map->iso_map[x][y],
				fdf->pos->zoom, fdf->pos->paddingx, fdf->pos->paddingy),
				get_point_color(fdf, fdf->map->iso_map[x][y]));
			if (y + 1 < fdf->map->width - 1)
				// draw_line_2(fdf, x, y, 0);
				draw_line(fdf, calculate_coord(fdf->map->iso_map[x][y],
				fdf->pos->zoom, fdf->pos->paddingx, fdf->pos->paddingy),
					calculate_coord(fdf->map->iso_map[x][y + 1],
				fdf->pos->zoom, fdf->pos->paddingx, fdf->pos->paddingy),
				(t_uint [2]){fdf->pos->color1, fdf->pos->color2});
		}
		if (x + 1 < fdf->map->height - 1)
		{
			y = -1;
			while (++y < fdf->map->width - 1)
				// draw_line_2(fdf, x, y, 1);
				draw_line(fdf, calculate_coord(fdf->map->iso_map[x][y],
					fdf->pos->zoom, fdf->pos->paddingx, fdf->pos->paddingy),
					calculate_coord(fdf->map->iso_map[x + 1][y],
					fdf->pos->zoom, fdf->pos->paddingx, fdf->pos->paddingy),
					(t_uint [2]){fdf->pos->color1, fdf->pos->color2});
		}
	}
	mlx_put_image_to_window(fdf->mlx->mlx, fdf->mlx->win, fdf->img->img, 0, 0);
}

/** @todo */
void	clear_model(t_fdf *fdf)
{
	ft_bzero(fdf->img->addr, fdf->img->size_line * fdf->img->height);
}

/** @todo */
void	zoom_model(t_fdf *fdf, int zoom)
{
	clear_model(fdf);
	if (fdf->pos->zoom == 1 && zoom < 0)
		return ;
	fdf->pos->zoom += zoom;
	draw_projection(fdf);
}

/** @todo */
void	rotate_model(t_fdf *fdf, double rotationx, double rotationy)
{
	clear_model(fdf);
	fdf->pos->rotationx += rotationy;
	fdf->pos->rotationy += rotationx;
	fdf->map->iso_map = isometric(fdf, fdf->map, fdf->map->iso_map);
	if (!fdf->map->iso_map)
		exiting(fdf, mlx_error, "cannot rotate model");
	draw_projection(fdf);
}

/** @todo */
void	translat_model(t_fdf *fdf, int x, int y)
{
	clear_model(fdf);
	fdf->pos->paddingx += x;
	fdf->pos->paddingy += y;
	draw_projection(fdf);
}
