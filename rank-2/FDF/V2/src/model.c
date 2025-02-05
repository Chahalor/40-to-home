/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   model.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:53:22 by nduvoid           #+#    #+#             */
/*   Updated: 2025/02/05 13:57:01 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/**
 * @brief This function will draw the projection of the map.
 * 
 * @param fdf The fdf structure.
 * 
 * @return void
 */
__attribute__((hot)) void	draw_projection(t_fdf *fdf)
{
	int	x;
	int	y;

	x = -1;
	while (++x < fdf->map->height - 1)
	{
		y = -1;
		while (++y < fdf->map->width - 1)
		{
			if (y + 1 < fdf->map->width - 1)
				draw_line(fdf, calc_c(fdf->map->iso_map[x][y], fdf->pos),
					calc_c(fdf->map->iso_map[x][y + 1], fdf->pos), fdf->img->addr);
		}
		if (x + 1 < fdf->map->height - 1)
		{
			y = -1;
			while (++y < fdf->map->width - 1)
				draw_line(fdf, calc_c(fdf->map->iso_map[x][y], fdf->pos),
					calc_c(fdf->map->iso_map[x + 1][y], fdf->pos), fdf->img->addr);
		}
	}
	mlx_put_image_to_window(fdf->mlx->mlx, fdf->mlx->win, fdf->img->img, 0, 0);
}

/** 
 * @brief This function will clear the model.
 * 
 * @param fdf The fdf structure.
 * 
 * @return void
 * 
 * @note a big ft_bzero() xD
 */
void	clear_model(t_fdf *fdf)
{
	ft_bzero(fdf->img->addr, fdf->img->size_line * fdf->img->height);
}

/** 
 * @brief This function will zoom the model. Only if the zoom > 0.
 * 
 * @param fdf The fdf structure.
 * @param zoom The zoom value.
 * 
 * @return void
 */
void	zoom_model(t_fdf *fdf, int zoom)
{
	if (DEBUG == 1)
		ft_printf("zoom: %d\n", zoom);
	clear_model(fdf);
	if (zoom == 0 || fdf->pos->zoom + zoom <= 0)
		return ;
	fdf->pos->zoom += zoom;
	draw_projection(fdf);
}

/** 
 * @brief This function will rotate the model with the given rotation values.
 * By 1/10 of the given values.
 * 
 * @param fdf The fdf structure.
 * @param rotationx The rotation on the x axis.
 * @param rotationy The rotation on the y axis.
 * 
 * @return void
 */
void	rotate_model(t_fdf *fdf, double rotationx, double rotationy)
{
	if (DEBUG == 1)
		ft_printf("rotationx: %f, rotationy: %f\n", rotationx, rotationy);
	clear_model(fdf);
	fdf->pos->rotationx += rotationx / 10;
	fdf->pos->rotationy += rotationy / 10;
	isometric(fdf, fdf->map, fdf->map->iso_map);
	draw_projection(fdf);
}

/**
 * @brief This function will translate the model with the given values.
 * 
 * @param fdf The fdf structure.
 * @param x The x value.
 * @param y The y value.
 * 
 * @return void
 */
void	translat_model(t_fdf *fdf, int x, int y)
{
	if (DEBUG == 1)
		ft_printf("translat x: %d, y: %d\n", x, y);
	clear_model(fdf);
	fdf->pos->paddingx += x;
	fdf->pos->paddingy += y;
	draw_projection(fdf);
}
