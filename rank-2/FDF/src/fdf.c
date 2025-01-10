/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 12:03:02 by nduvoid           #+#    #+#             */
/*   Updated: 2025/01/10 15:27:42 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#if DEBUG

/** @todo */
int	main(int argc, const char *argv[])
{
	t_args	*args;

	args = do_args(parse_args(argc, argv));
	// print_args(args);
	fdf(args);
	return (NO_ERROR);
}

#else

/** @todo */
int	main(int argc, const char *argv[])
{
	t_args	*args;

	args = do_args(parse_args(argc, argv));
	fdf(args);

	return (1);
}

#endif // DEBUG

/** @todo */
t_error	fdf(t_args *args)
{
	t_data	*mlx;

	mlx = init_data(args->width, args->height, args->title);
	if (!mlx)
		return (MLX_INIT_ERROR);
	mlx->map = parse_file(args->path);
	if (!mlx->map)
		exiting(PARSE_ERROR, NULL, mlx);
	mlx_key_hook(mlx->win, key_hook, mlx);		// find every key interactions
	mlx_mouse_hook(mlx->win, mouse_hook, mlx);	// find every mouse interactions
	mlx_hook(mlx->win, 17, 0, close_hook, mlx);	// check for window close request
	map_to_img_3d(mlx);							// put the "3d" map on the window
	// dbg_print_iso(mlx, mlx->map->iso_map);	// rm
	// draw_fdf(mlx);								// draw the map
	draw_tile(mlx, (t_point){1000, 1000, 0}, 1000, 1000);
	mlx_loop(mlx->mlx);							// idk how its working but it does
	return (NO_ERROR);
}
