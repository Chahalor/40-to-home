/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 09:50:20 by nduvoid           #+#    #+#             */
/*   Updated: 2025/02/10 18:01:18 by nduvoid          ###   ########.fr       */
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
__attribute__((unused, cold)) int	close_hook(t_fdf *data)
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
	ft_printf("\nUsage: %s [options] <map>\n\nOptions:\n  -h, --help\t\t\t"
		"Display this help\n  -s, --size\t\t\tSet the window size\n  -f, "
		"--file <heigth><width>\tSet the map file\n  -t, --type\t\t\tSet the "
		"map type\n  -c, --colors <start><end>\tSet the colors\n\nExits code:"
		"\n  0\t\t\tNo error\n  1\t\t\tInvalid argument\n  2\t\t\tInvalid file"
		"\n  3\t\t\tInvalid map\n  4\t\t\tMLX error\n  5\t\t\tMLX window error"
		"\n  6\t\t\tMLX image error\n\nAvailable commands (by pressing space):"
		"\n  exit\t\t\tExit the program\n  quit/q\t\tQuit the cmd\n  help\t\t"
		"\tDisplay this help\n  reset\t\t\tReset the program\n  zoom\t\t\t"
		"Zoom the model\n  rotate\t\tRotate the model\n  move\t\t\tMove the "
		"model\n  draw\t\t\tDraw the model\n", name);
}
