/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 12:03:02 by nduvoid           #+#    #+#             */
/*   Updated: 2024/12/19 14:17:14 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#if DEBUG

/** @todo */
int	main(int argc, const char *argv[])
{
	// t_data	*mlx;

	// if (argc != 2)
	// {
	// 	write(2, "Usage: ", 7);
	// 	write(2, argv[0], ft_strlen(argv[0]));
	// 	write(2, " <file>\n", 8);
	// 	exit(1);
	// }
	// mlx = init_data(800, 600, (char *)(argv[0] + 2));
	// if (!mlx)
	// {
	// 	perror("init_data failed");
	// 	exit(MLX_INIT_ERROR);
	// }
	// mlx->map = parse_file((char *)argv[1]);
	// dbg_print_map(mlx->map);
	fdf(argc, argv);
	// map_to_img(mlx);
	return (NO_ERROR);
}

#else

/** @todo */
int	main(int argc, const char *argv[])
{
	t_error	error;

	if (argc != 2)
	{
		write(2, "Usage: ", 7);
		write(2, argv[0], ft_strlen(argv[0]));
		write(2, " <file>\n", 8);
		exit(1);
	}
	error = fdf(argc, argv);
	if (error != NO_ERROR)
		perror("fdf failed");
	return (error);
}

#endif // DEBUG

/** @todo */
t_error	fdf(int argc, const char *argv[])
{
	t_data	*mlx;

	(void)argc;
	mlx = init_data(1600, 1200, (char *)(argv[0] + 2));
	if (!mlx)
		return (MLX_INIT_ERROR);
	mlx->map = parse_file((char *)argv[1]);
	if (!mlx->map)
		exiting(PARSE_ERROR, NULL, mlx);
	mlx_key_hook(mlx->win, key_hook, mlx);		// find every key interactions
	mlx_mouse_hook(mlx->win, mouse_hook, mlx);	// find every mouse interactions
	mlx_hook(mlx->win, 17, 0, close_hook, mlx);	// check for window close request
	map_to_img_2d(mlx);
	mlx_loop(mlx->mlx);
	return (NO_ERROR);
}
