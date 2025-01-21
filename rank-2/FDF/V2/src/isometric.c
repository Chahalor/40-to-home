/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:20:47 by nduvoid           #+#    #+#             */
/*   Updated: 2025/01/21 15:07:16 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	**isometric(t_fdf *fdf, t_map *map)
{
	t_point	**points;
	int		i;
	int		j;

	points = (t_point **)ft_calloc(1, sizeof(t_point *) * map->height
		+ sizeof(t_point) * map->width);
	if (!points)
		return (NULL);
	points[0] = (t_point *)(points + map->height) + map->height * map->width;
	i = -1;
	while (++i < map->height)
	{
		points[i] = (t_point *)(points + map->height) + i * map->width;
		j = -1;
		while (++j < map->width)
		{
			ft_printf("i: %d, j: %d\n", i, j);
			points[i][j].x = (i - j) * cos(fdf->pos->rotationx);
			points[i][j].y = (i + j) * sin(fdf->pos->rotationy) - map->map[i][j] * SCALE;
			points[i][j].z = map->map[i][j];
			// points[i][j] = (t_point)
			// {
			// 	.x = (i - j) * cos(fdf->pos->rotationx),//  + (data->height / 2);
			// 	.y = (i + j) * sin(fdf->pos->rotationy) - map->map[i][j] * SCALE,// + (data->width / 2);
			// 	.z = map->map[i][j]
			// };
		}
	}
	return (points);
}
