/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 08:10:55 by nduvoid           #+#    #+#             */
/*   Updated: 2025/03/10 11:25:14 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# pragma once

/* -----| Header |----- */
// Glibc
//...

// Libs
//...

// Local
//...

/* -----| Define |----- */
//...

/* -----| Macro |----- */
//...

/* -----| Typedef |----- */

typedef unsigned int	t_uint;
typedef enum e_bool		t_bool;
typedef enum e_print	t_print;
typedef enum e_comm		t_comm;
typedef enum e_crypt	t_crypt;
typedef enum e_mode		t_mode;

/* -----| Enum |----- */

enum e_bool
{
	false,
	true
};

enum e_print
{
	buffered,
	reallocing
};

enum e_comm
{
	ack,
	nack
};

enum e_crypt
{
	none,
	rc4
};

/**
 * @brief define the two different modes of the client manager function
 */
enum e_mode
{
	alloc,
	send,
	freeing
};

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
//...

#endif	/* TYPES_H */