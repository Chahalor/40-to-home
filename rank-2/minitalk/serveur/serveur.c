/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 14:10:25 by nduvoid           #+#    #+#             */
/*   Updated: 2025/02/13 14:16:03 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* -----| Headers |----- */
// Libs
#include "libft.h"
#include <unistd.h>

// Global
//...

// Modules
#include "Translator.h"
#include "Talker.h"
#include "Listener.h"

/* -----| Functions |----- */

/** */
int	main(int argc, const char *argv[])
{
	ft_printf("serveur PID: %d\n", getpid());
}