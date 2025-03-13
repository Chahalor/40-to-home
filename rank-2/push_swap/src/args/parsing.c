/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 10:27:57 by nduvoid           #+#    #+#             */
/*   Updated: 2025/03/13 13:26:58 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

/** */
__attribute__((unused, cold, noreturn)) void	show_help(void)
{
	ft_printf( RED "@todo show help\n" RESET);
	exit(EXIT_FAILURE);	// change exit code when finish
}

/** */
__attribute__((unused, cold)) t_algo	choose_algo(const char *algo,
	t_error *err)
{
	if (ft_strncmp(algo, "turkish", 7) == 0 || algo[0] == '1')
		return (turkish);
	else if (ft_strncmp(algo, "random", 6) == 0 || algo[0] == '2')
		return (random);
	else if (ft_strncmp(algo, "miracle", 7) == 0 || algo[0] == '3')
		return (miracle);
	else
	{
		*err = EINVAL;
		return (turkish);
	}
}

/** */
__attribute__((cold)) static void	parse_short_options(const int argc,
	const char **argv, int *i, t_args *args)
{
	const char	c = argv[*i][1];

	if (c == 'h')
		args->help = true;
	else if (*i + 1 <= argc)
		args->error = EINVAL;
	else if (c == 's')
		args->stack = argv[++(*i)];
	else if (c == 'a')
		args->algo = choose_algo(argv[++(*i)], &args->error);
	else
		args->error = EINVAL;
}

/** */
__attribute__((cold)) static void	parse_long_options(const int argc,
	const char *argv, int *i, t_args *args)
{
	const char	*option = argv[*i];

	if (ft_strncmp(option, "--help", 6) == 0)
		args->help = true;
	else if (*i + 1 <= argc)
		args->error = EINVAL;
	else if (ft_strncmp(option, "--stack", 8) == 0)
		args->stack = argv[++(*i)];
	else if (ft_strncmp(option, "--algo", 7) == 0)
		args->algo = choose_algo(argv[++(*i)], &args->error);
	else
		args->error = EINVAL;
}

/** */
__attribute__((unused, cold)) t_args	parse_args(const int argc,
	const char *argv[])
{
	t_args	args;
	int		i;

	args = (t_args){argc, argv, argv[argc - 1], turkish, succes, false};
	if (argc < 2)
		exiting(EINVAL, "  usage: ./push_swap [options] [stack]\n");
	i = 0;
	while (++i < argc && !args.error && !args.help)
	{
		if (argv[i][0] == '-')
		{
			if (argv[i][1] == '-')
				parse_long_options(argc, argv[i], &i, &args);
			else
				parse_short_options(argc, argv[i], &i, &args);
		}
	}
	if (args.help)
		show_help();
	return (args);
}
