/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 10:30:05 by nduvoid           #+#    #+#             */
/*   Updated: 2025/01/10 10:22:48 by nduvoid          ###   ########.fr       */
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
			*(unsigned int *)(addr + pixel) = RED + data->map->map[x][y] * 100;
			y++;
		}
		x++;
	}
}

/** test function */
_X_UNUSED t_error	map_to_img_2d(t_data *data)
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

void	color_pixel(void *addr, t_data *data, t_point p, t_color color)
{
	int		pixel;

	pixel = (p.v * data->img->size_line + (p.u * (data->img->bpp / 8)));
	*(unsigned int *)(addr + pixel) = color;
}

/**
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
	
	iso_map = (t_point *)ft_calloc(data->map->height * data->map->width, sizeof(t_point));
	if (!iso_map)
		return (NULL);
	x = -1;
	while (++x < data->map->height)
	{
		y = -1;
		while (++y < data->map->width)
		{
			iso_map[x * data->map->width + y].u = (x - y) * cos(ANGLE);
			iso_map[x * data->map->width + y].v = (x + y) * sin(ANGLE) - data->map->map[x][y] * SCALE;
		}
	}
	return (iso_map);
}

void	*map_drawer(t_data *data, t_point *iso_map)
{
	void	*addr;
	t_type	x;
	int		screenX;
	int		screenY;
	t_type	minx;
	t_type	miny;

	addr = mlx_get_data_addr(data->img->img, &data->img->bpp,
			&data->img->size_line, &data->img->endian);
	if (!addr)
		return (NULL);
	minx = (data->map->height - 1) * cos(ANGLE);
	miny = (data->map->width - 1) * sin(ANGLE);
	x = -1;
	while (++x < data->map->height * data->map->width)
	{
		screenX = iso_map[x].u + minx;
		screenY = iso_map[x].v + miny;
		ft_printf("x=%d, y=%d\n", screenX, screenY);
		color_pixel(addr, data, (t_point){screenX, screenY, 0}, GREEN);
	}
	return (addr);
}

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
	if (mlx_put_image_to_window(data->mlx, data->win, data->img->img, 0, 0) < 0)	//rm
		return (MLX_IMG_ERROR);	//rm
	return (NO_ERROR);	//rm
	data->map->iso_map = map_to_iso(data);
	// dbg_print_iso(data, data->map->iso_map);
	if (!map_drawer(data, data->map->iso_map))
		return (MLX_IMG_ERROR);
	if (mlx_put_image_to_window(data->mlx, data->win, data->img->img, 0, 0) < 0)
		return (MLX_IMG_ERROR);
	return (NO_ERROR);
}
