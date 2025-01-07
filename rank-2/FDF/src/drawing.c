/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 08:19:00 by nduvoid           #+#    #+#             */
/*   Updated: 2025/01/07 15:39:54 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_sign(int n)
{
	return ((n > 0) - (n < 0));
}

t_type	get_error(t_type dx, t_type dy)
{
	if (dx > dy)
		return (dx);
	return (-dy);
}

t_error	draw_line(t_data *data, t_point p1, t_point p2, int weigth)
{
	t_type	dx;
	t_type	dy;
	t_type	sx;
	t_type	sy;
	t_type	err;
	(void)weigth;

	ft_printf("p1: %d %d; p2: %d %d\n", p1.u, p1.v, p2.u, p2.v);
	dx = abs(p2.u - p1.u);
	dy = abs(p2.v - p1.v);
	sx = get_sign(p2.u - p1.u);
	sy = get_sign(p2.v - p1.v);
	err = dx - dy;
	while (p1.u < p2.u && p1.v < p2.v)
	{
		mlx_pixel_put(data->mlx, data->win, p1.u, p1.v, RED);
		if (2 * err > -dy)
		{
			err -= dy;
			p1.u += sx;
		}
		else if (2 * err < dx)
		{
			err += dx;
			p1.v += sy;
		}
	}
	return (NO_ERROR);
}

void	draw_fdf(t_data *data)
{
	t_type	x;
	t_type	y;

	x = -1;
	while (++x < data->map->height - 1)
	{
		y = -1;
		while (++y < data->map->width - 1)
		{
			if (x + 1 < data->map->height)
				draw_line(data, data->map->iso_map[x][y], data->map->iso_map[x + 1][y], 0);
			if (y + 1 < data->map->width)
				draw_line(data, data->map->iso_map[x][y], data->map->iso_map[x][y + 1], 0);
		}
	}
}
