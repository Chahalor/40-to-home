/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 16:06:28 by nduvoid           #+#    #+#             */
/*   Updated: 2025/02/24 10:20:30 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# pragma once

/* -----| Header |----- */
// Libs
//...

// Global
#include "struct.h"

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

t_serveur	*get_serveur(void);
void		exiting(int code, const char *msg, void *ptr);
/* -----| Static |----- */
//...

/* -----| Extern |----- */
//...

/* -----| Inline |----- */
//...

#endif	// UTILS_H