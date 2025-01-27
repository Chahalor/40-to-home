/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:20:47 by nduvoid           #+#    #+#             */
/*   Updated: 2025/01/27 14:29:10 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
		{
			points[i][j] = (t_point) {
				.x = (i - j) * cos(dtr(fdf->pos->rotationx)),
				.y = (i + j) * sin(dtr(fdf->pos->rotationy))
					- map->map[i][j] * 10 / fdf->pos->zoom,
				.z = map->map[i][j]};
		}
	}
	return (points);
}
