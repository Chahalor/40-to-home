/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 18:12:35 by nduvoid           #+#    #+#             */
/*   Updated: 2025/02/13 18:19:39 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* -----| Headers |----- */
// Libs
#include <stdlib.h>

// Global
#include "types.h"
#include "config.h"
#include "struct.h"

// Modules
#include "Hear.h"
#include "Translator.h"
#include "Talker.h"

/* -----| Functions |----- */

#if defined(BONUS) && BONUS == 1

/** */
int	main(int argc, const char *argv[])
{
	t_client	*client;

	client = parsing_args(argc, argv);
	if (!client)
		exiting(1, "client: parsing_args: Malloc failed\n", NULL);
	if (client.server_pid == 0)
		exiting(1, "client: parsing_args: Invalid pid\n", NULL);
	client.talker(client.server_pid, client.translator(client.msg));
	// @todo: callback
}

#else

/** */
int	main(int argc, const char *argv[])
{
	t_client	client;

	client = parsing_args(argc, argv, &client);
	if (client.server_pid == 0)
		exiting(1, "client: parsing_args: Invalid pid\n", NULL);
	client.talker(client.server_pid, client.translator(client.msg));
	return (0);
}

#endif	// BONUS