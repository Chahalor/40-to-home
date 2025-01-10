/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 15:38:15 by nduvoid           #+#    #+#             */
/*   Updated: 2025/01/10 10:00:05 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/** @todo */
int	dbg_print(char *str, ...)
{
	if (DEBUG == 0)
		return (0);
	return (ft_printf("%s", str));
}

/** @todo */
void	dbg_print_map(t_map *map)
{
	t_type	i;
	t_type	j;

	i = -1;
	while (++i < map->height)
	{
		if (!map->map[i])
		{
			ft_printf("│\t├──map->map[%d] %p\n", i, map->map[i]);
			i++;
			continue ;
		}
		if (i == map->height - 1)
			ft_printf("│\t└──");
		else
			ft_printf("│\t├──");
		j = 0;
		while (j < map->width)
		{
			ft_printf("%d ", map->map[i][j]);
			j++;
		}
		ft_printf("\n");
	}
}

/** @todo */
void	dbg_print_image(t_image *img)
{
	if (DEBUG == 0)
		return ;
	ft_printf("data->img %p\n", img);
	ft_printf("\t├──img->img %p\n", img->img);
	ft_printf("\t├──img->bpp %d\n", img->bpp);
	ft_printf("\t├──img->size_line %d\n", img->size_line);
	ft_printf("\t└──img->endian %d\n", img->endian);
}

/** @todo */
void	dbg_print_data(t_data *data)
{
	if (DEBUG == 0)
		return ;
	ft_printf("data %p\n", data);
	ft_printf("├──data->mlx %p\n", data->mlx);
	ft_printf("├──data->win %p\n", data->win);
	ft_printf("├──data->width %d\n", data->width);
	ft_printf("├──data->height %d\n", data->height);
	ft_printf("├──data->map %p\n", data->map);
	ft_printf("├──");
	dbg_print_map(data->map);
	ft_printf("└──");
	dbg_print_image(data->img);
}

/**
 * //rm 
 * test function 
 * */
void	dbg_print_iso(t_data *data, t_point *iso)
{
	int	x = 0;

	if (DEBUG == 0)
		return ;
	if (!iso)
	{
		ft_printf("iso is NULL\n");
		return ;
	}
	x = 0;
	while (x < data->map->height - 1)
	{
		ft_printf("[u=%d, v=%d] ", iso[x].u, iso[x].v);
		x++;
	}
}
