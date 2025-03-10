/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 15:45:16 by nduvoid           #+#    #+#             */
/*   Updated: 2025/03/07 13:32:22 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HANDLER_H
# define HANDLER_H

# pragma once

/* -----| Header |----- */
// Glibc
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>

// Libs
//...

// Local
# include "struct.h"
# include "config.h"
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

void	manager(const int mode, char *msg);
void	ack_handler(int sig, siginfo_t *info, void *context);
void	nack_handler(int sig, siginfo_t *info, void *context);

/* -----| Static |----- */
//...

/* -----| Extern |----- */
//...

/* -----| Inline |----- */
//...

#endif	/* HANDLER_H */