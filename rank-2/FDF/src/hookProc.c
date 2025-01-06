/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hookProc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 10:55:09 by nduvoid           #+#    #+#             */
/*   Updated: 2025/01/06 12:15:45 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_hook(int keycode, t_data *data)
{
	if (DEBUG == 1)
		ft_printf("keycode: %d\n", keycode);
	if (keycode == K_ESC)
		exiting(NO_ERROR, NULL, data);
	return (TRUE);
}

int	mouse_hook(int button, int x, int y, t_data *data)
{
	(void)data;
	if (DEBUG == 1)
	{
		if (button == 1)
			ft_printf("left click at %d, %d\n", x, y);
		else if (button == 2)
			ft_printf("right click at %d, %d\n", x, y);
		else if (button == 3)
			ft_printf("middle click at %d, %d\n", x, y);
		else if (button == 4)
			ft_printf("scroll up at %d, %d\n", x, y);
		else if (button == 5)
			ft_printf("scroll down at %d, %d\n", x, y);
		else
			ft_printf("button %d at %d, %d\n", button, x, y);
	}
	return (TRUE);
}

int	close_hook(t_data *data)
{
	exiting(NO_ERROR, NULL, data);
	return (TRUE);
}
