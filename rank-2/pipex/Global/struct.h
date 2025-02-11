/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 14:09:15 by nduvoid           #+#    #+#             */
/*   Updated: 2025/02/11 15:18:56 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# pragma once

/* -----| Header |----- */
// Global
//...

// Local
//...

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

/** @todo */
typedef struct s_cmd
{
	char	*bin;
	char	*cmd;
	char	**args;
}	t_cmd;

/** @todo */
typedef struct s_args
{
	char	*file_in;
	char	*file_out;
	char	*path;
	char	**envp;
	char	**cmd;
}	t_args;


/** @todo */
typedef struct s_fork
{
	int	pid;
	int	status;
}	t_fork;


/* -----| Prototype |----- */
//...

/* -----| Static |----- */
//...

/* -----| Extern |----- */
//...

/* -----| Inline |----- */
//...

#endif	// STRUCT_H