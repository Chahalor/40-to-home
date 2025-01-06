/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 10:30:05 by nduvoid           #+#    #+#             */
/*   Updated: 2025/01/06 12:36:47 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/** test function */
static void	draw_map_2d(void *addr, t_data *data)
{
	int		stepX;
	int		stepY;
	int		screenX;
	int		screenY;
	int		x;
	int		y;
	int		pixel;

	if (!addr)
		return ;
	stepX = data->width / data->map->width;
	stepY = data->height / data->map->height;
	x = 0;
	while (x < data->map->height - 1)
	{
		y = 0;
		while (y < data->map->width - 1)
		{
			screenX = x * stepX;
			screenY = y * stepY;
			pixel = (screenX * data->img->size_line + screenY * (data->img->bpp / 8));
			*(unsigned int *)(addr + pixel) = 0x00FF0000 + data->map->map[x][y] * 100;
			y++;
		}
		x++;
	}
}

/** test function */
t_error	map_to_img_2d(t_data *data)
{
	void	*img_addr;

	if (!data->img->img)
		data->img->img = mlx_new_image(data->mlx, data->width, data->height);
	if (!data->img->img)
		return (MLX_IMG_ERROR);
	img_addr = mlx_get_data_addr(data->img->img, &data->img->bpp,
			&data->img->size_line, &data->img->endian);
	if (!img_addr)
		return (MLX_IMG_ERROR);
	draw_map_2d(img_addr, data);
	mlx_put_image_to_window(data->mlx, data->win, data->img->img, 0, 0);
	return (NO_ERROR);
}

/**
 * @brief Convert the map to an isometric map
 * 
 * @param data The data structure
 * @return int** The isometric map On the format array[array[x, y]],
 *  the map is ready to be drawed
 */
t_point		**map_to_iso(t_data *data)
{
	t_type	x;
	t_type	y;
	t_point	**iso_map;
	
	iso_map = (t_point**)ft_calloc(data->map->height, sizeof(t_point*)
			+ data->map->width * sizeof(t_type));
	if (!iso_map)
		return (NULL);
	x = 0;
	while (x < data->map->height)
	{
		y = 0;
		iso_map[x] = (t_point*)(iso_map + data->map->height) + x * data->map->width;
		while (y < data->map->width)
		{
			iso_map[x][y].u = x * cos(45) + y * sin(45);
			iso_map[x][y].v = y * sin(30) + y * cos(30);
			y++;
		}
		x++;
	}
	return (iso_map);
}

void	*addr_builder(t_data *data, t_point **iso_map)
{
	t_type	x;
	t_type	y;
	int		screenX;
	int		screenY;
	int		pixel;

	x = 0;
	while (x < data->map->height)
	{
		y = 0;
		while (y < data->map->width)
		{
			screenX = iso_map[x][y].u * data->width / data->map->width;
			screenY = iso_map[x][y].v * data->height / data->map->height;
			pixel = (screenX * data->img->size_line + screenY
					* (data->img->bpp / 8));
			*(unsigned int *)(data->img->img + pixel) = 0x00FF0000
					+ data->map->map[x][y] * 100;
			y++;
		}
		x++;
	}
	// screenX = iso_map->u * data->width / data->map->width;
	// screenY = iso_map->v * data->height / data->map->height;
	// pixel = (screenX * data->img->size_line + screenY * (data->img->bpp / 8));
	return (data->img->img);
}

t_error	map_to_img_3d(t_data *data)
{
	void	*img_addr;
	t_point	**iso_map;

	if (!data->img->img)
		data->img->img = mlx_new_image(data->mlx, data->width, data->height);
	if (!data->img->img)
		return (MLX_IMG_ERROR);
	img_addr = mlx_get_data_addr(data->img->img, &data->img->bpp,
			&data->img->size_line, &data->img->endian);
	if (!img_addr)
		return (MLX_IMG_ERROR);
	iso_map = map_to_iso(data);
	if (!addr_builder(data, iso_map))
		return (MLX_IMG_ERROR);
	if (mlx_put_image_to_window(data->mlx, data->win, data->img->img, 0, 0) < 0)
		return (MLX_IMG_ERROR);
	return (NO_ERROR);
}
