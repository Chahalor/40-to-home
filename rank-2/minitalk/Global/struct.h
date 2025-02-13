/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 17:44:16 by nduvoid           #+#    #+#             */
/*   Updated: 2025/02/13 18:16:20 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# pragma once

/* -----| Header |----- */
// Libs
# include <signal.h>
# include <asm-generic/siginfo.h>

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
	void	*(*hear)(int, const char **);
	void	*(*translator)(char *);
	void	*(*talker)(int, int *);
	void	*(*callback)(int, siginfo_t *, void *);
}			t_client;

typedef struct s_serveur
{
	int		serveur_pid;
	void	*(*hear)(int, char **);
	void	*(*translator)(int *, int);
	void	*(*talker)();
};


/* -----| Prototype |----- */
//...

/* -----| Static |----- */
//...

/* -----| Extern |----- */
//...

/* -----| Inline |----- */
//...

#endif	