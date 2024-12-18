/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interactions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 10:55:09 by nduvoid           #+#    #+#             */
/*   Updated: 2024/12/18 12:41:33 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_hook(int keycode, t_data *data)
{
	ft_printf("keycode: %d\n", keycode);
	mlx_clear_window(data->mlx, data->win);
	if (keycode == K_ESC)
	{
		free(data->map);
		destroy_window(data);
		exit(0);
	}
	return (TRUE);
}

int	mouse_hook(int button, int x, int y, t_data *data)
{
	(void)data;
	if (button == 1)
		ft_printf("left click at %d, %d\n", x, y);
	else if (button == 2)
		ft_printf("right click at %d, %d\n", x, y);
	else if (button == 3)
		ft_printf("middle click at %d, %d\n", x, y);
	return (TRUE);
}
