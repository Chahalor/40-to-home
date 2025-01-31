/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 19:11:04 by nduvoid           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/01/30 10:35:44 by nduvoid          ###   ########.fr       */
=======
/*   Updated: 2025/01/29 11:30:37 by nduvoid          ###   ########.fr       */
>>>>>>> abbfe39 (auto push)
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
	int	k;
	// const int	matx[3][3] = {
	// 	{1, 0, 0},
	// 	{0, cos(rotationx), -sin(rotationx)},
	// 	{0, sin(rotationx), cos(rotationx)}
	// };
	// const int	maty[3][3] = {
	// 	{cos(rotationy), 0, sin(rotationy)},
	// 	{0, 1, 0},
	// 	{-sin(rotationy), 0, cos(rotationy)}
	// };
	int		new_x;
	int		new_y;

	x = -1;
	while (++x < map->height - 1)
	{
		y = -1;
		while (++y < map->width - 1)
		{
			k = -1;
			while (++k < 3)
			{
				new_x = map->iso_map[x][y].x * cos(rotationx) - map->iso_map[x][y].y * sin(rotationx);
				new_y = map->iso_map[x][y].x * sin(rotationy) + map->iso_map[x][y].y * cos(rotationy);
				map->iso_map[x][y].x = new_x;
				map->iso_map[x][y].y = new_y;
			}
		}
	}
}
