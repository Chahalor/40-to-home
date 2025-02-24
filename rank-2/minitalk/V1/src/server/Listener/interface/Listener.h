/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Listener.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:43:59 by nduvoid           #+#    #+#             */
/*   Updated: 2025/02/15 12:05:18 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LISTENER_H
# define LISTENER_H

# pragma once

/* -----| Header |----- */
// Libs
#include <signal.h>

// Global
# include "types.h"

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

void	signal_handler(int signum, siginfo_t *siginfo, void *context);
t_bool	setup_signal();

/* -----| Static |----- */
//...

/* -----| Extern |----- */
//...

/* -----| Inline |----- */
//...

#endif	// LISTENER_H