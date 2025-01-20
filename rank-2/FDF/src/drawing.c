/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 08:19:00 by nduvoid           #+#    #+#             */
/*   Updated: 2025/01/20 15:47:17 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	get_sign(int n)
{
	return ((n > 0) - (n < 0));
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
	p1.u = p1.u * data->zoom / ZOOM_FACTOR + OFFSET_X;
	p1.v = p1.v * data->zoom / ZOOM_FACTOR + OFFSET_Y;
	ft_printf("line draw from (%d, %d) to (%d, %d)\n", p1.u, p1.v, p2.u, p2.v);
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

t_error	draw_all_line(t_data *data, t_color color)
{
	t_type	x;
	t_error	err;
	t_type	y;
	t_point	p1;

	err = NO_ERROR;
	x = -1;
	while (++x < data->map->height)
	{
		y = -1;
		while (++y < data->map->width)
		{
			// ft_printf("x: %d, y: %d\n", x, y);
			p1 = (t_point){y, x, data->map->map[x][y]};
			if (y + 1 < data->map->width)
				err = draw_line(data, p1, (t_point){y + 1, x,
						data->map->map[x][y + 1]}, color);
			if (x + 1 < data->map->height)
				err = draw_line(data, p1, (t_point){y, x + 1,
						data->map->map[x + 1][y]}, color);
			if (err)
				return (err);
		}
	}
	return (NO_ERROR);
}

/** @todo */
t_error	map_drawer(t_data *data, t_point *iso_map, t_color color, Bool scaling)
{
	void	*addr;
	t_type	x;
	int		screenx;
	int		screeny;

	addr = data->img->addr;
	if (!addr)
		return (MLX_IMG_ERROR);
	x = -1;
	while (++x < data->map->height * data->map->width)
	{	// @todo changer la valeur des OFFSET pour rendre sa modulaire
		screenx = iso_map[x].u * data->zoom / ZOOM_FACTOR + OFFSET_X;
		screeny = iso_map[x].v * data->zoom / ZOOM_FACTOR + OFFSET_Y;
		if (scaling)
			color_pixel(addr, data, (t_point){screenx, screeny, 0}, color
				+ data->map->map[x / data->map->width][x % data->map->width]
				* 100);
		else
			color_pixel(addr, data, (t_point){screenx, screeny, 0}, color);
	}
	draw_all_line(data, GREEN);
	return (mlx_put_image_to_window(data->mlx, data->win, data->img->img, 0, 0)
		< 0);
}

t_error	draw_rotation(t_data *data)
{
	if (map_drawer(data, data->map->iso_map, BLACK, FALSE))
		return (MLX_IMG_ERROR);
	free(data->map->iso_map);
	data->map->iso_map = map_to_iso(data);
	if (!data->map->iso_map)
		return (MALLOC_ERROR);
	if (map_drawer(data, data->map->iso_map, RED, TRUE))
		return (MLX_IMG_ERROR);
	return (NO_ERROR);
}

t_error	draw_zoom(t_data *data, t_type zoom)
{
	ft_printf("zoom: %d\n", data->zoom);
	if (map_drawer(data, data->map->iso_map, BLACK, FALSE))
		return (MLX_IMG_ERROR);
	data->zoom += zoom;
	if (map_drawer(data, data->map->iso_map, RED, TRUE))
		return (MLX_IMG_ERROR);
	return (NO_ERROR);
}

t_error	draw_fdf(t_data *data)
{
	if (map_drawer(data, data->map->iso_map, RED, TRUE))
		return (MLX_IMG_ERROR);
	return (NO_ERROR);
}
