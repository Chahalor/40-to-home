/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 10:31:07 by nduvoid           #+#    #+#             */
/*   Updated: 2025/02/27 11:53:56 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/internal_args.h"

/**
 * @brief Parse the arguments.
 * 
 * @param argc The number of arguments.
 * @param argv The arguments.
 * 
 * @return The arguments structure.
 * 
 * @note The arguments structure is composed of:
 * 
 * - argc: The number of arguments.
 * 
 * - argv: The arguments.
 * 
 * - file: The file path. (the last argument will be take as a default path)
 * 
 * - height: The window height. (default: 600)
 * 
 * - width: The window width. (default: 800)
 * 
 * - color1: The first color. (default: 0x00FF00)
 * 
 * - color2: The second color. (default: 0x0000FF)
 * 
 * - invalid: Invalid argument.
 * 
 * - help: Display help.
 */
__attribute__((unused, cold)) t_args	*parse_args(int argc,
	char const *argv[])
{
	t_args	*args;

	if (argc < 2)
		exiting(NULL, invalid_argument, "no argument");
	args = (t_args *)ft_calloc(1, sizeof(t_args));
	if (!args)
		exiting(NULL, malloc_error, "parse_args: alloc error");
	args->argc = argc;
	args->argv = argv;
	args->file = argv[argc - 1];
	args->height = DEFAULT_HEIGHT;
	args->width = DEFAULT_WIDTH;
	args->type = DEFAULT_TYPE;
	args->color1 = DEFAULT_COLOR1;
	args->color2 = DEFAULT_COLOR2;
	args->invalid = 0;
	args->help = 0;
	parseur_v2(argc, argv, args);
	if (!is_fdf_file(args->file))
		return (free(args), exiting(NULL, file_error, "not an .fdf file"),
			NULL);
	return (args);
}
