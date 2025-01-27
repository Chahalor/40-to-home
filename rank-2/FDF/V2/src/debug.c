/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 10:46:48 by nduvoid           #+#    #+#             */
/*   Updated: 2025/01/27 11:41:10 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	d_print_args(t_args *args)
{
	if (DEBUG == 0)
		return ;
	if (args == NULL)
	{
		ft_printf("args = NULL\n");
		return ;
	}
	ft_printf("args = %p\n", args);
	ft_printf("├──args->type = %d\n", args->type);
	ft_printf("├──args->help = %d\n", args->help);
	ft_printf("├──args->invalid = %d\n", args->invalid);
	ft_printf("├──args->width = %d\n", args->width);
	ft_printf("├──args->height = %d\n", args->height);
	ft_printf("├──args->file = %s\n", args->file);
	ft_printf("└──args->invalid = %d\n", args->invalid);
}

void	d_print_mlx(t_mlx *mlx)
{
	if (DEBUG == 0)
		return ;
	if (mlx == NULL)
	{
		ft_printf("mlx = NULL\n");
		return ;
	}
	ft_printf("mlx = %p\n", mlx);
	ft_printf("├──mlx->mlx = %p\n", mlx->mlx);
	ft_printf("├──mlx->win = %p\n", mlx->win);
	ft_printf("├──mlx->width = %d\n", mlx->width);
	ft_printf("└──mlx->height = %d\n", mlx->height);
}

void	d_print_map(t_map *map)
{
	int	x;
	int	y;

	if (DEBUG == 0)
		return ;
	if (map == NULL)
	{
		ft_printf("map = NULL\n");
		return ;
	}
	ft_printf("map = %p\n", map);
	ft_printf("├──map->map = %p\n", map->map);
	ft_printf("├──map->iso_map = %p\n", map->iso_map);
	x = -1;
	while (++x < map->height - 1)
	{
		ft_printf("│ ");
		y = -1;
		while (++y < map->width - 1)
			ft_printf("[%d, %d, %d] ", map->iso_map[x][y].x,
				map->iso_map[x][y].y, map->iso_map[x][y].z);
		ft_printf("\n");
	}
	ft_printf("├──map->width = %d\n", map->width);
	ft_printf("└──map->height = %d\n", map->height);
}

void	d_print_image(t_image *img)
{
	if (DEBUG == 0)
		return ;
	if (img == NULL)
	{
		ft_printf("img = NULL\n");
		return ;
	}
	ft_printf("img = %p\n", img);
	ft_printf("├──img->img = %p\n", img->img);
	ft_printf("├──img->bpp = %d\n", img->bpp);
	ft_printf("├──img->size_line = %d\n", img->size_line);
	ft_printf("├──img->endian = %d\n", img->endian);
	ft_printf("└──img->addr = %p\n", img->addr);
}

void	d_print_fdf(t_fdf *fdf)
{
	if (DEBUG == 0)
		return ;
	if (!fdf)
		ft_printf("fdf = %p\n", fdf);
	else
	{
		ft_printf("fdf = %p\n", fdf);
		d_print_args(fdf->args);
		d_print_mlx(fdf->mlx);
		d_print_map(fdf->map);
		d_print_image(fdf->img);
		ft_printf("fdf->pos = %p\n", fdf->pos);
		ft_printf("├──fdf->pos->zoom = %d\n", fdf->pos->zoom);
		ft_printf("├──fdf->pos->rotationx = %f\n", fdf->pos->rotationx);
		ft_printf("├──fdf->pos->rotationy = %f\n", fdf->pos->rotationy);
		ft_printf("├──fdf->pos->paddingx = %d\n", fdf->pos->paddingx);
		ft_printf("└──fdf->pos->paddingy = %d\n", fdf->pos->paddingy);
	}
}
