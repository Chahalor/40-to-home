/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 08:50:14 by nduvoid           #+#    #+#             */
/*   Updated: 2025/03/07 12:35:52 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

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

typedef struct s_args	t_args;
typedef enum e_bool		t_bool;
typedef enum e_print	t_print;
typedef enum e_comm		t_comm;
typedef enum e_crypt	t_crypt;

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

/* -----| Union |----- */
//...

/* -----| Struct |----- */

# ifdef SERVER

#  pragma pack(push, 1)

struct s_args
{
	char	*key;
	t_crypt	crypt;
	t_print	print;
	t_comm	comm;
	t_bool	err		: 1;
	t_bool	help	: 1;
};

#  pragma pack(pop)

# elif (defined CLIENT)

#  pragma pack(push, 1)

struct s_args
{
	char	*msg;
	char	*key;
	int		pid;
	t_crypt	crypt;
	t_comm	comm;
	t_bool	err		: 1;
	t_bool	help	: 1;
};

#  pragma pack(pop)

# else

#  error "No target defined"

# endif	/* args struct */

/* -----| Prototype |----- */
//...

/* -----| Static |----- */
//...

/* -----| Extern |----- */
//...

/* -----| Inline |----- */
//...

#endif	/* STRUCT_H */