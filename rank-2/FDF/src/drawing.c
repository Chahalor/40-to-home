/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 08:19:00 by nduvoid           #+#    #+#             */
/*   Updated: 2025/01/10 10:25:49 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	get_sign(int n)
{
	return ((n > 0) - (n < 0));
}

t_error	draw_line(t_data *data, t_point p1, t_point p2)
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
		ft_printf("\tp1.u=%d, p1.v=%d\n", p1.u, p1.v);
		color_pixel(addr, data, p1, GREEN);
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

void	draw_fdf(t_data *data)
{
	// t_type	x;

	// x = -1;
	// while (++x < data->map->height - 1)
	// {
	// 	if (x + 1 < data->map->height)
	// 		draw_line(data, data->map->iso_map[x], data->map->iso_map[x + 1]);
	// }
	(void)data;
	// need to remake
}

//rm
void	draw_tile(t_data *data, t_point start, int heigth, int width)
{
	ft_printf("start.u=%d, start.v=%d, heigth=%d, width=%d\n", start.u, start.v, heigth, width);
	// draw_line(data, (t_point){0, 0, 0}, (t_point){100, 100, 0});
	draw_line(data, start, (t_point){start.u + width, start.v, 0});
	draw_line(data, start, (t_point){start.u, start.v + heigth, 0});
	draw_line(data, (t_point){start.u + width, start.v, 0}, (t_point){start.u + width, start.v + heigth, 0});
	draw_line(data, (t_point){start.u, start.v + heigth, 0}, (t_point){start.u + width, start.v + heigth, 0});
}
