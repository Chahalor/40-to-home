/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 12:03:02 by nduvoid           #+#    #+#             */
/*   Updated: 2025/01/20 15:30:51 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#if DEBUG

/** @todo */
int	main(int argc, const char *argv[])
{
	t_args	*args;

	ft_printf("🔧 DEBUG MODE\n");
	args = do_args(parse_args(argc, argv));
	exiting(fdf(args), NULL, NULL);
	return (NO_ERROR);
}

#else

/** @todo */
int	main(int argc, const char *argv[])
{
	t_args	*args;

	args = do_args(parse_args(argc, argv));
	exiting(fdf(args), NULL, NULL);
	return (NO_ERROR);
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
	mlx_key_hook(mlx->win, key_hook, mlx);
	mlx_mouse_hook(mlx->win, mouse_hook, mlx);
	mlx_hook(mlx->win, 17, 0, close_hook, mlx);
	mlx_hook(mlx->win, MotionNotify, PointerMotionMask, mouse_move_hook, mlx);
	map_to_img_3d(mlx);
	draw_fdf(mlx);
	mlx_loop(mlx->mlx);
	return (NO_ERROR);
}
