/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 09:26:30 by nduvoid           #+#    #+#             */
/*   Updated: 2025/03/10 15:13:56 by nduvoid          ###   ########.fr       */
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
#  define BONUS 0				// lock/unlock bonus functionality
# endif

# ifndef DEBUG
#  define DEBUG 0				// lock/unlock debug functionality
# endif

# define BUFF_MODE 0			// 0: buffered, 1: reallocing
# define BUFF_SIZE 1024			// size of the buffer for buffering/allocating
# define MAX_NAME_SIZE 32		// max size of client name

# define EOT 0x0				// end of transmission character used here (yes not 0x4)

# define RED "\033[0;31m"		// red color for the client name
# define GREEN "\033[0;32m"		// green color for the client name
# define BLUE "\033[0;34m"		// blue color for the client name
# define YELLOW "\033[0;33m"	// yellow color for the client name
# define RESET "\033[0m"		// reset color

/* -----| Macro |----- */
//...

/* -----| Typedef |----- */

typedef unsigned int	t_uint;

/* -----| Enum |----- */

/**
 * @brief a basic enum for boolean values
 */
typedef enum e_bool
{
	false,
	true
}	t_bool;

/**
 * @brief define the two different modes of the client manager function
 */
typedef enum e_mode
{
	alloc,
	send
}	t_mode;

/**
 * @brief literaly an enum of errno.h error code
 * 
 * @note in fault of the norminette i had to cut all other cause it is code
 * with the ass.
 */
typedef enum e_error
{
	enomen = ENOMEM,
	einval = EINVAL,	
}	t_error;
/* -----| Union |----- */
//...

/* -----| Struct |----- */

/**
 * @brief a struct to store the different available args to the programme
 * 
 * - pid: the server's pid
 * 
 * - msg: the msg we have to send to the server
 * 
 * - err: if any error occured will parsing args set  it to the rigth errno code
 */
typedef struct s_args
{
	char	*msg;
	char	*name;
	int		pid;
	t_error	err;
}	t_args;

typedef struct t_server
{
	char	*client_name;
	int		status;
}	t_server;

typedef struct t_client
{
	char	*name;
	char	*msg;
	int		server_pid;
}	t_client;

/* -----| Prototype |----- */
//...

/* -----| Static |----- */
//...

/* -----| Extern |----- */
//...

/* -----| Inline |----- */


/**
 * @brief this function exit the programme with the code code (nooo way) 
 * and if any message is given to it print it.
 * 
 * @param code the error code
 * @param msg the msg to print (should not be allocated)
 * 
 * @return no return, this function exit any way
 */
__attribute__((cold, unused, noreturn)) static inline void	exiting(
	const t_error code,
	const char *msg)
{
	if (msg)
		write(2, msg, ft_strlen(msg));
	if (code)
		errno = code;
	exit(code);
}

/**
 * @brief this function realloc the buffer to the next size
 * 
 * @param buff the buffer to realloc
 * @param nb_alloc the number of allocation done
 * 
 * @return the new buffer
 */
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

/**
 * @brief this function allocate the buffer to the first size
 * 
 * @param buff the buffer to allocate
 * @param nb_alloc the number of allocation done
 * 
 * @return the new buffer
 */
__attribute__((hot)) static inline void	*allocator(char *buff, int *nb_alloc)
{
	buff = (char *)malloc(++(*nb_alloc) * BUFF_SIZE);
	if (!buff)
		exiting(enomen, "Error: malloc failed\n");
	return (buff);
}

#endif	/* MINITALK_H */