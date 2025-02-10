/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parrallel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 09:47:33 by nduvoid           #+#    #+#             */
/*   Updated: 2025/02/07 13:37:59 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/** @todo */
__attribute__((hot)) static t_point	calculate_parallel(t_fdf *fdf, t_map *map,
		int x, int y)
{
	return ((t_point){
		.x = x / (1 + 10 /fdf->pos->zoom),
		.y = y / (1 + 10 /fdf->pos->zoom),
		.z = map->map[x][y]});
}

/** @todo */
__attribute__((hot)) t_point **parallel(t_fdf *fdf, t_map *map, t_point **points)
{
	int	x;
	int	y;

	if (!points)
		points = (t_point **)ft_calloc(map->height, sizeof(t_point *));
	if (!points)
		exiting(fdf, malloc_error, "cannot allocate memory for points");
	x = -1;
	while (++x < map->height - 1)
	{
		y = -1;
		while (++y < map->width - 1)
			points[x][y] = calculate_parallel(fdf, map, x, y);
	}
	return (points);
}
