/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 13:47:39 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/16 17:21:13 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Headers

/* Global   */
#include "config.h"
#include "types.h"
#include "formating.h"

/* Internal */
#include "_game.h"
#include "game.h"

/* Modules  */
#include "dico.h"
#include "display.h"
#include "utils.h"
#include "debug.h"

#pragma endregion Headers
#pragma region Functions

static inline void	print_main_info(
	void
)
{
	print_header();
	printf(FULL_CLEAN);
	printf("\n" GREEN);
	print_str_to_art("Welcome to the game");
	printf(RESET "\n");
	printf("choose an option:\n");
	printf("  1. Start game\n");
	printf("  2. Show version\n");
	printf("  3. Exit\n");
}

/** */
__attribute__((always_inline, used)) int	main_menu(
	const t_args args,
	t_dico *restrict dico
)
{
	char	buffer[64] = {0};

	(void)args;
	while (TRUE)
	{
		print_main_info();
		printf(UNDERLINE "Enter your choice" RESET ": ");
		fflush(stdout);
		scanf("%63s", buffer);
		switch (buffer[0])
		{
		case '1':
			start_game(dico);
			break;
		case '2':
			printf("Version: %d.%d.%d\n", VERSION_MAJOR, VERSION_MINOR, VERSION_PATCH);
			break;
		case '3':
			printf("Exiting...\n");
			sleep(1);
			return (0);
		default:
			printf("Invalid option. Please try again.\n");
		}
	}
}


#pragma endregion Functions