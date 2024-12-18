/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 15:38:15 by nduvoid           #+#    #+#             */
/*   Updated: 2024/12/18 13:53:57 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	dbg_print_map(t_map *map)
{
	t_type	i;
	t_type	j;

	i = 0;
	while (i < map->height)
	{
		if (!map->map[i])
		{
			ft_printf("map->map[%d] is NULL\n", i);
			i++;
			continue ;
		}
		j = 0;
		while (j < map->width)
		{
			ft_printf("%d ", map->map[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}
