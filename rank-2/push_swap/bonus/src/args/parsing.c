/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 10:27:57 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/01 16:41:37 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_parsing.h"
#include "parsing.h"
#include "utils.h"

/**
 * @brief	Shows the help message. What do you expect ?
 * 
 * @param	void
 * 
 * @return	void
*/
__attribute__((unused, cold, noreturn, always_inline))
static inline	void	show_help(void)
{
	ft_printf(BLUE "usage: ./checker [options] [stack]\n" RESET);
	ft_printf(YELLOW "options:\n" RESET);
	ft_printf("  -h, --help\t\tshow this help\n");
	ft_printf("  -s, --stack <stack>\tset the stack to sort\n");
	ft_printf(YELLOW "authors:\n" RESET);
	ft_printf("  - nduvoid <nduvoid@student.42mulhouse.fr>\n");
	exit(EXIT_FAILURE);
}

/**
 * @brief	Parses the command line arguments and fills the args structure.
 * 
 * @param	argc	The number of arguments.
 * @param	argv	The arguments.
 * 
 * @return	The args structure filled with the parsed arguments.
 */
__attribute__((unused, cold)) t_args	parse_args(const int argc,
	const char *argv[])
{
	t_args	args;
	int		i;

	args = (t_args){argc, argv, NULL, 0, 0, false};
	if (argc < 2)
		exiting(EINVAL, "  usage: ./checker [options] [stack]\n");
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
	else if (args.help)
		show_help();
	return (args);
}
