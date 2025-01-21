/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 10:12:26 by nduvoid           #+#    #+#             */
/*   Updated: 2025/01/21 15:04:31 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int main(int argc, char const *argv[])
{
	t_args	*args;

	args = parse_args(argc, argv);
	d_print_args(args, 0);
	fdf(args);
	return (0);
}

void	fdf(t_args *args)
{
	t_fdf	*fdf_var;

	fdf_var = init_fdf(args);
	if (fdf_var == NULL)
		exiting(fdf_var, mlx_error, "cannot initialize fdf_var");
	d_print_fdf(fdf_var);
	setup_hooks(fdf_var);
	isometric(fdf_var, fdf_var->map);
	draw_projection(fdf_var, red, blue);
	mlx_loop(fdf_var->mlx->mlx);
}
