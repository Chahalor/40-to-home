/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 11:18:01 by nduvoid           #+#    #+#             */
/*   Updated: 2025/01/21 13:23:51 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	exiting(t_fdf *fdf, t_error code, const char *message)
{
	if (fdf)
	{
		if (fdf->args)
			free(fdf->args);
		if (fdf->map)
			free_map(fdf->map);
		if (fdf->img)
			if (fdf->img->img)
				mlx_destroy_image(fdf->mlx->mlx, fdf->img->img);
		if (fdf->mlx)
		{
			if (fdf->mlx->win)
				mlx_destroy_window(fdf->mlx->mlx, fdf->mlx->win);
			if (fdf->mlx->mlx)
				mlx_destroy_display(fdf->mlx->mlx);
		}
		free(fdf);
	}
	if (message)
		perror(message);
	exit(code);
}
