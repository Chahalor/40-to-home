/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 09:50:20 by nduvoid           #+#    #+#             */
/*   Updated: 2025/01/28 13:15:13 by nduvoid          ###   ########.fr       */
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

void	print_help(const char *name)
{
	ft_printf("Usage: %s [options]\n", name);
	ft_printf("Options:\n");
	ft_printf("  -h, --help\t\t\tDisplay this help\n");
	ft_printf("  -s, --size\t\t\tSet the window size\n");
	ft_printf("  -f, --file <heigth><width>\tSet the map file\n");
	ft_printf("  -t, --type\t\t\tSet the map type\n");
	ft_printf("  -c, --colors <start><end>\tSet the colors\n");
	ft_printf("\nExits code:\n");
	ft_printf("  0\t\t\tNo error\n");
	ft_printf("  1\t\t\tInvalid argument\n");
	ft_printf("  2\t\t\tInvalid file\n");
	ft_printf("  3\t\t\tInvalid map\n");
	ft_printf("  4\t\t\tMLX error\n");
	ft_printf("  5\t\t\tMLX window error\n");
	ft_printf("  6\t\t\tMLX image error\n");
	ft_printf("\nExample:\n");
	ft_printf("  \"%s \" >> Error", name);
	ft_printf("  %s maps/map.fdf\n", name);
	ft_printf("  %s -h\n", name);
	ft_printf("  %s -s 800 600 -f map.fdf\n", name);
}
