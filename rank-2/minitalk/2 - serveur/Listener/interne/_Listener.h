/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _Listener.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 14:19:53 by nduvoid           #+#    #+#             */
/*   Updated: 2025/02/13 15:36:25 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _LISTENER_H
# define _LISTENER_H

# pragma once

/* -----| Header |----- */
// Libs
# include <unistd.h>
# include <signal.h>
# include <sys/types.h>
#include <asm-generic/siginfo.h>

// Global
# include "config.h"

// Modules
//...

/* -----| Define |----- */
//...

/* -----| Macro |----- */
//...

/* -----| Typedef |----- */
//...

/* -----| Enum |----- */
//...

/* -----| Union |----- */
//...

/* -----| Struct |----- */
//...

/* -----| Prototype |----- */
//...

/* -----| Static |----- */
//...

/* -----| Extern |----- */
//...

/* -----| Inline |----- */

/** */
__attribute__((hot)) static inline	int	is_EOT(const int *buffer,
	const int count)
{
	int	i;
	int	c;

	if (count < 9)
		return (0);
	i = count - 8;
	c = 0;
	while (i < count)
		c = (c << 1) | buffer[i++];
	return (c == 4);
}

#endif	// _LISTENER_H