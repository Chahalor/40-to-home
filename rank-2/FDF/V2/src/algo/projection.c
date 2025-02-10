/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 10:44:51 by nduvoid           #+#    #+#             */
/*   Updated: 2025/02/10 15:32:54 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/** @todo */
__attribute__((hot)) t_point	calculate_rev(t_fdf *fdf, t_map *map, int x,
	int y)
{
	return ((t_point){
		.x = map->map[x][y] * fdf->pos->rotationx / 2 + y * fdf->pos->rotationy,
		.y = x * fdf->pos->rotationy + y * fdf->pos->rotationx,
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
 * @return t_point The isometric coordinates of the point.
 */
__attribute__((hot)) t_point	calculate_iso(t_fdf *fdf, t_map *map, int i,
	int j)
{
	int	z;
	int	centered_i;
	int	centered_j;

	centered_i = i - map->height / 2;
	centered_j = j - map->width / 2;
	z = -centered_j * sin(fdf->pos->rotationx) + map->map[i][j] * cos(fdf->pos->rotationx) / 2;
	return ((t_point){
		.x = centered_j * cos(fdf->pos->rotationx) + map->map[i][j] * sin(fdf->pos->rotationx) / 2,
		.y = centered_i * cos(fdf->pos->rotationy) - z * sin(fdf->pos->rotationy),
		.z = fdf->map->map[i][j]
	});
}

/** @todo */
__attribute__((hot)) t_point	**projection(t_fdf *fdf, t_map *map,
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
		map->iso_map = points;
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
