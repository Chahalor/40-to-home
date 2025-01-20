/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 10:30:05 by nduvoid           #+#    #+#             */
/*   Updated: 2025/01/20 15:07:18 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	color_pixel(void *addr, t_data *data, t_point p, t_color color)
{
	int		pixel;

	pixel = (p.v * data->img->size_line + (p.u * (data->img->bpp / 8)));
	if (pixel < 0 || pixel >= data->img->size_line * data->height)
		return ;
	*(unsigned int *)(addr + pixel) = color;
}

/**k
 * @brief Convert the map to an isometric map
 * 
 * @param data The data structure
 * @return t_point** The isometric map On the format array[array[t_point]],
 *  the map is ready to be drawed
 * @todo
 */
t_point	*map_to_iso(t_data *data)
{
	t_point	*iso_map;
	t_type	x;
	t_type	y;

	iso_map = (t_point *)ft_calloc(data->map->height * data->map->width,
			sizeof(t_point));
	if (!iso_map)
		return (NULL);
	x = -1;
	while (++x < data->map->height)
	{
		y = -1;
		while (++y < data->map->width)
		{
			iso_map[x * data->map->width + y].u = (y - x) * cos(data->rotationx);//  + (OFFSET_X);
			iso_map[x * data->map->width + y].v = (y + x) * sin(data->rotationy)
				- data->map->map[x][y] * SCALE ;//+ (OFFSET_Y);
		}
	}
	return (iso_map);
}

/** @todo */
t_error	map_to_img_3d(t_data *data)
{
	if (!data->img->img)
		data->img->img = mlx_new_image(data->mlx, data->width, data->height);
	if (!data->img->img)
		return (MLX_IMG_ERROR);
	data->img->addr = mlx_get_data_addr(data->img->img, &data->img->bpp,
			&data->img->size_line, &data->img->endian);
	if (!data->img->addr)
		return (MLX_IMG_ERROR);
	data->map->iso_map = map_to_iso(data);
	return (NO_ERROR);
}
