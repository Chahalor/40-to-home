/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 19:11:04 by nduvoid           #+#    #+#             */
/*   Updated: 2025/02/04 15:23:02 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fdf.h"

/** @todo */
__attribute__((unused)) t_uint	get_point_color(t_fdf *fdf, t_point start,
	t_point end, t_point cur)
{
	int	D;
	int	d;
	int	t;
	int	r;
	int	g;
	int	b;

	D = sqrt(pow(end.x - start.x, 2) + pow(end.y - start.y, 2));
	d = sqrt(pow(cur.x - start.x, 2) + pow(cur.y - start.y, 2));

	if (D == 0)
		D = 1;
	t = d / D;

	r = fdf->pos->color1 >> 16 & 0xFF;
	g = fdf->pos->color1 >> 8 & 0xFF;
	b = fdf->pos->color1 & 0xFF;

	return (t << 24 | r << 16 | g << 8 | b);
}

/** @todo */
__attribute__((unused)) t_uint	calc_line_color(t_fdf *fdf, t_color start,
	t_color end, int percent)
{
	t_uint	color;

	(void)fdf;
	if (start == end)
		return (end);
	color = (t_uint)(end - start) * percent;
	return (color);
}
