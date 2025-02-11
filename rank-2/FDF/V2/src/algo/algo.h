/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 10:38:53 by nduvoid           #+#    #+#             */
/*   Updated: 2025/02/11 11:22:33 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGO_H
# define ALGO_H

# pragma once

/* -----| Header |----- */
// Global
//...

// Local
//...

// modules
//...

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

// projection.c

t_point	**projection(t_fdf *fdf, t_map *map, t_point **points);
t_point	calculate_iso(t_fdf *fdf, t_map *map, int i, int j);
t_point	calculate_rev(t_fdf *fdf, t_map *map, int x, int y);

/* -----| Static |----- */
//...

/* -----| Extern |----- */
//...

/* -----| Inline |----- */
//...

#endif	// ALGO_H