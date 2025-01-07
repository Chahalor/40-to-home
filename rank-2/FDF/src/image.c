/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 10:30:05 by nduvoid           #+#    #+#             */
/*   Updated: 2025/01/07 15:17:35 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/**
 * @rm 
 * test function 
 * */
void	print_iso(t_data *data, t_point **iso)
{
	int	x, y = 0;

	while (y < data->map->height - 1)
	{
		x = 0;
		ft_printf("%p: ", iso[y]);
		while (x < data->map->width - 1)
		{
			ft_printf("[u=%d, v=%d] ", iso[y][x].u, iso[y][x].v);
			x++;
		}
		y++;
		ft_printf("\n");
	}
}

/** test function */
_X_UNUSED static void	draw_map_2d(void *addr, t_data *data)
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

/**
 * @brief Convert the map to an isometric map
 * 
 * @param data The data structure
 * @return t_point** The isometric map On the format array[array[t_point]],
 *  the map is ready to be drawed
 * @todo
 */
t_point	**map_to_iso(t_data *data)
{
	t_point	**iso_map;
	t_type	x;
	t_type	y;

	iso_map = (t_point **)malloc(sizeof(t_point *) * data->map->height +
		sizeof(t_point) * data->map->height * data->map->width);
	if (!iso_map)
		return (NULL);
	x = -1;
	while (++x < data->map->height)
		iso_map[x] = (t_point *)(iso_map + data->map->height)
					+ x * data->map->width;
	x = -1;
	while (++x < data->map->height)
	{
		y = -1;
		while (++y < data->map->width)
		{
			iso_map[x][y].u = abs((int)(x * cos(45) + y * sin(45)
							* data->width / data->map->width));
			iso_map[x][y].v = abs((int)(y * sin(30) + y * cos(30)
							* data->height / data->map->height));
		}
	}
	return (iso_map);
}

void	*map_drawer(t_data *data, t_point **iso_map)
{
	void	*addr;
	t_type	x;
	t_type	y;
	t_type	pixel;

	addr = mlx_get_data_addr(data->img->img, &data->img->bpp,
			&data->img->size_line, &data->img->endian);
	if (!addr)
		return (NULL);
	x = -1;
	while (++x < data->map->height - 1)
	{
		y = -1;
		while (++y < data->map->width - 1)
		{
			pixel = (iso_map[x][y].u * data->img->size_line +
					iso_map[x][y].v * (data->img->bpp / 8));
			*(unsigned int *)(addr + pixel) = RED + data->map->map[x][y] * 100;
		}
	}
	return (addr);
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
	print_iso(data, iso_map);	// rm
	if (!map_drawer(data, iso_map))
		return (MLX_IMG_ERROR);
	if (mlx_put_image_to_window(data->mlx, data->win, data->img->img, 0, 0) < 0)
		return (MLX_IMG_ERROR);
	free(iso_map);
	return (NO_ERROR);
}

