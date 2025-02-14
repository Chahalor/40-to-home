/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hear.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 17:42:53 by nduvoid           #+#    #+#             */
/*   Updated: 2025/02/14 09:14:27 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* -----| Headers |----- */
// Libs
#include <stdio.h>

// Global
#include "types.h"
#include "libft.h"
#include "config.h"
#include "libft.h"
#include "struct.h"

// Modules
#include "interne/_Hear.h"
#include "utils.h"
#include "Translator.h"
#include "Talker.h"

/* -----| Functions |----- */

#if defined(BONUS) && BONUS == 1

t_client	parsing_args(const int argc, const char *argv[])
{
	t_client	*client;

	if (argc != 2)
		exiting(1, "Usage: ./client [pid]\n", NULL);
	client = (t_client *)ft_calloc(1, sizeof(t_client));
	if (!client)
		exiting(1, "client: parsing_args: Malloc failed\n", NULL);
	client->server_pid = ft_atoi(argv[1]);
	client->msg = argv[2];
	client->hear = hear;
	client->translator = translator;
	client->callback = callback;
}

#else

void	parsing_args(int argc, const char *argv[], t_client *client)
{
	printf("argc: %d\n", argc);
	printf("argv: %p\n", argv);
	printf("client: %p\n", client);
	if (!argv || !client)
		exiting(1, "Arguments invalides\n", NULL);
	client->server_pid = ft_atoi(argv[1]);
	client->msg = (char *)argv[2];
	client->hear = parsing_args;
	client->translator = translator;
	client->talker = talker;
	client->callback = NULL;
}

#endif	// BONUS