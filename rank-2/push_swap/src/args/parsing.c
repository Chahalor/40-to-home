/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 10:27:57 by nduvoid           #+#    #+#             */
/*   Updated: 2025/03/19 13:20:11 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_parsing.h"
#include "parsing.h"

/** */
__attribute__((unused, cold, noreturn))
static inline  void	show_help(void)
{
	ft_printf( BLUE "usage: ./push_swap [options] [stack]\n" RESET);
	ft_printf( YELLOW "options:\n" RESET);
	ft_printf("  -h, --help\t\tshow this help\n" RESET);
	ft_printf("  -s, --stack <stack>\tset the stack to sort\n" RESET);
	ft_printf("  -a, --algo <algo>\tset the algorithm to use\n" RESET);
	ft_printf( YELLOW "\nalgorithms:\n" RESET);
	ft_printf("  1. turkish\n" RESET);
	ft_printf("  2. random\n" RESET);
	ft_printf("  3. miracle\n" RESET);
	exit(EXIT_FAILURE);	/** @todo: change exit code when finish */
}

/** */
__attribute__((unused, cold)) t_args	parse_args(const int argc,
	const char *argv[])
{
	t_args	args;
	int		i;

	args = (t_args){argc, argv, NULL, 0, e_turkish, succes, false};
	if (argc < 2)
		exiting(EINVAL, "  usage: ./push_swap [options] [stack]\n");
	i = 0;
	while (++i < argc && !args.error && !args.help)
	{
		if (argv[i][0] == '-')
		{
			if (argv[i][1] == '-')
				parse_long_options(argc, argv, &i, &args);
			else
				parse_short_options(argc, argv, &i, &args);
		}
		else
			args.stack = _parse_stack(argc, argv, &i, &args);
	}
	if (args.help)
		show_help();
	else
		return (args);
}
