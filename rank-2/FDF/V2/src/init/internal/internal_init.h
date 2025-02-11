/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internal_init.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 12:22:54 by nduvoid           #+#    #+#             */
/*   Updated: 2025/02/11 09:53:51 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERNAL_INIT_H
# define INTERNAL_INIT_H

# pragma once

/* -----| Header |----- */
// Global
# include <fcntl.h>
# include <stdlib.h>

// Local
# include "struct.h"
# include "type.h"
# include "libft.h"
# include "mlx.h"
# include "mlx_int.h"
# include "config.h"

// modules
# include "args.h"
# include "algo.h"
# include "init.h"
# include "graphic.h"
# include "utils.h"
# include "debug.h"

/* -----| Define |----- */
//...

/* -----| Macro |----- */
//...

/* -----| Typedef |----- */
//...

/* -----| Enum |----- */
//...

/* -----| Union |----- */
//...

/* -----| Struct |----- */
//...

/* -----| Prototype |----- */

t_fdf	*init_fdf(t_args *args);
void	setup_hooks(t_fdf *data);

/* -----| Static |----- */
//...

/* -----| Extern |----- */
//...

/* -----| Inline |----- */

/** @todo */
__attribute__((cold, unused)) static inline int	get_nb_high(t_map *map)
{
	int	x;
	int	y;
	int	nb_high;

	x = -1;
	nb_high = 0;
	while (++x < map->height - 1)
	{
		y = -1;
		while (++y < map->width - 1)
			if (map->map[x][y] > 0)
				nb_high++;
	}
	return (nb_high);
}

/** @todo */
__attribute__((cold, unused)) static inline void	get_map_min(t_map *map)
{
	int	x;
	int	y;

	x = -1;
	while (++x < map->height - 1)
	{
		y = -1;
		while (++y < map->width - 1)
			if (map->map[x][y] < map->min)
				map->min = map->map[x][y];
	}
}

/** @todo */
__attribute__((cold, unused)) static inline void	get_map_max(t_map *map)
{
	int	x;
	int	y;

	x = -1;
	while (++x < map->height - 1)
	{
		y = -1;
		while (++y < map->width - 1)
			if (map->map[x][y] > map->max)
				map->max = map->map[x][y];
	}
}

#endif	// INTERNAL_INIT_H