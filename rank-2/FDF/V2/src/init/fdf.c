/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 10:12:26 by nduvoid           #+#    #+#             */
/*   Updated: 2025/02/10 18:03:25 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/internal_init.h"

/**
 * @author nduvoid
 * 
 * @brief This is the main function of the program.
 * 
 * @param argc The number of arguments.
 * @param argv The arguments.
 * 
 * @note This function will parse the arguments, initialize the fdf structure,
 * setup the hooks, calculate the isometric map, display the fdf structure and
 * start the mlx loop.
 * 
 * @returns Different exit codes:
 * 
 * - 0: The program ended successfully.
 * 
 * - 1: The program ended with an invalid argument.
 * 
 * - 2: The program ended with an mlx error.
 * 
 * - 3: The program ended with a map error.
 * 
 * - 4: The program ended with a memory error.
 * 
 * - 5: The program ended with a file error.
 * 
 * - 6: The program ended with a color error.
 * 
 * @see parse_args(), init_fdf(), setup_hooks(), isometric(), draw_projection()
 */
int	main(int argc, char const *argv[])
{
	t_args	*args;

	args = parse_args(argc, argv);
	if (args == NULL)
		exiting(NULL, invalid_argument, "cannot parse arguments");
	else if (args->help)
		return (print_help(argv[0]), free(args), 0);
	fdf(args);
	return (0);
}

/**
 * @brief This function is the main function of the program. It will initialize
 * the fdf structure, setup the hooks, calculate the isometric map, display the
 * fdf structure and start the mlx loop. All logic diffrent than parsing args
 * is here.
 * 
 * @param args The arguments structure.
 */
__attribute__((unused, cold)) void	fdf(t_args *args)
{
	t_fdf	*fdf_var;

	fdf_var = init_fdf(args);
	if (fdf_var == NULL)
		exiting(fdf_var, mlx_error, "cannot initialize fdf_var");
	setup_hooks(fdf_var);
	fdf_var->map->iso_map = projection(fdf_var, fdf_var->map, fdf_var->map->iso_map);
	draw_projection(fdf_var);
	mlx_put_image_to_window(fdf_var->mlx->mlx, fdf_var->mlx->win,
		fdf_var->img->img, 0, 0);
	mlx_loop(fdf_var->mlx->mlx);
}
