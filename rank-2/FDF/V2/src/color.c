/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 19:11:04 by nduvoid           #+#    #+#             */
/*   Updated: 2025/02/03 10:50:37 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fdf.h"

t_uint	get_point_color(t_fdf *fdf, t_point point)
{
	double	percent;
	t_uint	color;

	percent = (point.z - fdf->map->min) / (fdf->map->max - fdf->map->min);
	color = (t_uint)(fdf->pos->color1 * (1 - percent) + fdf->pos->color2 * percent);
	return (color);
}

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

void	calculate_rotation(t_map *map, double rotationx, double rotationy)
{
	int	x;
	int	y;
	// int	new_x;
	// int	new_y;

	x = -1;
	while (++x < map->height - 1)
	{
		y = -1;
		while (++y < map->width - 1)
		{
			// double	x;
			// double	y;
			double	z;
			double	angle_z;

			angle_z = 90;
			z = map->map[x][y];
			t_point point = {
				// .x = x * cos(fdf->pos->rotationy) * cos(angle_z) - y
				// 	* sin(angle_z) + z * sin(fdf->pos->rotationy),
				// .y = x * sin(fdf->pos->rotationx) * sin(fdf->pos->rotationy)
				// 	+ y * cos(fdf->pos->rotationx) - z * sin(fdf->pos->rotationx)
				// 	* cos(fdf->pos->rotationy),
				// .z = map->map[i][j]
				.x = (x - y) * cos(rotationx),
				.y = (x + y) * sin(rotationy) - z,
				.z = map->map[x][y]
			};
			map->iso_map[x][y] = point;
		}
	}
}
