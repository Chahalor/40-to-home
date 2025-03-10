/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cryptography.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 13:34:57 by nduvoid           #+#    #+#             */
/*   Updated: 2025/03/10 11:02:36 by nduvoid          ###   ########.fr       */
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

# define S_BOX_SIZE 256	// size of the s-box used in rc4

/* -----| Macro |----- */
//...

/* -----| Typedef |----- */
//...

/* -----| Enum |----- */

enum e_code
{
	XOR,
	AND,
	RC4,
};

/* -----| Union |----- */
//...

/* -----| Struct |----- */
//...

/* -----| Prototype |----- */

char	*encode_xor(const char *str, const char *key);
char	*decode_xor(const char *str, const char *key);

/* -----| Static |----- */
//...

/* -----| Extern |----- */
//...

/* -----| Inline |----- */
//...

#endif	/* HANDLER_H */