/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 10:52:51 by nduvoid           #+#    #+#             */
/*   Updated: 2025/03/07 14:15:43 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HANDLER_H
# define HANDLER_H

# pragma once

/* -----| Header |----- */
// Glibc
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>

// Libs
# include "libft.h"

// Local
# include "struct.h"
# include "config.h"

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
//...

/* -----| Prototype |----- */

char	*decrypt_manager(void *msg, int mode);
void	handler(int sig, siginfo_t *info, void *context);

void	connection_manager(int sig);
void	connection_manager2(int sig);
void	reset_handler(void (*handler)());

void	ack_handler(int sig, siginfo_t *info, void *context);
void	nack_handler(int sig, siginfo_t *info, void *context);

/* -----| Static |----- */
//...

/* -----| Extern |----- */
//...

/* -----| Inline |----- */

__attribute__((hot)) static inline void	*reallocator(char *buff, int *nb_alloc)
{
	char	*tmp;

	tmp = buff;
	buff = (char *)malloc(++(*nb_alloc) * BUFF_SIZE);
	if (!buff)
		exiting(1, "Error: reallocation failed\n", NULL);
	ft_memcpy(buff, tmp, (*nb_alloc - 1) * BUFF_SIZE);
	free(tmp);
	return (buff);
}

__attribute__((hot)) static inline void	*allocator(char *buff, int *nb_alloc)
{
	buff = (char *)malloc(++(*nb_alloc) * BUFF_SIZE);
	if (!buff)
		exiting(1, "Error: malloc failed\n", NULL);
	return (buff);
}

#endif	/* HANDLER_H */