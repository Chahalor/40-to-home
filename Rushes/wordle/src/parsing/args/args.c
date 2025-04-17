/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 09:19:24 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/16 15:52:05 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Headers

/* Global   */
#include "config.h"
#include "types.h"

/* Internal */
#include "_internal/_args.h"
#include "args.h"

/* Modules  */
#include "utils.h"

#pragma endregion Headers
#pragma region Functions

/**
 * @brief	Parses the short options.
 * 
 * @param	const char **argv The arguments passed to the programme.
 * @param	int i The index of the argument to parse.
 * @param	int argc The number of arguments passed to the programme.
 * @param	t_args *args The structure to store the parsed arguments.
 * 
 * @return int The number of arguments parsed.
 */
__attribute__((cold)) static int	parse_short_options(
	register const char **argv,
	register int i,
	const int argc,
	t_args *args
)
{
	(void)argc;
	if ((argv[i][1] == 'h' && !argv[i][2]) || (argv[i][1] == 'H' && !argv[i][2]))
		args->help = TRUE;
	else if ((argv[i][1] == 'v' && !argv[i][2]) || (argv[i][1] == 'V' && !argv[i][2]))
		args->version = TRUE;
	else
		args->invalid = EINVAL;
	return (1);
}

/**
 * @brief	Parses the long options.
 * 
 * @param	const char **argv The arguments passed to the programme.
 * @param	int i The index of the argument to parse.
 * @param	int argc The number of arguments passed to the programme.
 * @param	t_args *args The structure to store the parsed arguments.
 * 
 * @return int The number of arguments parsed.
 */
__attribute__((cold)) static int	parse_long_options(
	register const char **argv,
	register int i,
	const int argc,
	t_args *args
)
{
	(void)argc;
	if (strcmp(argv[i], "--help") == 0)
		args->help = TRUE;
	else if (strcmp(argv[i], "--version") == 0)
		args->version = TRUE;
	else
		args->invalid = EINVAL;
	return (1);
}

/** 
 * @brief	Parses the arguments passed to the programme.
 * 
 * @param	int argc The number of arguments passed to the programme.
 * @param	char **argv The arguments passed to the programme.
 * 
 * @return t_args The structure containing the parsed arguments.
*/
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
	register int	i = 1;

	while (i < argc && !args.invalid && !args.help)
	{
		if (argv[i][0] == '-')
		{
			if (argv[i][i] == '-')
				i += parse_long_options(argv, i, argc, &args);
			else
				i += parse_short_options(argv, i, argc, &args);
		}
		else
			++i;
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