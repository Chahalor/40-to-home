/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 09:17:36 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/16 15:12:54 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Headers

/* Global   */
#include "config.h"
#include "types.h"
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

/* Internal */
	//...

/* Modules  */
#include "args.h"
#include "dico.h"
#include "game.h"
#include "display.h"
#include "debug.h"

#pragma endregion Headers
#pragma region Functions

int	main(int argc, const char **argv)
{
	const t_args	args = parseur_args(argc, argv);
	t_dico2			*dico = get_dico_info(DEFAULT_DATA_DIR DEFAULT_DICO_FILE);
	
	if (args.invalid || args.help || args.version)
		return (args.invalid);
	
	(void)argc;
	(void)argv;
	debug_print("debug mode: %d\n", DEBUG);
	debug_print_args(&args);
	debug_print_dico(dico);

	srand(time(NULL));
	main_menu(args, dico);
	free_dico(dico);
	return (0);
}

#pragma endregion Functions