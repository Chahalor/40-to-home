/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:45:06 by nduvoid           #+#    #+#             */
/*   Updated: 2025/02/19 15:35:15 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/internal_graphic.h"
#include "internal/internal_window.h"

/**
 * @brief This function will draw a line between two points.
 * 
 * @param fdf The fdf structure.
 * @param start The start point.
 * @param end The end point.
 * 
 * @return void
 */
__attribute__((hot)) void	draw_line(t_fdf *fdf, t_point start, t_point end,
	void *ptr)
{
	const t_point	sign = {get_s(start.x, end.x), get_s(start.y, end.y), 0};
	const int		dist = get_dist(start, end);
	t_point			cur;
	int				error[2];

	error[0] = abs(end.x - start.x) - abs(end.y - start.y);
	cur = start;
	while (cur.x != end.x || cur.y != end.y)
	{
		if (is_valid_pixel(cur, fdf->img))
			*(int *)(ptr + calc_pixel(cur, fdf->img)) = fdf->pos->color1
				- cur.z;
		error[1] = error[0] * 2;
		if (error[1] > -abs(end.y - start.y))
		{
			error[0] -= abs(end.y - start.y);
			cur.x += sign.x;
		}
		if (error[1] < abs(end.x - start.x))
		{
			error[0] += abs(end.x - start.x);
			cur.y += sign.y;
		}
		cur.z += dist / fdf->map->nb_high;
	}
}
