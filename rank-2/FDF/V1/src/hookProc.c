/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hookProc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 10:55:09 by nduvoid           #+#    #+#             */
/*   Updated: 2025/01/20 15:44:33 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_hook(int keycode, t_data *data)
{
	if (DEBUG == 1)
		ft_printf("keycode: %d\n", keycode);
	if (keycode == K_ESC)
		exiting(NO_ERROR, NULL, data);
	if (keycode == K_RESET)
	{
		data->rotationx = ANGLE;
		data->rotationy = ANGLE;
		draw_rotation(data);
	}
	if (keycode == K_UP || keycode == K_DOWN || keycode == K_LEFT
		|| keycode == K_RIGHT)
	{
		if (keycode == K_UP)
			data->rotationy += ROTA_FACTOR;
		else if (keycode == K_DOWN)
			data->rotationy -= ROTA_FACTOR;
		else if (keycode == K_LEFT)
			data->rotationx -= ROTA_FACTOR;
		else if (keycode == K_RIGHT)
			data->rotationx += ROTA_FACTOR;
		draw_rotation(data);
	}
	return (TRUE);
}
	// if (keycode == K_PLUS || keycode == K_MINUS)	// en plus si j ai la place
	// {
	// 	if (keycode == K_PLUS)
	// 		draw_zoom(data, 1);
	// 	else if (keycode == K_MINUS)
	// 		draw_zoom(data, -1);
	// }

int	mouse_hook(int button, int x, int y, t_data *data)
{
	if (button == 1)
		ft_printf("left click at %d, %d\n", x, y);
	else if (button == 2)
		ft_printf("right click at %d, %d\n", x, y);
	else if (button == 3)
		ft_printf("middle click at %d, %d\n", x, y);
	else if (button == 4)
	{
		draw_zoom(data, 1);
		ft_printf("scroll up at %d, %d\n", x, y);
	}
	else if (button == 5)
	{
		draw_zoom(data, -1);
		ft_printf("scroll down at %d, %d\n", x, y);
	}
	else
		ft_printf("button %d at %d, %d\n", button, x, y);
	return (TRUE);
}

int	mouse_move_hook(int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	(void)data;
	// ft_printf("mouse move at %d, %d\n", x, y);
	return (TRUE);
}

int	close_hook(t_data *data)
{
	exiting(NO_ERROR, NULL, data);
	return (TRUE);
}
