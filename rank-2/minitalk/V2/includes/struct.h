/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 08:50:14 by nduvoid           #+#    #+#             */
/*   Updated: 2025/03/05 15:43:06 by nduvoid          ###   ########.fr       */
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

/* -----| Union |----- */
//...

/* -----| Struct |----- */

# ifdef SERVER

struct s_args
{
	t_print	print;
	t_comm	comm;
	// const char *key;
	// t_bool	crypted	: 1;	// need more informations
	t_bool	err		: 1;
	t_bool	help	: 1;
};

# elif (defined CLIENT)

struct s_args
{
	int		pid;
	char	*msg;
	t_comm	comm;
	// const char *key;
	// t_bool	crypted	: 1;	// need more informations
	t_bool	err		: 1;
};

# else

#  error "No target defined"

# endif

/* -----| Prototype |----- */
//...

/* -----| Static |----- */
//...

/* -----| Extern |----- */
//...

/* -----| Inline |----- */
//...

#endif	/* STRUCT_H */