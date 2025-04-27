/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 20:25:33 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/27 20:53:04 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERFACE_H
# define INTERFACE_H

# pragma once

# include <unistd.h>
# include <stdio.h>
# include <string.h>

# include "type.h"
# include "config.h"
# include "formating.h"

# include "philosophers.h"
# include "states.h"
# include "utils.h"

/* ************************************************************************** */
/*                                  Defines                                   */
/* ************************************************************************** */

# define MAX_LOGS	3

# define NB_LOG_COL	5
# define LOG_WIDTH	26
# define LOG_HEIGHT	5

/* ************************************************************************** */
/*                                  Typedefs                                  */
/* ************************************************************************** */

typedef struct s_log	t_log;		/* The log type   */
typedef struct s_info	t_info;		/* The info type */

/* ************************************************************************** */
/*                                  Structs                                   */
/* ************************************************************************** */

struct s_log
{
	const char	*msg;	/* The log message         */
	int			sec;	/* The log time in sec    */
	int			ms;		/* The log time in ms    */
	int			id;		/* The philosopher id   */
};

struct s_info
{
	t_log		logs[MAX_LOGS];	/* The log messages           */
	t_time		time_start;		/* The start time of the log */
	t_mutex		print_lock;		/* The print mutex          */
	int			nb_logs;		/* The number of logs      */
};

/* ************************************************************************** */
/*                                  Structs                                   */
/* ************************************************************************** */

// print.c

void	info(
			const int id,
			const char *msg
			);

// display.c

extern void	move_cursor(
			const int row,
			const int col
			);

void	display_philo(
			const t_philo *philo
			);

#endif	// INTERFACE_H