/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HookProc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:01:17 by nduvoid           #+#    #+#             */
/*   Updated: 2025/01/21 14:14:18 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	key_hook(int keycode, t_fdf *data)
{
	if (DEBUG == 1)
		ft_printf("keycode: %d\n", keycode);
	if (keycode == k_esc)
		exiting(data, no_error, "clean exit");
	if (keycode == k_reset)
	{
		data->pos->rotationx = ANGLE;
		data->pos->rotationy = ANGLE;
		// draw_rotation(data);
	}
	if (keycode == k_up || keycode == k_down || keycode == k_left
		|| keycode == k_right)
	{
		if (keycode == k_up)
			data->pos->rotationy += ROTA_FACTOR;
		else if (keycode == k_down)
			data->pos->rotationy -= ROTA_FACTOR;
		else if (keycode == k_left)
			data->pos->rotationx -= ROTA_FACTOR;
		else if (keycode == k_right)
			data->pos->rotationx += ROTA_FACTOR;
		// draw_rotation(data);
	}
	return (True);
}
	// if (keycode == K_PLUS || keycode == K_MINUS)	// en plus si j ai la place
	// {
	// 	if (keycode == K_PLUS)
	// 		draw_zoom(data, 1);
	// 	else if (keycode == K_MINUS)
	// 		draw_zoom(data, -1);
	// }

static int	mouse_hook(int button, int x, int y, t_fdf *data)
{
	(void)data;
	if (button == 1)
		ft_printf("left click at %d, %d\n", x, y);
	else if (button == 2)
		ft_printf("right click at %d, %d\n", x, y);
	else if (button == 3)
		ft_printf("middle click at %d, %d\n", x, y);
	else if (button == 4)
	{
		// draw_zoom(data, 1);
		ft_printf("scroll up at %d, %d\n", x, y);
	}
	else if (button == 5)
	{
		// draw_zoom(data, -1);
		ft_printf("scroll down at %d, %d\n", x, y);
	}
	else
		ft_printf("button %d at %d, %d\n", button, x, y);
	return (True);
}

static int	mouse_move_hook(int x, int y, t_fdf *data)
{
	(void)x;
	(void)y;
	(void)data;
	// ft_printf("mouse move at %d, %d\n", x, y);
	return (True);
}

static int	close_hook(t_fdf *data)
{
	exiting(data, no_error, "clean exit");
	return (True);
}

void	setup_hooks(t_fdf *data)
{
	mlx_hook(data->mlx->win, 2, 1L << 0, key_hook, data);
	mlx_key_hook(data->mlx->win, key_hook, data);
	mlx_mouse_hook(data->mlx->win, mouse_hook, data);
	mlx_hook(data->mlx->win, 6, 1L << 6, mouse_move_hook, data);
	mlx_hook(data->mlx->win, 17, 1L << 17, close_hook, data);
}
