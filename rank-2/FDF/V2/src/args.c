/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 10:31:07 by nduvoid           #+#    #+#             */
/*   Updated: 2025/02/04 15:20:42 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/**
 * @brief Check if the short option is valid.
 * 
 *  - type: 0 = no args after, 1 = 1 arg after.
 * 
 * @param argc The number of arguments.
 * @param argv The arguments.
 * @param pos The position of the argument.
 * @param nb_args The number of arguments after the option.
 * 
 * @return True if the option is valid, otherwise False.
 */
__attribute__((hot)) static Bool	is_valid_soption(const int argc,
	const char *argv[], int pos, int nb_args)
{
	if (pos >= argc)
		return (False);
	if (argv[pos][0] != '-' || ft_strlen(argv[pos]) != 2
		|| pos + nb_args >= argc)
		return (False);
	return (True);
}

/**
 * @brief Check if the long option is valid.
 * 
 *  - type: 0 = no args after, 1 = 1 arg after.
 * 
 * @param argc The number of arguments.
 * @param argv The arguments.
 * @param pos The position of the argument.
 * @param nb_args The number of arguments after the option.
 * 
 * @return True if the option is valid, otherwise False.
 */
__attribute__((hot))  static Bool	vl(const int argc, const char *argv[],
	int pos, int nb_args)
{
	if (pos >= argc)
		return (False);
	if (ft_strncmp(argv[pos], "--", 2) != 0 || argc + nb_args >= argc)
		return (False);
	return (True);
}

/**
 * @brief Parse the short options. in case of an invalid option, the invalid
 * flag will be set to True.
 * 
 * @param argc The number of arguments.
 * @param argv The arguments.
 * @param args The arguments structure.
 * 
 * @return void
 * */
__attribute__((cold)) void	parse_short_options(int argc, char const *argv[],
	t_args *args)
{
	int	x;

	x = 0;
	while (++x < argc)
	{
		if (argv[x][1] == 'h')
			args->help = True;
		else if (argv[x][1] == 's' && is_valid_soption(argc, argv, x, 2))
		{
			args->width = ft_atoi(argv[++x]);
			args->height = ft_atoi(argv[++x]);
		}
		else if (argv[x][1] == 'f' && is_valid_soption(argc, argv, x, 1))
			args->file = argv[++x];
		else if (argv[x][1] == 't' && is_valid_soption(argc, argv, x, 1))
			args->type = ft_atoi(argv[++x]);
		else if (argv[x][1] == 'c' && is_valid_soption(argc, argv, x, 2))
		{
			args->color1 = ft_atoi(argv[++x]);
			args->color2 = ft_atoi(argv[++x]);
		}
		else
			args->invalid = True;
	}
}

/**
 * @brief Parse the long options. in case of an invalid option, the invalid
 * flag will be set to True.
 * 
 * @param argc The number of arguments.
 * @param argv The arguments.
 * @param args The arguments structure.
 * 
 * @return void
 */
__attribute__((cold)) void	parse_long_options(int argc, char const *argv[],
	t_args *args)
{
	int	x;

	x = 0;
	while (++x < argc)
	{
		if (ft_strncmp(argv[x], "--help", 6) == 0)
			args->help = True;
		else if (ft_strncmp(argv[x], "--size", 6) == 0 && vl(argc, argv, x, 2))
		{
			args->width = ft_atoi(argv[++x]);
			args->height = ft_atoi(argv[++x]);
		}
		else if (ft_strncmp(argv[x], "--file", 6) == 0 && vl(argc, argv, x, 1))
			args->file = argv[++x];
		else if (ft_strncmp(argv[x], "--type", 6) == 0 && vl(argc, argv, x, 1))
			args->type = ft_atoi(argv[++x]);
		else if (ft_strncmp(argv[x], "--colors", 8) == 0
			&& vl(argc, argv, x, 2))
		{
			args->color1 = ft_atoi(argv[++x]);
			args->color2 = ft_atoi(argv[++x]);
		}
		else
			args->invalid = True;
	}
}

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
		return (NULL);
	args->argc = argc;
	args->argv = argv;
	args->file = argv[argc - 1];
	args->height = DEFAULT_HEIGHT;
	args->width = DEFAULT_WIDTH;
	args->color1 = DEFAULT_COLOR1;
	args->color2 = DEFAULT_COLOR2;
	args->invalid = False;
	args->help = False;
	if (argc < 2)
	{
		args->invalid = True;
		return (args);
	}
	parse_short_options(argc, argv, args);
	parse_long_options(argc, argv, args);
	return (args);
}
