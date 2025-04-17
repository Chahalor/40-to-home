/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _args.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 09:42:08 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/16 15:54:35 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Headers

/* Global   */
#include "config.h"
#include "types.h"
#include "formating.h"

/* Internal */
#include "_args.h"
#include "args.h"

/* Modules  */
	//...

#pragma endregion Headers
#pragma region Functions

/**
 * @brief	Print the how to use the programme.
 * 
 * @param	t_bool exiting If true, exit the programme.
 * 
 * @return void
 */
__attribute__((always_inline, used)) inline void	show_usage(
	t_bool exiting
)
{
	printf(BLUE "Usage: " RESET "./wordle [options]\n");
	if (exiting)
		exit(EXIT_EINVAL);
}

/**
 * @brief	Print the version of the programme.
 * 
 * @param	t_bool exiting If true, exit the programme.
 * 
 * @return void
 */
__attribute__((always_inline, used)) inline void	show_version(
	t_bool exiting
)
{
	printf(YELLOW "Version: " RESET "%d.%d.%d\n", VERSION_MAJOR, VERSION_MINOR, VERSION_PATCH);
	if (exiting)
		exit(EXIT_VERSION);
}

/** 
 * @brief	Print the help message.
 * 
 * @param	void
 * 
 * @return void
 * 
 * @note This will exit the programme with the EXIT_HELP code.
*/
__attribute__((always_inline, used)) inline void	show_help(
	void
)
{
	show_usage(FALSE);
	show_version(FALSE);
	printf("\n" YELLOW "Options:\n" RESET);
	printf("  -h, --help\t\tShow this help message and exit\n");
	printf("  -v, --version\t\tShow version information and exit\n");
	printf("\n" YELLOW "Autors:\n" RESET);
	printf("  nduvoid  <" BLUE UNDERLINE "nduvoid@student.42mulhouse.fr" RESET ">\n");
	printf("  chhoflac <" BLUE UNDERLINE "chhoflac@student.42mulhouse.fr" RESET ">\n");
	exit(EXIT_HELP);
}

#pragma endregion Functions
