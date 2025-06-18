/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MegaPhone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 10:51:40 by nduvoid           #+#    #+#             */
/*   Updated: 2025/06/18 11:21:16 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Headers

/* -----| standars |----- */
#include <iostream>
#include <string>

/* -----| Global   |----- */
#include "macro.hpp"

/* -----| Internal |----- */
#include "MegaPhone.hpp"


#pragma endregion Headers
#pragma region    Functions

static inline void	_usage(void)
{
	ERROR(
		"@TODO: usage"
	);
}

static inline void	_help(void)
{
	PRINT(
		"@TODO: help"
	);
	exit(EXIT_SUCCESS);
}

static inline t_args	_parser(
	char const *argv[],
	const int argc
)
{
	t_args	args = (t_args){
		.argv = argv,
		.argc = argc,
		.message = NULL,
		.help = false,
		.error = false
	};
	register int	i = 0;
	std::string		current = NULL;

	if (argc < 1)
	{
		_usage();
		args.error = true;
		return (args);
	}

	current = argv[1];
	if (current == "-h" || current == "--help")
		_help();
	while (++i < argc)
		args.message += argv[i];
	return (args);
}

static inline std::string	_to_upper(
	std::string message
)
{
	register int	i = -1;

	while (message[++i])
		message[i] = toupper(message[i]);
	return (message);
}

#pragma endregion Functions
#pragma region    Main

int main(int argc, char const *argv[])
{
	const t_args	args = _parser(argv, argc);

	if (unlikely(args.error))
		return (EXIT_FAILURE);
	else
		PRINT(_to_upper(args.message));
	return (EXIT_SUCCESS);
}

#pragma endregion Mains