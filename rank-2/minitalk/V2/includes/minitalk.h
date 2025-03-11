/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 09:26:30 by nduvoid           #+#    #+#             */
/*   Updated: 2025/03/11 15:44:11 by nduvoid          ###   ########.fr       */
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

# define BUFF_MODE 1		// 0: buffered, 1: reallocing
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

t_args	parse_args(int argc, char *argv[]);

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
	ft_memset(buff, 0, BUFF_SIZE * *nb_alloc);
	// ft_printf("Allocating buffer at address: %p, size: %d\n", (void *)buff, *nb_alloc * BUFF_SIZE);	//rm
	return (buff);
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
	// ft_printf("Reallocating buffer at address: %p, size: %d\n", (void *)tmp, *nb_alloc * BUFF_SIZE);	//rm
	buff = (char *)allocator(buff, nb_alloc);
	ft_memcpy(buff, tmp, (*nb_alloc - 1) * BUFF_SIZE);
	if (tmp)
	{
		free(tmp);
		tmp = NULL;
	}
	// ft_printf("New buffer address: %p, new size: %d\n", (void *)buff, *nb_alloc * BUFF_SIZE);	//rm
	return (buff);
}


#endif	/* MINITALK_H */