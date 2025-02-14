/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 15:03:27 by nduvoid           #+#    #+#             */
/*   Updated: 2025/02/14 15:07:20 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* -----| Headers |----- */
# include "interne/_Utils.h"

/* -----| Functions |----- */

__attribute__((hot))	t_serveur	*get_serveur(void)
{
	static t_serveur	serveur = (t_serveur){	// @todo: add the rigth functions
		.serveur_pid = get_pid(),
		.hear = NULL,
		.translator = NULL
		.talker = NULL,
	};

	return (&serveur);
}
