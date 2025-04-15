/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 09:17:36 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/15 10:39:04 by nduvoid          ###   ########.fr       */
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

#pragma endregion Headers
#pragma region Functions

int	main(int argc, char **argv)
{
	const t_args	args = parseur_args(argc, argv);
	const t_dico	dico = dico_read_info(DEFAULT_DICO_PATH);
	
	if (args.invalid || args.help || args.version)
		return (args.invalid);
	
	srand(time(NULL));	// init the random seed
	print_main_menu();
	cleaning();	// add the rigth param
	return (0);
}

#pragma endregion Functions