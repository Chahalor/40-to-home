/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 17:44:16 by nduvoid           #+#    #+#             */
/*   Updated: 2025/02/14 16:31:17 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# pragma once

/* -----| Header |----- */
// Libs
# include <signal.h>
// # include <asm-generic/siginfo.h>

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

typedef struct s_client
{
	int		server_pid;
	char	*msg;
	void	(*hear)(const int, const char **, struct s_client *);
	t_bool	(*translator)(const char *, const int);
	t_bool	(*talker)(const int, t_byte *);
	void	*(*callback)(void);
}	t_client;

typedef struct s_serveur
{
	int		serveur_pid;
	void	(*hear)(int, siginfo_t *, void *);
	void	(*translator)(const int [], const int);
	int		(*talker)(const char *, ...);
}	t_serveur;


/* -----| Prototype |----- */
//...

/* -----| Static |----- */
//...

/* -----| Extern |----- */
//...

/* -----| Inline |----- */
//...

#endif	