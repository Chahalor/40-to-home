/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 08:40:38 by nduvoid           #+#    #+#             */
/*   Updated: 2025/02/11 10:26:06 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/internal_args.h"

/**
 * @brief Check if the short option is supported and valid. if not, set invalid
 * to true.
 * 
 * @param argc The number of arguments.
 * @param argv The arguments given to the programmes.
 * @param x The current index.
 * @param n The number of arguments to check.
 * 
 * @return void
 */
void	parse_short_options2(int argc, const char *argv[], t_args *args, int *x)
{
	if (argv[*x][1] == 'h')
		args->help = true;
	else if (argv[*x][1] == 's' && is_valid_soption(argc, argv, *x, 2))
	{
		args->width = ft_atoi(argv[++*x]);
		args->height = ft_atoi(argv[++*x]);
	}
	else if (argv[*x][1] == 'f' && is_valid_soption(argc, argv, *x, 1))
		args->file = argv[++*x];
	else if (argv[*x][1] == 't' && is_valid_soption(argc, argv, *x, 1))
		args->type = ft_atoi(argv[++*x]);
	else if (argv[*x][1] == 'c' && is_valid_soption(argc, argv, *x, 2))
	{
		args->color1 = ft_atoi(argv[++*x]);
		args->color2 = ft_atoi(argv[++*x]);
	}
	else if (argv[*x][1] == 't' && is_valid_soption(argc, argv, *x, 1))
		args->type = ft_atoi(argv[++*x]);
	else
		args->invalid = true;
}

/**
 * @brief Check if the long option is supported and valid. if not, set invalid
 * to true.
 * 
 * @param argc The number of arguments.
 * @param argv The argumentsgiven to the programmes.
 * @param x The current index.
 * @param n The number of arguments to check.
 * 
 * @return void
 */
void	parse_long_options2(int argc, const char *argv[], t_args *args, int *x)
{
	if (ft_strncmp(argv[*x], "--help", 6) == 0)
		args->help = true;
	else if (ft_strncmp(argv[*x], "--size", 6) == 0 && vl(argc, argv, *x, 2))
	{
		args->width = ft_atoi(argv[++*x]);
		args->height = ft_atoi(argv[++*x]);
	}
	else if (ft_strncmp(argv[*x], "--file", 6) == 0 && vl(argc, argv, *x, 1))
		args->file = argv[++*x];
	else if (ft_strncmp(argv[*x], "--type", 6) == 0 && vl(argc, argv, *x, 1))
		args->type = ft_atoi(argv[++*x]);
	else if (ft_strncmp(argv[*x], "--colors", 8) == 0
		&& vl(argc, argv, *x, 2))
	{
		args->color1 = ft_atoi(argv[++*x]);
		args->color2 = ft_atoi(argv[++*x]);
	}
	else
		args->invalid = true;
}

/**
 * @brief Parse the arguments.
 * 
 * @param argc The number of arguments.
 * @param argv The arguments.
 * @param args The arguments structure.
 * 
 * @return void
 */
void	parseur_v2(int argc, const char *argv[], t_args *args)
{
	int	x;

	x = 0;
	while (++x < argc)
	{
		if (argv[x][0] == '-' && ft_strlen(argv[x]) == 2)
			parse_short_options2(argc, argv, args, &x);
		else if (argv[x][0] == '-' && ft_strlen(argv[x]) > 2)
			parse_long_options2(argc, argv, args, &x);
	}
}
