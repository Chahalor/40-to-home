/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 10:30:05 by nduvoid           #+#    #+#             */
/*   Updated: 2024/12/19 14:12:25 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	draw_map_2d(void *addr, t_data *data)
{
	int		stepX;
	int		stepY;
	int		step;
	int		screenX;
	int		screenY;
	int		x;
	int		y;
	int		pixel;

	if (!addr)
		return ;
	stepX = data->width / data->map->width;
	stepY = data->height / data->map->height;
	step = ft_min(stepX, stepY);
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
