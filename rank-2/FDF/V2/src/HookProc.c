/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HookProc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:01:17 by nduvoid           #+#    #+#             */
/*   Updated: 2025/02/03 12:14:54 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fdf.h"

/**
 * @brief This function is called when a key is pressed.
 * 
 * @param keycode The key code.
 * @param data The fdf structure.
 * 
 * @return int Always return True.
 */
int	key_down_hook(int keycode, t_fdf *data)
{
	if (DEBUG == 1)
		ft_printf("key down: %d\n", keycode);
	if (keycode == k_esc)
		exiting(data, no_error, NULL);
	else if (keycode == k_ctrl)
		data->pos->ctrldown = True;
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

/**
 * @brief This function is called when a key is released.
 * 
 * @param keycode The key code.
 * @param data The fdf structure.
 * 
 * @return int Always return True.
 */
int	key_up_hook(int keycode, t_fdf *data)
{
	if (DEBUG == 1)
		ft_printf("key up: %d\n", keycode);
	if (keycode == k_ctrl)
		data->pos->ctrldown = False;
	else if (keycode == k_reset)
	{
		clear_model(data);
		data->pos->zoom = DEFAULT_ZOOM;
		data->pos->rotationx = DEFAULT_ROTATIONX;
		data->pos->rotationy = DEFAULT_ROTATIONY;
		data->pos->paddingx = data->mlx->width / 2;
		data->pos->paddingy = data->mlx->height / 2;
		data->map->iso_map = isometric(data, data->map, data->map->iso_map);
		draw_projection(data);
	}
	else if (keycode == k_spc)
		cmd(data);
	return (True);
}

/**
 * @brief This function is called when a mouse button is pressed.
 * 
 * @param button The button code.
 * @param x The x position of the mouse.
 * @param y The y position of the mouse.
 * @param data The fdf structure.
 * 
 * @return int Always return True.
 */
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

/**
 * @brief This function is called when a mouse button is released.
 * 
 * @param button The button code.
 * @param x The x position of the mouse.
 * @param y The y position of the mouse.
 * @param data The fdf structure.
 * 
 * @return int Always return True.
 */
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

/**
 * @brief This function is called when the mouse is moved.
 * 
 * @param x The x position of the mouse.
 * @param y The y position of the mouse.
 * @param data The fdf structure.
 * 
 * @return int Always return True.
 */
int	mouse_move_hook(int x, int y, t_fdf *data)
{
	static int	last_posx = 0;
	static int	last_posy = 0;

	if (data->pos->ctrldown == 1 && data->pos->lclickdown == 1)
		rotate_model(data, (x - last_posx) / 10, (y - last_posy) / 10);
	else if (data->pos->lclickdown == True)
		translat_model(data, (x - last_posx), (y - last_posy));
	last_posx = x;
	last_posy = y;
	return (True);
}
