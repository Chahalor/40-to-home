/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 14:10:08 by nduvoid           #+#    #+#             */
/*   Updated: 2025/02/13 10:21:08 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_H
# define TYPE_H

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

typedef enum e_exit
{
	clean = 0,
	malloc_error,
	fork_error,
	execve_error,
	pipe_error,
	dup_error,
	close_error,
	waitpid_error,
	invalid_cmd,
	invalid_file,
	invalid_path,
	invalid_arg,
}	t_exit;

typedef	enum e_bool
{
	false = 0,
	true = 1,
}	t_bool;

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

#endif	// TYPE_H