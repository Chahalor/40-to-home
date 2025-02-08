/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 10:44:51 by nduvoid           #+#    #+#             */
/*   Updated: 2025/02/08 12:10:58 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/** @todo */
__attribute__((hot)) t_point	calculate_rev(t_fdf *fdf, t_map *map, int x,
	int y)
{
	return ((t_point){
		.x = map->map[x][y] * fdf->pos->rotationx + y * fdf->pos->rotationy,
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
	double	z;

	z = -j * sin(fdf->pos->rotationx) + map->map[i][j] / 2
		* cos(fdf->pos->rotationx);
	return ((t_point){
		.x = j * cos(fdf->pos->rotationx) + map->map[i][j] / 2
		* sin(fdf->pos->rotationx),
		.y = i * cos(fdf->pos->rotationy) - z * sin(fdf->pos->rotationy),
		.z = fdf->map->map[i][j]
	});
	// int		x;
	// int		y;
	// double	z;

	// x = map->iso_map[i][j].x;
	// y = map->iso_map[i][j].y;
	
}


/** @todo */
__attribute__((hot)) t_point	**projection(t_fdf *fdf, t_map *map,
	t_point **points, t_point (*f)(t_fdf *, t_map *, int, int))
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
		{
			points[i][j] = f(fdf, map, i, j);
			ft_printf("x: %d, y: %d, z: %d\n", points[i][j].x, points[i][j].y, points[i][j].z);
		}
	}
	return (points);
}
