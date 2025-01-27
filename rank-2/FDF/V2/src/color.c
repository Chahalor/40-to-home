/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 19:11:04 by nduvoid           #+#    #+#             */
/*   Updated: 2025/01/27 19:59:54 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_color	calculate_color(int min, int max, int current, t_color colors[2])
{
	t_color	color;
	double	percent;

	if (current == max)
		return (colors[1]);
	if (current == min)
		return (colors[0]);
	percent = (double)(current - min) / (max - min);
	color.r = (int)((1 - percent) * colors[0].r + percent * colors[1].r);
	color.g = (int)((1 - percent) * colors[0].g + percent * colors[1].g);
	color.b = (int)((1 - percent) * colors[0].b + percent * colors[1].b);
	return (color);
}
