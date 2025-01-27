/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HookProc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:01:17 by nduvoid           #+#    #+#             */
/*   Updated: 2025/01/27 14:57:08 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_hook(int keycode, t_fdf *data)
{
	if (DEBUG == 1)
		ft_printf("keycode: %d\n", keycode);
	if (keycode == k_esc)
		exiting(data, no_error, NULL);
	else if (keycode == k_reset)
	{
		draw_projection(data, black, black);
		data->pos->zoom = DEFAULT_ZOOM;
		data->pos->rotationx = 50.0;
		data->pos->rotationy = -30.0;
		data->pos->paddingx = data->mlx->width / 2;
		data->pos->paddingy = data->mlx->height / 2;
		zoom_model(data, 0);
		rotate_model(data, 0, 0);
		translat_model(data, 0, 0);
	}
	else if (keycode == k_up)
		translat_model(data, 0, -SCALE);
	else if (keycode == k_down)
		translat_model(data, 0, SCALE);
	else if (keycode == k_left)
		translat_model(data, -SCALE, 0);
	else if (keycode == k_right)
		translat_model(data, SCALE, 0);
	return (True);
}

int	mouse_hook_down(int button, int x, int y, t_fdf *data)
{
	if (button == 1)
	{
		ft_printf("left down click at %d, %d\n", x, y);
		data->pos->lclickdown = True;
	}
	else if (button == 2)
	{
		ft_printf("right down click at %d, %d\n", x, y);
		data->pos->rclickdown = True;
	}
	else if (button == 3)
		ft_printf("middle down click at %d, %d\n", x, y);
	else if (button == 4)
	{
		ft_printf("scroll up at %d, %d\n", x, y);
		zoom_model(data, 1);
	}
	else if (button == 5)
	{
		ft_printf("scroll down at %d, %d\n", x, y);
		zoom_model(data, -1);
	}
	else
		ft_printf("button %d at %d, %d\n", button, x, y);
	return (True);
}

int	mouse_hook_up(int button, int x, int y, t_fdf *data)
{
	if (button == 1)
	{
		ft_printf("left up click at %d, %d\n", x, y);
		data->pos->lclickdown = False;
	}
	else if (button == 2)
	{
		ft_printf("right up click at %d, %d\n", x, y);
		data->pos->rclickdown = False;
	}
	else if (button == 3)
		ft_printf("middle up click at %d, %d\n", x, y);
	return (True);
}

int	mouse_move_hook(int x, int y, t_fdf *data)
{
	static int	last_posx = 0;
	static int	last_posy = 0;

	if (data->pos->lclickdown == -1)
		rotate_model(data, x - last_posx, y - last_posy);
	last_posx = x;
	last_posy = y;
	return (True);
}

int	close_hook(t_fdf *data)
{
	exiting(data, no_error, NULL);
	return (True);
}
