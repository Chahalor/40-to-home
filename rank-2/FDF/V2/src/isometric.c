/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:20:47 by nduvoid           #+#    #+#             */
/*   Updated: 2025/01/23 08:01:48 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	**isometric(t_fdf *fdf, t_map *map)
{
	t_point	**points;
	int		i;
	int		j;

	points = (t_point **)ft_calloc(map->height, sizeof(t_point *)
		+ sizeof(t_point) * map->width);
	if (!points)
		return (NULL);
	ft_printf("map->height: %d, map->width: %d\n", map->height, map->width);
	i = -1;
	while (++i < map->height - 1)
	{
		points[i] = (t_point *)(points + map->height) + i * map->width;
		j = -1;
		while (++j < map->width - 1)
		{
			points[i][j] = (t_point) {
				.x = (i - j) * cos(fdf->pos->rotationx)  + (fdf->img->height / 2),
				.y = (i + j) * sin(fdf->pos->rotationy) - map->map[i][j] * 10
					+ (fdf->img->width / 2),
				.z = map->map[i][j]};
		}
	}
	return (points);
}
