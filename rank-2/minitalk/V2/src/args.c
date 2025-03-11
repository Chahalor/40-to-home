/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 10:14:03 by nduvoid           #+#    #+#             */
/*   Updated: 2025/03/11 12:08:41 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/** */
__attribute__((unused, cold, noreturn)) void	show_help(void)
{
	ft_printf("usage: ./client [options] <pid> <message>\n");
	ft_printf("options:\n");
	ft_printf("  -h, --help\t\tshow this help message and exit\n");
	ft_printf("  -n, --name <name>\tset the name of the client\n");
	ft_printf("  -p, --pid <pid>\tset the pid of the server\n");
	ft_printf("  -m, --msg <msg>\tset the message to send\n");
	ft_printf("\nExemple:\n");
	ft_printf("  ./client 1234 \"Hello World\"\n");
	ft_printf("  ./client -n \"My name\" -p 1234 -m \"Hello World\"\n");
	exit(0);
}

/** */
__attribute__((cold)) static void	parse_short_args(const int argc,
	char *argv[], t_args *args, int *i)
{
	const char	c = argv[*i][1];

	if (c == 'h')
		show_help();
	else if (*i + 1 >= argc)
	{
		args->err = einval;
		return ;
	}
	else if (c == 'n')
		args->name = ft_strdup(argv[*i + 1]);
	else if (c == 'p')
		args->pid = ft_atoi(argv[*i + 1]);
	else if (c == 'm')
		args->msg = (char *)argv[*i + 1];
	else
		args->err = einval;
	*i += 1 * (args->err == 0);
	return ;
	
}

/** */
__attribute__((cold)) static void	parse_long_option(const int argc,
	char *argv[], t_args *args, int *i)
{
	if (ft_strncmp(argv[*i], "--help", 6) == 0)
		show_help();
	else if (*i + 1 >= argc)
	{
		args->err = einval;
		return ;
	}
	else if (ft_strncmp(argv[*i], "--name", 6) == 0)
		args->name = ft_strdup(argv[*i + 1]);
	else if (ft_strncmp(argv[*i], "--pid", 5) == 0)
		args->pid = ft_atoi(argv[*i + 1]);
	else if (ft_strncmp(argv[*i], "--msg", 5) == 0)
		args->msg = (char *)argv[*i + 1];
	else
		args->err = einval;
	*i += 1 * (args->err == 0);
	return ;
}

/** */
__attribute__((unused, cold)) t_args	parse_args(int argc, char *argv[])
{
	t_args	args;
	int		i;

	i = 1;
	if (argc < 3)
		args.err = einval;
	args = (t_args){.msg = argv[argc - 1], .pid = ft_atoi(argv[argc - 2]),
		.name = NULL, .err = 0, .help = 0};
	while (i < argc && !args.err && !args.help)
	{
		if (argv[i][0] == '-')
		{
			if (argv[i][1] == '-')
				parse_long_option(argc, argv, &args, &i);
			else
				parse_short_args(argc, argv, &args, &i);
		}
		++i;
	}
	if (args.err)
		exiting(args.err, "usage: ./client [options] <pid> <message>");
	else if (!args.name)
		args.name = ft_strdup("");
	return (args);
}
