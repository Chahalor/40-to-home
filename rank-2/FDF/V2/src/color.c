/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 19:11:04 by nduvoid           #+#    #+#             */
/*   Updated: 2025/01/27 19:12:31 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_color	calculate_color(int min, int max, int current, t_color start, t_color end)
{
	t_color	color;
	double	percent;

	if (current == max)
		return (end);
	if (current == min)
		return (start);
	percent = (double)(current - min) / (max - min);
	color.red = (int)((1 - percent) * start.red + percent * end.red);
	color.green = (int)((1 - percent) * start.green + percent * end.green);
	color.blue = (int)((1 - percent) * start.blue + percent * end.blue);
	return (color);
}