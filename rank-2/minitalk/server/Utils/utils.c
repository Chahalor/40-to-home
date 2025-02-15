/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 15:03:27 by nduvoid           #+#    #+#             */
/*   Updated: 2025/02/15 12:04:15 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* -----| Headers |----- */
# include "interne/_Utils.h"
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

/* -----| Functions |----- */

__attribute__((hot))	t_serveur	*get_serveur(void)
{
	// static t_serveur	serveur = (t_serveur){	// @todo: add the rigth functions
	// 	.serveur_pid = getpid(),
	// 	.hear = NULL,
	// 	.translator = NULL
	// 	.talker = NULL,
	// };

	// return (&serveur);
	return (NULL);
}
