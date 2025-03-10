/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 10:25:58 by nduvoid           #+#    #+#             */
/*   Updated: 2025/03/05 15:41:00 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "config.h"

__attribute__((cold)) void	parse_short_args(t_args *args, int *argc,
	const char *argv)
{
	if (__builtin_expect(argv[1] == 'h', EXPECTED))
		exiting(0, "usage: ./server [-p=1|2] [--print=buff|realloc]\n", NULL);
	else
		args->err = true;
	*argc += 1;
}

__attribute__((cold)) void	parse_long_args(t_args *args, int *argc,
	const char *arg)
{
	if (ft_strncmp(arg, "--print=", 8) == 0 || ft_strncmp(arg, "-p=", 3) == 0)
	{
		if (ft_strncmp(arg + 8, "buff", 4) == 0)
			args->print = buffered;
		else if (ft_strncmp(arg + 8, "realloc", 7) == 0)
			args->print = reallocing;
		else
			args->err = 1;
	}
	else if (ft_strncmp(arg, "--help", 6) == 0)
		exiting(0, "usage: ./server [-p=1|2] [--print=buff|realloc]\n", NULL);
	else
		args->err = 1;
	*argc += 1;
}

/** */
__attribute__((cold, unused)) t_args	parse_args(const int argc, char *argv[])
{
	t_args	args;
	int		i;

	args = (t_args){0};
	i = 0;
	while (++i < argc && !args.err)
	{
		if (argv[i][0] == '-' && ft_strlen(argv[i]) == 2)
			parse_short_args(&args, &i, argv[i]);
		else if (argv[i][0] == '-' && ft_strlen(argv[i]) > 2)
			parse_long_args(&args, &i, argv[i]);
		else
			args.err = 1;
	}
	return (args);
}
