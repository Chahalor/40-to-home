/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:20:47 by nduvoid           #+#    #+#             */
/*   Updated: 2025/01/27 19:10:56 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_point	calculate_iso(t_fdf *fdf, t_map *map, int i, int j)
{
	double	x;
	double	y;
	double	z;
	double	angle_z;

	angle_z = fdf->pos->rotationx;
	x = i - j;
	y = i + j;
	z = map->map[i][j];
	return ((t_point){
		.x = x * cos(fdf->pos->rotationy) * cos(angle_z) - y
			* sin(angle_z) + z * sin(fdf->pos->rotationy),
		.y = x * sin(fdf->pos->rotationx) * sin(fdf->pos->rotationy)
			+ y * cos(fdf->pos->rotationx) - z * sin(fdf->pos->rotationx)
			* cos(fdf->pos->rotationy),
		.z = 0});
}

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

// static t_point	calculate_iso(t_fdf *fdf, t_map *map, int i, int j, double center_x, double center_y)
// {
//     double	x;
//     double	y;
//     double	z;
//     double	angle_x;
//     double	angle_y;
//     double	angle_z;

//     angle_x = dtr(fdf->pos->rotationx);
//     angle_y = dtr(fdf->pos->rotationy);
//     angle_z = dtr(0);

//     // Recentrer le modèle
//     x = (i - j) - center_x;
//     y = (i + j) - center_y;
//     z = map->map[i][j];

//     // Appliquer la rotation
//     double new_x = x * cos(angle_y) * cos(angle_z) - y * sin(angle_z) + z * sin(angle_y);
//     double new_y = x * sin(angle_x) * sin(angle_y) + y * cos(angle_x) - z * sin(angle_x) * cos(angle_y);
//     double new_z = x * cos(angle_x) * sin(angle_y) + y * sin(angle_x) + z * cos(angle_x) * cos(angle_y);

//     // Recentrer à la position d'origine
//     new_x += center_x;
//     new_y += center_y;

//     return ((t_point){.x = new_x, .y = new_y, .z = new_z});
// }

// t_point	**isometric(t_fdf *fdf, t_map *map, t_point **points)
// {
//     int		i;
//     int		j;
//     double	center_x;
//     double	center_y;

//     // Calculer le centre du modèle
//     center_x = (map->width - 1) / 2.0;
//     center_y = (map->height - 1) / 2.0;

//     if (!points)
//         points = (t_point **)ft_calloc(map->height, sizeof(t_point *)
//             + sizeof(t_point) * map->width);
//     if (!points)
//         return (NULL);
//     i = -1;
//     while (++i < map->height - 1)
//     {
//         points[i] = (t_point *)(points + map->height) + i * map->width;
//         j = -1;
//         while (++j < map->width - 1)
//         {
//             points[i][j] = calculate_iso(fdf, map, i, j, center_x, center_y);
//         }
//     }
//     return (points);
// }