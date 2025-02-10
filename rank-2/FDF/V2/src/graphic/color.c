/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 19:11:04 by nduvoid           #+#    #+#             */
/*   Updated: 2025/02/10 17:54:29 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/internal_graphic.h"

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
