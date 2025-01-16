/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 08:19:00 by nduvoid           #+#    #+#             */
/*   Updated: 2025/01/16 14:16:56 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	get_sign(int n)
{
	return ((n > 0) - (n < 0));
}

/** @todo */
t_error	map_drawer(t_data *data, t_point *iso_map, t_color color)
{
	void	*addr;
	t_type	x;
	int		screenx;
	int		screeny;
	t_color	pcolor;

	addr = data->img->addr;
	if (!addr)
		return (MLX_IMG_ERROR);
	x = -1;
	while (++x < data->map->height * data->map->width)
	{
		screenx = iso_map[x].u * data->zoom / ZOOM_FACTOR
			* (1 - 2 * (iso_map[x].u < 0));
		screeny = iso_map[x].v * data->zoom / ZOOM_FACTOR
			* (1 - 2 * (iso_map[x].v < 0));
		pcolor = color + data->map->map[x / data->map->width]
			[x % data->map->width] * 100;
		color_pixel(addr, data, (t_point){screenx, screeny, 0}, pcolor);
	}
	if (mlx_put_image_to_window(data->mlx, data->win, data->img->img, 0, 0) < 0)
		return (MLX_IMG_ERROR);
	return (NO_ERROR);
}

t_error	draw_zoom(t_data *data, t_type zoom)
{
	if (data->zoom + zoom < MIN_ZOOM * ZOOM_FACTOR
		|| data->zoom + zoom > MAX_ZOOM * ZOOM_FACTOR)
		return (NO_ERROR);
	if (map_drawer(data, data->map->iso_map, BLACK))
		return (MLX_IMG_ERROR);
	data->zoom += zoom;
	if (map_drawer(data, data->map->iso_map, BLUE))
		return (MLX_IMG_ERROR);
	return (NO_ERROR);
}


/** @todo */
t_error	draw_line(t_data *data, t_point p1, t_point p2, t_color color)
{
	t_type	dx;
	t_type	dy;
	t_type	err;
	void	*addr;

	dx = abs(p2.u - p1.u);
	dy = abs(p2.v - p1.v);
	err = dx - dy;
	addr = data->img->addr;
	while (p1.u < p2.u && p1.v < p2.v)
	{
		color_pixel(addr, data, p1, color);
		if (2 * err > -dy)
		{
			err -= dy;
			p1.u += get_sign(p2.u - p1.u);
		}
		else if (2 * err < dx)
		{
			err += dx;
			p1.v += get_sign(p2.v - p1.v);
		}
	}
	return (NO_ERROR);
}

t_error	draw_fdf(t_data *data)
{
	if (map_drawer(data, data->map->iso_map, BLUE))
		return (MLX_IMG_ERROR);
	// if (mlx_put_image_to_window(data->mlx, data->win, data->img->img, 0, 0) < 0)
	// 	return (MLX_IMG_ERROR);
	return (NO_ERROR);
}
