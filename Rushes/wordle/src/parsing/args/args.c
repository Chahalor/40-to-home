/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 09:19:24 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/15 09:59:16 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Headers

/* Global   */
#include "config.h"
#include "types.h"

/* Internal */
#include "_args.h"
#include "args.h"

/* Modules  */
#include "utils.h"

#pragma endregion Headers
#pragma region Functions

/** */
__attribute__((cold)) static int	parse_short_options(
	register const char **argv,
	register int i,
	const int argc,
	t_args *args
)
{
	if ((argv[i][1] == 'h' && !argv[i][2]) || (argv[i][1] == 'H' && !argv[i][2]))
		args->help = TRUE;
	else if ((argv[i][1] == 'v' && !argv[i][2]) || (argv[i][1] == 'V' && !argv[i][2]))
		args->version = TRUE;
	else
		args->invalid = EINVAL;
	return (1);
}

/** */
__attribute__((cold)) static int	parse_long_options(
	register const char **argv,
	register int i,
	const int argc,
	t_args *args
)
{
	if (strcmp(argv[i], "--help") == 0)
		args->help = TRUE;
	else if (strcmp(argv[i], "--version") == 0)
		args->version = TRUE;
	else
		args->invalid = EINVAL;
	return (1);
}

/** */
__attribute__((cold)) t_args	parseur_args(
	register const int argc,
	const char **argv
)
{
	t_args	args = (t_args){
		.argc = argc,
		.argv = (char **)argv,
		.invalid = FALSE,
		.help = FALSE,
		.version = FALSE
	};
	register int	i = 0;

	while (i < argc && !args.invalid && !args.help)
	{
		if (argv[i][0] == '-')
		{
			if (argv[i][i] == '-')
				i += parse_long_options(argv, i, argc, &args);
			else
				i += parse_short_options(argv, i, argc, &args);
		}
	}
	if (args.help)
		show_help();
	else if (args.version)
		show_version(TRUE);
	else if (args.invalid)
		exit_error("Invalid argument", args.invalid);
	return (args);
}

#pragma endregion Functions