/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 09:26:30 by nduvoid           #+#    #+#             */
/*   Updated: 2025/03/13 09:37:40 by nduvoid          ###   ########.fr       */
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
#  define BONUS 0		// lock/unlock bonus functionality
# endif

# ifndef DEBUG
#  define DEBUG 0		// lock/unlock debug functionality
# endif

# define BUFF_MODE 0		// 0: buffered, 1: reallocing
# define BUFF_SIZE 1024		// size of the buffer for buffering/allocating
# define MAX_NAME_SIZE 32	// max size of the name of the client

# define EOT 0x0		// end of transmission character used here (yes not 0x4)

# define GREEN "\033[0;32m"
# define RED "\033[0;31m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define RESET "\033[0m"

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
	send,
	reset,
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

typedef enum e_status
{
	name,
	print_name,
	msg,
}	t_status;

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
	pid_t	pid;
	t_error	err;
	t_uint	help	: 1;
}	t_args;

# if (BUFF_MODE == 0)

#  pragma pack(push, 1)

typedef struct s_server
{
	char		buff[BUFF_SIZE];
	char		name_client[BUFF_SIZE];
	t_status	status;
}	t_server;

#  pragma pack(pop)

# else

#  pragma pack(push, 1)

typedef struct s_server
{
	char		*buff;
	char		*name_client;
	t_status	status;
}	t_server;

#  pragma pack(pop)

# endif

typedef struct s_client
{
	char		*name;
	char		*msg;
	pid_t		pid;
	t_status	status;
}	t_client;

/* -----| Prototype |----- */

t_args	parse_args_client(int argc, char *argv[]);
void	parse_args_server(int argc, char *argv[]);

void	cleanup_server(int signal, siginfo_t *info, void *context);

// inline
void	exiting(const t_error code, const char *msg);
void	*allocator(char *buff, int *nb_alloc);
void	*reallocator(char *buff, int *nb_alloc);

/* -----| Static |----- */
//...

/* -----| Extern |----- */
//...

/* -----| Inline |----- */
//...

#endif	/* MINITALK_H */