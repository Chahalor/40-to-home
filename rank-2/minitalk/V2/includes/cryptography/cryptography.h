/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cryptography.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 13:34:57 by nduvoid           #+#    #+#             */
/*   Updated: 2025/03/07 13:40:11 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CRYPTOGRAPHY_H
# define CRYPTOGRAPHY_H

# pragma once

/* -----| Header |----- */
// Glibc
#include <stdio.h>
#include <stdlib.h>

// Libs
# include "libft.h"

// Local
//...

/* -----| Define |----- */

# define S_BOX_SIZE 256

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

char	*f_rc4(char *key, char *msg, int len_msg);

/* -----| Static |----- */
//...

/* -----| Extern |----- */
//...

/* -----| Inline |----- */
//...

#endif	/* HANDLER_H */