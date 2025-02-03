/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   model.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:53:22 by nduvoid           #+#    #+#             */
/*   Updated: 2025/02/03 16:40:36 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fdf.h"


/** @todo */
void	draw_projection(t_fdf *fdf)
{
	int	x;
	int	y;

	x = -1;
	while (++x < fdf->map->height - 2)
	{
		y = -1;
		while (++y < fdf->map->width - 2)
		{
			if (y < fdf->map->width - 1)
				draw_line(fdf, fdf->map->iso_map[x][y], fdf->map->iso_map[x][y + 1], NULL);
			if (x < fdf->map->height - 1)
				draw_line(fdf, fdf->map->iso_map[x][y], fdf->map->iso_map[x + 1][y], NULL);
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
	if (DEBUG == 1)
		ft_printf("zoom: %d\n", zoom);
	clear_model(fdf);
	if (fdf->pos->zoom == 1 && zoom < 0)
		return ;
	fdf->pos->zoom += zoom;
	draw_projection(fdf);
}

/** @todo */
void	rotate_model(t_fdf *fdf, double rotationx, double rotationy)
{
	if (DEBUG == 1)
		ft_printf("rotationx: %f, rotationy: %f\n", rotationx, rotationy);
	clear_model(fdf);
	fdf->pos->rotationx += rotationx;
	fdf->pos->rotationy += rotationy;
	calculate_rotation(fdf->map, fdf->pos->rotationx, fdf->pos->rotationy);
	draw_projection(fdf);
}

/** @todo */
void	translat_model(t_fdf *fdf, int x, int y)
{
	if (DEBUG == 1)
		ft_printf("translat x: %d, y: %d\n", x, y);
	clear_model(fdf);
	fdf->pos->paddingx += x;
	fdf->pos->paddingy += y;
	draw_projection(fdf);
}
