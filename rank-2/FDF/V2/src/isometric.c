/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:20:47 by nduvoid           #+#    #+#             */
/*   Updated: 2025/02/07 15:50:46 by nduvoid          ###   ########.fr       */
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
__attribute__((hot)) static t_point	calculate_iso(t_fdf *fdf, t_map *map, int i, int j)
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
__attribute__((hot)) t_point	**isometric(t_fdf *fdf, t_map *map, t_point **points)
{
	int		i;
	int		j;

	if (!points)
		points = (t_point **)ft_calloc(map->height, sizeof(t_point *)
				+ sizeof(t_point) * map->width);
	if (!points)
		return (NULL);
	i = -1;
	while (++i < map->height)
	{
		points[i] = (t_point *)(points + map->height) + i * map->width;
		j = -1;
		while (++j < map->width)
			points[i][j] = calculate_iso(fdf, map, i, j);
	}
	return (points);
}
