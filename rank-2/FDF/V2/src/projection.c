/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 10:44:51 by nduvoid           #+#    #+#             */
/*   Updated: 2025/02/07 15:46:36 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/** @todo */
__attribute__((hot)) static t_point calculate_reversator(t_fdf *fdf, t_map *map,
		int x, int y)
{
	return ((t_point){
		.x = map->map[x][y] * fdf->pos->rotationx + y * fdf->pos->rotationy,
		.y = x * fdf->pos->rotationy + y * fdf->pos->rotationx,
		.z = map->map[x][y]
	});
}

/** @todo */
__attribute__((hot)) t_point **reversator(t_fdf *fdf, t_map *map, t_point **points)
{
	int	x;
	int	y;

	if (!points)
		points = (t_point **)ft_calloc(map->height, sizeof(t_point *)
				+ sizeof(t_point) * map->width);
	if (!points)
		exiting(fdf, malloc_error, "cannot allocate memory for points");
	x = -1;
	while (++x < map->height)
	{
		points[x] = (t_point *)(points + map->height) + x * map->width;
		y = -1;
		while (++y < map->width)
			points[x][y] = calculate_reversator(fdf, map, x, y);
	}
	return (points);
}
