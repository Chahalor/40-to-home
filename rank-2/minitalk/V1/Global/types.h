/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 14:21:02 by nduvoid           #+#    #+#             */
/*   Updated: 2025/02/26 11:46:42 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# pragma once

/* -----| Header |----- */
// Libs
//...

// Global
//...

// Modules
//...

/* -----| Define |----- */
//...

/* -----| Macro |----- */
//...

/* -----| Typedef |----- */

typedef unsigned char	t_byte;

/* -----| Enum |----- */

/** */
typedef enum e_bool
{
	FALSE = 0,
	TRUE = 1
}	t_bool;

/** */
typedef enum e_error
{
	err_none = 0,
	err_malloc,
	err_open,
	err_close,
	err_signal,
	err_argv,
	//...
}	t_error;

typedef enum e_mode
{
	alloc = 0,
	add_char,
	print_str,
}	t_mode;

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

#endif	// TYPES_H