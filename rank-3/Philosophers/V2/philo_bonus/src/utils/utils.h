/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 10:36:54 by nduvoid           #+#    #+#             */
/*   Updated: 2025/05/07 10:38:09 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# pragma once

/* ************************************************************************** */
/*                                  Headers                                   */
/* ************************************************************************** */

/* Systemes */
	//...

/* Global */
# include "config.h"
# include "type.h"

/* Modules */
# include "semaphores.h"

/* ************************************************************************** */
/*                                 Defines                                    */
/* ************************************************************************** */

# define USLEEP_MAGIC_VALUE	100	/* tkt */

/* ************************************************************************** */
/*                                 Prototypes                                 */
/* ************************************************************************** */

// utils.c

extern void		ft_memcpy(
					void *restrict dest,
					const void *restrict src,
					register const size_t len
					);
extern int		ft_sprintf(
					char *restrict dest,
					int nb
					);

// shortcut.c
extern int		launch(
					t_thread *thread,
					void *(*start_routine)(void *),
					void *arg
					);
extern int		join(
					t_thread *thread
					);
extern int		swait(
					sem_t *sem
					);

extern int		post(
					sem_t *sem
					);
// error.c

extern void		ft_error(
					const char *msg
					);

// time.c

void			ft_usleep(
					register const t_time time
					);
extern t_time	get_ms_time(void);

#endif	/* UTILS_H */