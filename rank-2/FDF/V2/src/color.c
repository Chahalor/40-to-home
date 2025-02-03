/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 19:11:04 by nduvoid           #+#    #+#             */
/*   Updated: 2025/02/03 16:27:54 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fdf.h"

/** @todo */
t_uint	get_point_color(t_fdf *fdf, t_point point)
{
	double	percent;
	t_uint	color;

	percent = (point.z - fdf->map->min) / (fdf->map->max - fdf->map->min);
	color = (t_uint)(fdf->pos->color1 * (1 - percent) + fdf->pos->color2 * percent);
	return (color);
}

/** @todo */
t_uint	calc_line_color(t_fdf *fd, t_point start, t_point end, t_point cur)
{
	double	percent;
	t_uint	color;

	if (start.z == end.z)
		return (get_point_color(fd, cur));
	percent = (cur.z - start.z) / (end.z - start.z);
	color = (t_uint)(get_point_color(fd, start) * (1 - percent)
			+ get_point_color(fd, end) * percent);
	return (color);
}

/** @todo */
void	calculate_rotation(t_map *map, double rotationx, double rotationy)
{
	int		x;
	int		y;
	float	tmpx;
	float	tmpy;
	int		center_x; 
	int		center_y;

	center_y = (map->height - 1) / 2;
	center_x = (map->width - 1) / 2;
	x = -1;
	while (++x < map->height - 1)
	{
		y = -1;
		while (++y < map->width - 1)
		{
			tmpx = x - center_x;
			tmpy = y - center_y;
			map->iso_map[x][y] = (t_point){
				.x = (tmpx * cos(rotationx) + tmpy * sin(rotationx)) + center_x,
				.y = (tmpx * sin(rotationy) + tmpy * cos(rotationy)) + center_y,
				.z = map->iso_map[x][y].z
			};
		}
	}
}
