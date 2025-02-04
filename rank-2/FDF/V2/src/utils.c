/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 09:50:20 by nduvoid           #+#    #+#             */
/*   Updated: 2025/02/04 15:30:05 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/**
 * @brief This is the function that will be called when the window is closed.
 *  by clicking on the red cross.
 * 
 * @param data The fdf structure.
 * 
 * @return int Always return True.
 */
int	close_hook(t_fdf *data)
{
	exiting(data, no_error, NULL);
	return (True);
}

/**
 * @brief This function is called when an error occurs. This is a cancelation
 * function that will free all the allocated memory and exit the program.
 * 
 * @param fdf The fdf structure.
 * @param code The error code.
 * @param message The error message.
 * 
 * @return void
 */
__attribute__((unused, cold)) void	exiting(t_fdf *fdf, t_error code, const char *message)
{
	if (fdf)
	{
		if (fdf->args)
			free(fdf->args);
		if (fdf->map)
			free_map(fdf->map);
		if (fdf->img)
			if (fdf->img->img)
				mlx_destroy_image(fdf->mlx->mlx, fdf->img->img);
		if (fdf->mlx)
		{
			if (fdf->mlx->win)
				mlx_destroy_window(fdf->mlx->mlx, fdf->mlx->win);
			if (fdf->mlx->mlx)
				mlx_destroy_display(fdf->mlx->mlx);
		}
		free(fdf);
	}
	if (message)
		perror(message);
	exit(code);
}

/**
 * @brief Print the help message. when the -h or --help option is given.
 * 
 * @param name The name of the program.
 * 
 * @return void
 */
__attribute__((unused, cold)) void	print_help(const char *name)
{
	ft_printf("\nUsage: %s [options] <map>\n", name);
	ft_printf("\nOptions:\n");
	ft_printf("  -h, --help\t\t\tDisplay this help\n");
	ft_printf("  -s, --size\t\t\tSet the window size\n");
	ft_printf("  -f, --file <heigth><width>\tSet the map file\n");
	ft_printf("  -t, --type\t\t\tSet the map type\n");
	ft_printf("  -c, --colors <start><end>\tSet the colors\n");
	ft_printf("\nExits code:\n");
	ft_printf("  0\t\t\tNo error\n");
	ft_printf("  1\t\t\tInvalid argument\n");
	ft_printf("  2\t\t\tInvalid file\n");
	ft_printf("  3\t\t\tInvalid map\n");
	ft_printf("  4\t\t\tMLX error\n");
	ft_printf("  5\t\t\tMLX window error\n");
	ft_printf("  6\t\t\tMLX image error\n");
	ft_printf("\nAvailable commands (by pressing space):\n");
	ft_printf("  exit\t\t\tExit the program\n");
	ft_printf("  quit/q\t\tQuit the cmd\n");
	ft_printf("  help\t\t\tDisplay this help\n");
	ft_printf("  reset\t\t\tReset the program\n");
	ft_printf("  zoom\t\t\tZoom the model\n");
	ft_printf("  rotate\t\tRotate the model\n");
	ft_printf("  move\t\t\tMove the model\n");
	ft_printf("  draw\t\t\tDraw the model\n");
}
