/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:20:47 by nduvoid           #+#    #+#             */
/*   Updated: 2025/02/03 09:49:13 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fdf.h"

/**
 * @brief This function will calculate the isometric coordinates of a point.
 * 
 * @param fdf The fdf structure.
 * @param map The map structure.
 * @param i The x position of the point.
 * @param j The y position of the point.
 * 
 * @return t_point The isometric coordinates of the point.
 */
static t_point	calculate_iso(t_fdf *fdf, t_map *map, int i, int j)
{
	double	x;
	double	y;
	double	z;
	double	angle_z;

	angle_z = 90;
	x = i;
	y = j;
	z = map->map[i][j];
	t_point point = {
		// .x = x * cos(fdf->pos->rotationy) * cos(angle_z) - y
		// 	* sin(angle_z) + z * sin(fdf->pos->rotationy),
		// .y = x * sin(fdf->pos->rotationx) * sin(fdf->pos->rotationy)
		// 	+ y * cos(fdf->pos->rotationx) - z * sin(fdf->pos->rotationx)
		// 	* cos(fdf->pos->rotationy),
		// .z = map->map[i][j]
		.x = (x - y) * cos(fdf->pos->rotationx),
		.y = (x + y) * sin(fdf->pos->rotationy) - z,
		.z = map->map[i][j]
	};
	return (point);
}

/**
 * @brief This function will calculate the isometric map.
 * 
 * @param fdf The fdf structure.
 * @param map The map structure.
 * @param points The points.
 * 
 * @return t_point** The isometric map.
 */
t_point	**isometric(t_fdf *fdf, t_map *map, t_point **points)
{
	int		i;
	int		j;

	if (!points)
		points = (t_point **)ft_calloc(map->height, sizeof(t_point *)
			+ sizeof(t_point) * map->width);
	if (!points)
		return (NULL);
	i = -1;
	while (++i < map->height - 1)
	{
		points[i] = (t_point *)(points + map->height) + i * map->width;
		j = -1;
		while (++j < map->width - 1)
			points[i][j] = calculate_iso(fdf, map, i, j);
	}
	return (points);
}
