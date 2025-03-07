/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 08:58:23 by nduvoid           #+#    #+#             */
/*   Updated: 2025/03/07 08:56:14 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_H
# define CONFIG_H

# pragma once

/* -----| Header |----- */
// Glibc
# include <unistd.h>
# include <stdlib.h>

// Libs
# include "libft.h"

// Local
//...

/* -----| Define |----- */

// Compilation config

# ifndef BONUS
#  define BONUS 0
# endif

# ifndef DEBUG
#  define DEBUG 0
# endif

# define EXPECTED 1
# define UNEXPECTED 0

// in-App config

# define BUFF_MODE 0	// 0: buffered, 1: reallocing
# define BUFF_SIZE 1024

# define EOT 0x0

# define SLEEP 500

/* -----| Macro |----- */
//...

/* -----| Typedef |----- */

typedef t_comm	t_connection;

/* -----| Enum |----- */


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

__attribute__((cold, unused, noreturn)) static inline void	exiting(int code,
	char *msg, void *ptr)
{
	if (msg)
		write(2, msg, ft_strlen(msg));
	if (ptr)
		free(ptr);
	exit(code);
}

#endif	/* CONFIG_H */