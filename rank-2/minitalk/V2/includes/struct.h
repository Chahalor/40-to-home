/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 08:50:14 by nduvoid           #+#    #+#             */
/*   Updated: 2025/03/10 08:13:43 by nduvoid          ###   ########.fr       */
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

#include "types.h"

/* -----| Define |----- */
//...

/* -----| Macro |----- */
//...

/* -----| Typedef |----- */

typedef struct s_args	t_args;

/* -----| Enum |----- */
//...

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