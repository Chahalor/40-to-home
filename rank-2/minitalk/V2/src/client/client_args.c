/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 11:09:51 by nduvoid           #+#    #+#             */
/*   Updated: 2025/03/10 09:19:06 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "args.h"

__attribute__((cold)) static void	parse_short_args(t_args *args,
	const char *arg[], int *i, const int argc)
{
	if (arg[*i][1] == 'h')
		args->help = true;
	else if (*i + 1 >= argc)
		args->err = true;
	else if (arg[*i][1] == 'k')
	{
		args->crypt = rc4;
		args->key = (char *)arg[*i + 1];
		*i += 1;
	}
	else if (arg[*i][1] == 'p')
	{
		args->pid = ft_atoi(arg[*i + 1]);
		if (args->pid < 0)
			args->err = true;
		*i += 1;
	}
	else if (arg[*i][1] == 'm')
	{
		args->msg = (char *)arg[*i + 1];
		*i += 1;
	}
	else
		args->err = true;
}

__attribute__((cold)) static void	parse_long_args(t_args *args,
	const char *arg[], int *i, const int argc)
{
	if (ft_strncmp(arg[*i], "--help", 7) == 0)
		args->help = true;
	else if (*i + 1 >= argc)
		args->err = true;
	else if (ft_strncmp(arg[*i], "--key=", 6) == 0)
	{
		args->crypt = rc4;
		args->key = (char *)arg[*i] + 6;
		*i += 1;
	}
	else if (ft_strncmp(arg[*i], "--pid=", 6) == 0)
	{
		args->pid = ft_atoi(arg[*i] + 6);
		if (args->pid < 0)
			args->err = true;
		*i += 1;
	}
	else if (ft_strncmp(arg[*i], "--msg=", 6) == 0)
	{
		args->msg = (char *)arg[*i] + 6;
		*i += 1;
	}
	else
		args->err = true;
}

__attribute__((unused, cold)) void	print_help(void)
{
	ft_printf("Usage: ./client [options] [pid] [message]\n"
		"\nOptions:\n"
		"  -h, --help\t\tDisplay this help message\n"
		"  -k, --key=KEY\t\tSet the encryption key\n"
		"  -p, --pid=PID\t\tSet the PID of the server\n"
		"  -m, --msg=MSG\t\tSet the message to send\n"
		"\nExample:\n"
		"  ./client 12345 \"Hello, World!\"\n"
		"  ./client -p 12345 -m \"Hello, World!\"\n"
		"  ./client --pid=12345 --msg=\"Hello, World!\"\n"
		"  ./client --key=secret --pid=12345 --msg=\"Hello, World!\"\n"
		"\nDeveloped By: nduvoid <nduvoid@42mulhouse.fr>\n");
}

__attribute__((unused, cold, pure)) t_args	parse_args(const int argc,
	const char *argv[])
{
	t_args	args;
	int		i;

	if (argc < 2)
	{
		args.err = true;
		return (args);
	}
	args = (t_args){args .msg = (char *)argv[argc - 1], .key = NULL,
		.pid = ft_atoi(argv[argc - 2]),		.crypt = none, .comm = nack,
		.err = false, .help = false};
	i = -1;
	while (++i < argc)
	{
		if (argv[i][0] == '-')
		{
			if (argv[i][1] == '-')
				parse_long_args(&args, argv, &i, argc);
			else
				parse_short_args(&args, argv, &i, argc);
		}
	}
	if ((args.key == NULL && args.crypt != none) || args.pid == 0
		|| args.msg == NULL)
		args.err = true;
	return (args);
}
