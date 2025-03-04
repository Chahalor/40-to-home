/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 09:26:30 by nduvoid           #+#    #+#             */
/*   Updated: 2025/03/04 14:50:31 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# pragma once

/* -----| Header |----- */
// Glibc
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <stdio.h>
# include <sys/types.h>
# include <errno.h>

// Local
# include "libft.h"

/* -----| Define |----- */

# ifndef BONUS
#  define BONUS 0
# endif

# ifndef DEBUG
#  define DEBUG 0
# endif

# define BUFF_MODE 0	// 0: buffered, 1: reallocing
# define BUFF_SIZE 1024

# define EOT 0x0

/* -----| Macro |----- */
//...

/* -----| Typedef |----- */

typedef unsigned int	t_uint;

/* -----| Enum |----- */

typedef enum e_bool
{
	false,
	true
}	t_bool;

typedef enum e_mode
{
	alloc,
	send
}	t_mode;

/**
 * @brief literaly an enum of errno.h error code
 */
typedef enum e_error
{
	enomen = ENOMEM,
	einval = EINVAL,	
}	t_error;
/* -----| Union |----- */
//...

/* -----| Struct |----- */

typedef struct s_args
{
	pid_t	pid;
	char	*msg;
	t_error	err;
}	t_args;

/* -----| Prototype |----- */
//...

/* -----| Static |----- */
//...

/* -----| Extern |----- */
//...

/* -----| Inline |----- */

// __attribute__((cold, unused, noreturn))	/* hate you so much norminette */
static inline void	exiting(
	const t_error code,
	const char *msg)
{
	if (msg)
		write(2, msg, ft_strlen(msg));
	if (code)
		errno = code;
	exit(code);
}

__attribute__((hot)) static inline void	*reallocator(char *buff, int *nb_alloc)
{
	char	*tmp;

	tmp = buff;
	buff = (char *)malloc(++(*nb_alloc) * BUFF_SIZE);
	if (!buff)
		exiting(enomen, "Error: reallocation failed\n");
	ft_memcpy(buff, tmp, (*nb_alloc - 1) * BUFF_SIZE);
	free(tmp);
	return (buff);
}

__attribute__((hot)) static inline void	*allocator(char *buff, int *nb_alloc)
{
	buff = (char *)malloc(++(*nb_alloc) * BUFF_SIZE);
	if (!buff)
		exiting(enomen, "Error: malloc failed\n");
	return (buff);
}

#endif	/* MINITALK_H */