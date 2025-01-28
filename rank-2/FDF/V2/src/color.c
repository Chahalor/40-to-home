/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 19:11:04 by nduvoid           #+#    #+#             */
/*   Updated: 2025/01/28 17:33:25 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_uint	calculate_color(t_fdf *fdf, int curent)
{
	t_uint	color;
	double	percent;

	if (fdf->map->max == fdf->map->min)
		return (fdf->pos->color1);
	percent = (curent - fdf->map->min) / (double)(fdf->map->max - fdf->map->min);
	color = (fdf->pos->color1 + fdf->pos->color2) * (1 + percent);
	return (color);
}

t_uint	calc_line_color(t_point s, t_point e, t_point cur, t_uint colors[2])
{
	t_uint	color;
	double	percent;

	if (s.x == e.x)
		percent = (cur.y - s.y) / (double)(e.y - s.y);
	else
		percent = (cur.x - s.x) / (double)(e.x - s.x);
	color = (colors[0] + colors[1]) * (1 + percent);
	return (color);
}
