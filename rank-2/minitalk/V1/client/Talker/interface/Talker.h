/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Talker.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 18:34:04 by nduvoid           #+#    #+#             */
/*   Updated: 2025/02/14 11:27:47 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TALKER_H
# define TALKER_H

# pragma once

/* -----| Header |----- */
//libs
//...

// Global
#include "types.h"

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

t_bool	talker(const int serv_pid, t_byte *msg);
void	sig_bit(int bit, int pid);

/* -----| Static |----- */
//...

/* -----| Extern |----- */
//...

/* -----| Inline |----- */
//...

#endif	// TALKER_H