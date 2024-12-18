/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 12:03:02 by nduvoid           #+#    #+#             */
/*   Updated: 2024/12/18 14:06:55 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#if DEBUG

/** @todo */
int	main(int argc, const char *argv[])
{
	t_data	*mlx;

	if (argc != 2)
	{
		write(2, "Usage: ", 7);
		write(2, argv[0], ft_strlen(argv[0]));
		write(2, " <file>\n", 8);
		exit(1);
	}
	mlx = init_data(800, 600, (char *)(argv[0] + 2));
	if (!mlx)
	{
		perror("init_data failed");
		exit(MLX_INIT_ERROR);
	}
	mlx->map = parse_file((char *)argv[1]);
	dbg_print_map(mlx->map);
	free(mlx->map);
	destroy_window(mlx);
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
t_error fdf(int	argc, const char *argv[])
{
	t_data	*mlx;

	(void)argc;
	(void)argv;
	mlx = init_data(800, 600, (char *)(argv[0] + 2));
	if (!mlx)
		return (MLX_INIT_ERROR);
	// mlx->map = parse_file((char *)argv[1]);
	// if (!mlx->map)
	// {
	// 	destroy_window(mlx);
	// 	return (PARSE_ERROR);
	// }
	mlx_key_hook(mlx->win, key_hook, mlx);
	mlx_mouse_hook(mlx->win, mouse_hook, mlx);
	mlx_loop(mlx->mlx);
	return (NO_ERROR);
}
