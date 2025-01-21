/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 10:37:02 by nduvoid           #+#    #+#             */
/*   Updated: 2025/01/16 12:22:10 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/**
 * @brief Parse the arguments passed to the program.
 * @note the following options are available:
 * -s or --size <width> <heigth> Set the width and the heigth of the window
 * -t or --title <title> Set the title of the window
 * -p or --path <path> Set the path of the file to parse  
 * if -p is not set, the proram will take the last argument as the path
 * -h or --help Display the help message @todo
 */

/**
 * @brief Parse the arguments passed to the program.
 * @note the following options are available:  
 * -s <width> <heigth> Set the width and the heigth of the window
 * -t <title> Set the title of the window
 * -p <path> Set the path of the file to parse
 * if -p is not set, the proram will take the last argument as the path
 * 
 * @param argc The number of arguments
 * @param argv The arguments
 * @return t_args* The arguments structure
 */
void	short_options(t_args *args, const char *argv[], int *i)
{
	if (argv[*i][1] == 's')
	{
		args->width = ft_atoi(argv[*i + 1]);
		args->height = ft_atoi(argv[*i + 2]);
		*i += 2;
	}
	else if (argv[*i][1] == 't')
		args->title = (char *)argv[++(*i)];
	else if (argv[*i][1] == 'p')
		args->path = (char *)argv[++(*i)];
	else if (argv[*i][1] == 'h')
		args->help = TRUE;
	else
		args->invalid = TRUE;
}

/**
 * @brief Parse the arguments passed to the program.
 * @note the following options are available:  
 * --size <width> <heigth> Set the width and the heigth of the window
 * --title <title> Set the title of the window
 * --path <path> Set the path of the file to parse
 * if --path is not set, the proram will take the last argument as the path
 * --no-header Do not display the header
 */
void	long_options(t_args *args, const char *argv[], int *i)
{
	if (ft_strncmp(argv[*i], "--size", 7) == 0)
	{
		args->width = ft_atoi(argv[*i + 1]);
		args->height = ft_atoi(argv[*i + 2]);
		*i += 2;
	}
	else if (ft_strncmp(argv[*i], "--title", 8) == 0)
		args->title = (char *)argv[++(*i)];
	else if (ft_strncmp(argv[*i], "--path", 7) == 0)
		args->path = (char *)argv[++(*i)];
	else if (ft_strncmp(argv[*i], "--help", 7) == 0)
		args->help = TRUE;
	else if (ft_strncmp(argv[*i], "--no-header", 12) == 0)
		args->header = FALSE;
	else
		args->invalid = TRUE;
}

/** @todo */
t_args	*parse_args(int argc, const char *argv[])
{
	t_args	*args;
	int		i;

	if (argc < 2)
		return (help(), NULL);
	args = (t_args *)ft_calloc(1, sizeof(t_args));
	if (!args)
		exiting(MALLOC_ERROR, "parse_args failed", NULL);
	*args = (t_args){.argc = argc, .argv = argv, .width = 1600, .height = 1200,
		.title = "fdf", .path = NULL, .help = FALSE, .invalid = FALSE,
		.header = TRUE};
	i = 0;
	while (++i < argc)
	{
		if (argv[i][0] == '-' && argv[i][1] != '-')
			short_options(args, argv, &i);
		else if (argv[i][0] == '-' && argv[i][1] == '-')
			long_options(args, argv, &i);
	}
	return (args);
}

/** @todo */
void	help(void)
{
	ft_printf("Usage: fdf [options] <file>\n");
	ft_printf("\nDescription:\n");
	ft_printf("A simple 3D wireframe renderer\n");
	ft_printf("\nOptions:\n");
	ft_printf("  -s, --size <width> <heigth> Set the width and the heigth \
		of the window\n");
	ft_printf("  -t, --title <title> Set the title of the window\n");
	ft_printf("  -p, --path <path> Set the path of the file to parse\n");
	ft_printf("  -h, --help Display the help message\n");
	ft_printf("      --no-header Do not display the header\n");
	ft_printf("\nExample:\n");
	ft_printf("  fdf -s 1600 1200 -t \"fdf\" -p \"maps/42.fdf\"\n");
	ft_printf("  fdf --size 1600 1200 --title \"fdf\" --path \
		\"maps/42.fdf\"\n");
	ft_printf("  fdf maps/42.fdf\n");
}

/** @todo */
t_args	*do_args(t_args *args)
{
	if (args->invalid)
	{
		ft_printf("Invalid arguments\n");
		return (help(), free(args), NULL);
	}
	else if (!args->path)
		args->path = (char *)args->argv[args->argc - 1];
	if (args->help)
		return (help(), args);
	if (!args->header)
		ft_printf("the --no-header option is not implemented yet\n");
	return (args);
}

//rm
// void	print_args(t_args *args)
// {
// 	ft_printf("%p:\n", args);
// 	ft_printf("├──argc: %d\n", args->argc);
// 	ft_printf("├──argv: %s\n", args->argv[0]);
// 	ft_printf("├──width: %d\n", args->width);
// 	ft_printf("├──height: %d\n", args->height);
// 	ft_printf("├──title: %s\n", args->title);
// 	ft_printf("├──path: %s\n", args->path);
// 	ft_printf("├──help: %d\n", args->help);
// 	ft_printf("└──invalid: %d\n", args->invalid);
// }
