/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 10:36:54 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/23 13:35:35 by nduvoid          ###   ########.fr       */
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
	//...

/* ************************************************************************** */
/*                                 Defines                                    */
/* ************************************************************************** */

//...

/* ************************************************************************** */
/*                                  Typedefs                                  */
/* ************************************************************************** */

//...

/* ************************************************************************** */
/*                                   Enumes                                   */
/* ************************************************************************** */

//...

/* ************************************************************************** */
/*                                  Structs                                   */
/* ************************************************************************** */

//...

/* ************************************************************************** */
/*                                 Prototypes                                 */
/* ************************************************************************** */

// utils.c

extern int	ft_strlen(const char *str);
extern void	ft_bzero(void *ptr, size_t len);
extern void	*ft_calloc(const size_t nmemb, const size_t size);
void		*emergency_storage(void *ptr);

// shortcut.c
extern int	lock(t_mutex *mutex);
extern int	unlock(t_mutex *mutex);
extern int	launch(t_thread *thread, void *(*start_routine)(void *), void *arg);
extern int	join(t_thread *thread);
extern int	unexpect(long value);

// error.c

extern void	ft_error(const char *msg);

// ansi.c

void		print_rgb_ansi(const int rgb);

// time.c

void		ft_usleep(int time);
extern int	get_ms_time(void);

#endif	/* UTILS_H */