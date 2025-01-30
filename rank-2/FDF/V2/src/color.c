/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 19:11:04 by nduvoid           #+#    #+#             */
/*   Updated: 2025/01/30 10:35:44 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_uint	get_point_color(t_fdf *fdf, t_point point)
{
	double	percent;
	t_uint	color;

	percent = (point.z - fdf->map->min) / (fdf->map->max - fdf->map->min);
	color = (t_uint)(fdf->pos->color1 * (1 - percent) + fdf->pos->color2 * percent);
	return (color);
}

t_uint	calc_line_color(t_fdf *fd, t_point start, t_point end, t_point cur)
{
	double	percent;
	t_uint	color;

	if (start.z == end.z)
		return (get_point_color(fd, cur));
	percent = (cur.z - start.z) / (end.z - start.z);
	color = (t_uint)(get_point_color(fd, start) * (1 - percent)
			+ get_point_color(fd, end) * percent);
	return (color);
}
