/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 10:12:26 by nduvoid           #+#    #+#             */
/*   Updated: 2025/01/27 14:30:02 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int main(int argc, char const *argv[])
{
	t_args	*args;

	args = parse_args(argc, argv);
	fdf(args);
	return (0);
}

void	fdf(t_args *args)
{
	t_fdf	*fdf_var;

	fdf_var = init_fdf(args);
	if (fdf_var == NULL)
		exiting(fdf_var, mlx_error, "cannot initialize fdf_var");
	setup_hooks(fdf_var);
	fdf_var->map->iso_map = isometric(fdf_var, fdf_var->map, NULL);
	d_print_fdf(fdf_var);
	draw_projection(fdf_var, red, blue);
	mlx_put_image_to_window(fdf_var->mlx->mlx, fdf_var->mlx->win, fdf_var->img->img, 0, 0);
	mlx_loop(fdf_var->mlx->mlx);
}
