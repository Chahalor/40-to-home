/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 18:20:02 by nduvoid           #+#    #+#             */
/*   Updated: 2025/02/13 18:36:56 by nduvoid          ###   ########.fr       */
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
#include "interne/_Translator.h"

/* -----| Functions |----- */

/** */
__attribute__((cold)) t_byte	*translator(const char *msg)
{
	t_byte	*msg_bin;
	int		i;
	int		nb_bit;

	msg_bin = (t_byte *)ft_calloc(ft_strlen(msg) * 8, sizeof(t_byte));
	if (!msg_bin)
		exiting(1, "translator: msg: Malloc failed\n", NULL);
	i = -1;
	while (msg[++i])
	{
		nb_bit = -1;
		while (++nb_bit < 8)
			msg_bin[i * 8 + nb_bit] = (msg[i] >> nb_bit) & 1;
	}
	return (msg_bin);
}
