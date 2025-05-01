/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 10:43:01 by nduvoid           #+#    #+#             */
/*   Updated: 2025/05/01 11:31:09 by nduvoid          ###   ########.fr       */
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
#  define BONUS		0		/* 0: bonus disabled, 1: bonus enabled   */
# endif	/* BONUS */

# define DISPLAY_MODE	1	/* 0: raw log, 2: vizualizer     */

# define DEFAULT_SEMA_DIR	"/philo"	/* default semaphore directory         */
# define DEFAULT_SEMA_FORKS	"/forks"	/* default semaphore name for forks   */
# define DEFAULT_SEMA_RUN	"/run"		/* default semaphore name for death  */
# define DEFAULT_SEMA_PRINT	"/print"	/* default semaphore name for print */

#endif	/* CONFIG_H */