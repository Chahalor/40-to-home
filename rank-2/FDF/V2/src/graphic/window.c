/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:45:06 by nduvoid           #+#    #+#             */
/*   Updated: 2025/02/27 11:40:26 by nduvoid          ###   ########.fr       */
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
	t_point			crt;
	int				error[2];

	error[0] = abs(end.x - start.x) - abs(end.y - start.y);
	crt = start;
	while (crt.x != end.x || crt.y != end.y)
	{
		if (is_valid_pixel(crt, fdf->img))
			*(int *)(ptr + calc_pixel(crt, fdf->img)) = fdf->pos->color1 \
		- crt.z;
		error[1] = error[0] * 2;
		if (error[1] > 0)
		{
			error[0] -= abs(end.y - start.y);
			crt.x += sign.x;
		}
		if (error[1] < abs(end.x - start.x))
		{
			error[0] += abs(end.x - start.x);
			crt.y += sign.y;
		}
	}
}

__attribute__((hot)) void	draw_line2(t_image *img, t_point start, t_point end)
{
	t_point	crt;

	crt = start;
	while (crt.x != end.x || crt.y != end.y)
	{
		if (is_valid_pixel(crt, img))
			*(int *)(img->addr + calc_pixel(crt, img)) = 0xFFFFFF;
		if (abs(end.x - start.x) > abs(end.y - start.y))
			crt.x += get_s(start.x, end.x);
		else
			crt.y += get_s(start.y, end.y);
	}
}
