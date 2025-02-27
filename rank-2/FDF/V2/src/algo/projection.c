/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 10:44:51 by nduvoid           #+#    #+#             */
/*   Updated: 2025/02/27 11:51:52 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/internal_algo.h"

/**
 * @brief This function will calculate the coordinates of a point in the reverse
 * projection. To be quick, z become x, x become y and y becom z.
 * 
 * @param fdf The fdf structure.
 * @param map The map structure.
 * @param x The x position of the point.
 * @param y The y position of the point.
 * 
 * @return t_point The reverse projection coordinates of the point.
 */
__attribute__((hot)) t_point	calculate_rev(t_fdf *fdf, t_map *map, int x,
	int y)
{
	return ((t_point){
		.x = map->map[x][y] * fdf->pos->rotationx * 0.5 + y
			* fdf->pos->rotationy,
		.y = x * fdf->pos->rotationy + y * fdf->pos->rotationx * 0.5,
		.z = map->map[x][y]
	});
}

/**
 * @brief This function will calculate the isometric coordinates of a point.
 * 
 * @param fdf The fdf structure.
 * @param map The map structure.
 * @param i The x position of the point.
 * @param j The y position of the point.
 * 
 * @storage cos(fdf->pos->rotationy) - z * sin(fdf->pos->rotationy),
 * 
 * @return t_point The isometric coordinates of the point.
 */
__attribute__((hot)) t_point	calculate_iso(t_fdf *fdf, t_map *map, int i,
	int j)
{
	int	z;
	int	centered_i;
	int	centered_j;

	centered_i = i - (map->height >> 1);
	centered_j = j - (map->width >> 1);
	z = -centered_j * sin(fdf->pos->rotationx) + map->map[i][j]
		* cos(fdf->pos->rotationx) * 0.5 + 1;
	if (z > 10000)
		z = 10000;
	else if (z < -10000)
		z = -10000;
	return ((t_point){
		.x = centered_j * cos(fdf->pos->rotationx) + map->map[i][j]
			* sin(fdf->pos->rotationx) * 0.5,
		.y = centered_i,
		.z = fdf->map->map[i][j]
	});
}

__attribute__((cold)) t_point	init_iso(t_fdf *fdf, t_map *map, int i, int j)
{
	int	z;
	int	centered_i;
	int	centered_j;

	centered_i = i - map->height * 0.5;
	centered_j = j - map->width * 0.5;
	z = -centered_j * sin(fdf->pos->rotationx) + map->map[i][j]
		* cos(fdf->pos->rotationx) * 0.5 + 1;
	if (z > 10000)
		z = 10000;
	else if (z < -10000)
		z = -10000;
	return ((t_point){
		.x = centered_j * cos(fdf->pos->rotationx) + map->map[i][j]
			* sin(fdf->pos->rotationx) * 0.5,
		.y = centered_i * cos(fdf->pos->rotationy) - z
			* sin(fdf->pos->rotationy),
		.z = fdf->map->map[i][j]
	});
}

/**
 * @brief This function will calculate the projection in "3d" of the map.
 * It will use the fdf->algo function to calculate the coordinates of each point.
 * 
 * @param fdf The fdf structure.
 * @param map The map structure.
 * @param points The points array.
 * 
 * @return t_point** The points array.
 */
__attribute__((hot, malloc)) t_point	**projection(t_fdf *fdf, t_map *map,
	t_point **points)
{
	int		i;
	int		j;

	if (!points)
	{
		points = (t_point **)ft_calloc(map->height, sizeof(t_point *)
				+ sizeof(t_point) * map->width);
		if (!points)
			exiting(fdf, malloc_error, "projection(): cannot allocate memory");
	}
	i = -1;
	while (++i < map->height)
	{
		points[i] = (t_point *)(points + map->height) + i * map->width;
		j = -1;
		while (++j < map->width)
			points[i][j] = fdf->algo(fdf, map, i, j);
	}
	return (points);
}
