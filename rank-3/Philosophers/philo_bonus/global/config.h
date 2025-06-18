/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 10:43:01 by nduvoid           #+#    #+#             */
/*   Updated: 2025/05/06 13:24:28 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_H
# define CONFIG_H

# pragma once

/* ************************************************************************** */
/*                                 Config                                     */
/* ************************************************************************** */

# ifndef DEBUG
#  define DEBUG		0		/* 0: debug disabled, 1: debug enabled   */
# endif	/* DEBUG */

# ifndef BONUS
#  define BONUS		1		/* 0: bonus disabled, 1: bonus enabled   */
# endif	/* BONUS */

# define DISPLAY_MODE	1	/* 0: raw log, 1: vizualizer (deprecated)    */

# define DEFAULT_SEMA_DIR		"/philo"	/* default sem directory         */
# define DEFAULT_SEMA_FORKS		"_forks"	/* default sem name for forks    */
# define DEFAULT_SEMA_RUN		"_run"		/* default sem name for death    */
# define DEFAULT_SEMA_PRINT		"_print"	/* default sem name for print    */
# define DEFAULT_SEMA_FINISHED	"_finished"	/* default sem name for finished */
# define DEFAULT_SEMA_LOCK		"_lock_0"	/* default sem name for lock     */

#endif	/* CONFIG_H */