/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 08:19:00 by nduvoid           #+#    #+#             */
/*   Updated: 2025/01/21 10:06:02 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/** @todo */
t_error	draw_line(t_data *data, t_point p1, t_point p2, t_color color)
{
	t_type	dx;
	t_type	dy;
	t_type	err;

	// ft_printf("drawing line from (%d, %d) to (%d, %d)\n", p1.u, p1.v, p2.u, p2.v);
	dx = abs(p2.u - p1.u);
	dy = abs(p2.v - p1.v);
	err = dx - dy;
	// p1.u = p1.u * data->zoom / ZOOM_FACTOR + data->height / 2;
	// p1.v = p1.v * data->zoom / ZOOM_FACTOR + data->width / 2;
	while (p1.u < p2.u && p1.v < p2.v)
	{
		// ft_printf("\tdrawing pixel at (%d, %d)\n", p1.u, p1.v);
		color_pixel(data->img->addr, data, p1, color);
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
	(void)data;
	(void)color;
	// ft_printf("drawing all lines\n");
	// draw_line(data, (t_point){0, 0, 0}, (t_point){data->height, data->width, 0}, color);
	return (NO_ERROR);
}

/** @todo */
t_error	map_drawer(t_data *data, t_point *iso_map, t_color color, Bool scaling)
{
	void	*addr;
	t_type	x;
	int		screenx;
	int		screeny;

	(void)scaling;
	addr = data->img->addr;
	if (!addr)
		return (MLX_IMG_ERROR);
	x = -1;
	while (++x < data->map->height * data->map->width)
	{
		screenx = iso_map[x].u * data->zoom / ZOOM_FACTOR + data->height / 2;
		screeny = iso_map[x].v * data->zoom / ZOOM_FACTOR + data->width / 2;
		color_pixel(addr, data, (t_point){screenx, screeny, 0},
			color + data->map->map[x / data->map->width]
			[x % data->map->width] * 100);
		if (x + 1 < data->map->height * data->map->width)
			draw_line(data, (t_point){screenx, screeny, 0}, (t_point){
				iso_map[x + 1].u * data->zoom / ZOOM_FACTOR + data->height
				/ 2, iso_map[x + 1].v * data->zoom / ZOOM_FACTOR
				+ data->width / 2, 0}, color);
	}
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
	if (data->zoom + zoom != 0)
	{
		if (map_drawer(data, data->map->iso_map, BLACK, FALSE))
			return (MLX_IMG_ERROR);
		data->zoom += zoom;
		if (map_drawer(data, data->map->iso_map, RED, TRUE))
			return (MLX_IMG_ERROR);
	}
	return (NO_ERROR);
}

t_error	draw_fdf(t_data *data)
{
	if (map_drawer(data, data->map->iso_map, RED, TRUE))
		return (MLX_IMG_ERROR);
	return (NO_ERROR);
}
