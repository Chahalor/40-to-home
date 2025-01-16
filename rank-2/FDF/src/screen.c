/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 14:37:00 by nduvoid           #+#    #+#             */
/*   Updated: 2025/01/16 13:35:12 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_data	*init_data(t_uint width, t_uint height, char *title)
{
	t_data	*data;

	data = (t_data *)ft_calloc(1, sizeof(t_data));
	if (!data)
		return (NULL);
	data->mlx = mlx_init();
	if (!data->mlx)
		return (free(data), NULL);
	data->height = height;
	data->width = width;
	data->win = mlx_new_window(data->mlx, data->width, data->height, title);
	data->img = (t_image *)ft_calloc(1, sizeof(t_image));
	if (!data->win || !data->img)
		exiting(MLX_INIT_ERROR, NULL, data);
	data->img->img = NULL;
	data->map = NULL;
	data->zoom = 1;
	return (data);
}

void	destroy_window(t_data *data)
{
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
		mlx_destroy_display(data->mlx);
	free(data->mlx);
	free(data);
}
