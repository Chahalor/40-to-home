/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:13:12 by nduvoid           #+#    #+#             */
/*   Updated: 2025/02/13 11:48:23 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* -----| Header |----- */
// Global
#include "struct.h"
#include "type.h"

// Modules
#include "utils.h"

// Internes
#include "interne/_parsing_args.h"

/* -----| Functions | ----- */

/** */
__attribute__((cold)) static t_cmd	*parse_cmd(t_args *args, int argc,
	const char *argv[])
{
	t_cmd	*cmd;
	int		i;
	char	**tmp;

	cmd = (t_cmd *)ft_calloc(argc - 2, sizeof(t_cmd));
	if (!cmd)
		return (NULL);
	i = 1;
	while (++i < argc - 1)
	{
		tmp = ft_split(argv[i], ' ');
		if (!tmp)
			return (NULL);
		cmd[i].bin = NULL;
		cmd[i].cmd = tmp[0];
		cmd[i].args = tmp + 1;
	}
}

/** */
__attribute__((cold)) t_args	*parse_args(int argc, const char *argv[],
	const char *envp[])
{
	t_args	*args;

	args = (t_args *)ft_calloc(1, sizeof(t_args));
	if (!args)
		exiting(malloc_error, "parse_args: cannot allocate memory", NULL, NULL);
	args = &(t_args){
		.infile = argv[1],
		.outfile = argv[argc - 1],
		.cmd = NULL,
		.nb_cmd = argc - 3,
		.path = ft_getenv(envp, "PATH"),
	};
	parse_cmd(args, argc, argv);
	return (args);
}
