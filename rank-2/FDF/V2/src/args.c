/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 10:31:07 by nduvoid           #+#    #+#             */
/*   Updated: 2025/01/21 13:39:04 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/** @todo */
void	parse_short_options(int argc, char const *argv[], t_args *args)
{
	int	x;

	x = 1;
	while (x < argc)
	{
		if (argv[x][0] != '-' || argv[x][2] != '\0')
			x++;
		else if (argv[x][1] == 'h')
			args->help = True;
		else if (argv[x][1] == 's')
		{
			if (x + 2 < argc)
			{
				args->width = ft_atoi(argv[++x]);
				args->height = ft_atoi(argv[++x]);
			}
			else
				args->invalid = True;
		}
		else if (argv[x][1] == 'h')
			args->help = True;
		else if (argv[x][1] == 'f')
			if (x + 1 < argc)
				args->file = argv[++x];
			else
				args->invalid = True;
		else if (argv[x][1] == 't')
			if (x + 1 < argc)
				args->type = ft_atoi(argv[++x]);
			else
				args->invalid = True;
		else if (argv[x][1] == 'p')
			if (x + 1 < argc)
				args->file = argv[++x];
			else
				args->invalid = True;
		else
			args->invalid = True;
		x++;
	}
}

/** @todo */
void	parse_long_options(int argc, char const *argv[], t_args *args)
{
	int	x;

	x = 1;
	while (x < argc)
	{
		if (ft_strncmp(argv[x], "--help", 6) == 0)
			args->help = True;
		else if (ft_strncmp(argv[x], "--size", 6) == 0)
		{
			if (x + 2 < argc)
			{
				args->width = ft_atoi(argv[++x]);
				args->height = ft_atoi(argv[++x]);
			}
			else
				args->invalid = True;
		}
		else if (ft_strncmp(argv[x], "--file", 6) == 0)
			if (x + 1 < argc)
				args->file = argv[++x];
			else
				args->invalid = True;
		else if (ft_strncmp(argv[x], "--type", 6) == 0)
			if (x + 1 < argc)
				args->type = ft_atoi(argv[++x]);
			else
				args->invalid = True;
		else if (ft_strncmp(argv[x], "--path", 6) == 0)
			if (x + 1 < argc)
				args->file = argv[++x];
			else
				args->invalid = True;
		else
			args->invalid = True;
		x++;
	}
}

/** @todo */
t_args	*parse_args(int argc, char const *argv[])
{
	t_args	*args;

	args = (t_args *)ft_calloc(1, sizeof(t_args));
	if (!args)
		return (NULL);
	args->argc = argc;
	args->argv = argv;
	args->file = NULL;
	args->height = DEFAULT_HEIGHT;
	args->width = DEFAULT_WIDTH;
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
