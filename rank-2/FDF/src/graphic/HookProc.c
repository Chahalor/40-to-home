/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HookProc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:01:17 by nduvoid           #+#    #+#             */
/*   Updated: 2025/02/27 12:10:16 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/internal_graphic.h"

/**
 * @brief This function is called when a key is pressed.
 * 
 * @param keycode The key code.
 * @param data The fdf structure.
 * 
 * @return int Always return True.
 */
__attribute__((hot)) int	key_down_hook(int keycode, t_fdf *data)
{
	if (DEBUG == 1)
		ft_printf("key down: %d\n", keycode);
	if (keycode == k_ctrl)
		data->pos->ctrldown = true;
	else if (keycode == k_up)
		translat_model(data, 0, -SCALE);
	else if (keycode == k_down)
		translat_model(data, 0, SCALE);
	else if (keycode == k_left)
		translat_model(data, -SCALE, 0);
	else if (keycode == k_right)
		translat_model(data, SCALE, 0);
	else if (keycode == k_esc)
		exiting(data, no_error, NULL);
	return (true);
}

/**
 * @brief This function is called when a key is released.
 * 
 * @param keycode The key code.
 * @param data The fdf structure.
 * 
 * @return int Always return True.
 */
__attribute__((hot)) int	key_up_hook(int keycode, t_fdf *data)
{
	if (DEBUG == 1)
		ft_printf("key up: %d\n", keycode);
	if (keycode == k_ctrl)
		data->pos->ctrldown = false;
	else if (keycode == k_reset)
	{
		data->pos->zoom = DEFAULT_ZOOM;
		data->pos->rotationx = DEFAULT_ROTATIONX;
		data->pos->rotationy = DEFAULT_ROTATIONY;
		data->pos->paddingx = data->mlx->width * 0.5;
		data->pos->paddingy = data->mlx->height * 0.5;
		projection(data, data->map, data->map->iso_map);
		draw_projection(data);
	}
	else if (keycode == k_spc)
		cmd(data);
	else if (keycode == k_w)
		rotate_model(data, 0, 1);
	else if (keycode == k_a)
		rotate_model(data, 1, 0);
	else if (keycode == k_s)
		rotate_model(data, 0, -1);
	else if (keycode == k_d)
		rotate_model(data, -1, 0);
	return (true);
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
__attribute__((hot)) int	mouse_hook_down(int button, int x, int y,
	t_fdf *data)
{
	if (DEBUG == 1)
		ft_printf("button %d down at %d, %d\n", button, x, y);
	if (button == 1)
		data->pos->lclickdown = true;
	else if (button == 2)
		data->pos->rclickdown = true;
	else if (button == 4)
		zoom_model(data, 1);
	else if (button == 5)
		zoom_model(data, -1);
	return (true);
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
__attribute__((hot)) int	mouse_hook_up(int button, int x, int y, t_fdf *data)
{
	if (DEBUG == 1)
		ft_printf("button %d up at %d, %d\n", button, x, y);
	if (button == 1)
		data->pos->lclickdown = false;
	else if (button == 2)
		data->pos->rclickdown = false;
	return (true);
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
__attribute__((hot)) int	mouse_move_hook(int x, int y, t_fdf *data)
{
	static int		last_posx = 0;
	static int		last_posy = 0;
	static t_uint	tkt = 1;

	if (data->pos->ctrldown == 1 && data->pos->lclickdown == 1)
		rotate_model(data, (x - last_posx), (y - last_posy));
	else if (data->pos->lclickdown == true)
		if (tkt++ % 4 == 0)
			translat_model(data, (x - last_posx), (y - last_posy));
	last_posx = x;
	last_posy = y;
	return (true);
}
