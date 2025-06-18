/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _interface.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 14:56:36 by nduvoid           #+#    #+#             */
/*   Updated: 2025/06/18 14:07:49 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _INTERFACE_H
# define _INTERFACE_H

# pragma once

/* ************************************************************************** */
/*                                  Headers                                   */
/* ************************************************************************** */

/* Systems */
# include <unistd.h>
# include <stdio.h>
# include <string.h>

/* Globals */
# include "type.h"
# include "config.h"
# include "formating.h"

/* Modules */
# include "philosophers.h"
# include "utils.h"

/* ************************************************************************** */
/*                                  Defines                                   */
/* ************************************************************************** */

# define MAX_LOGS		16	/* The max number of logs to display   */

# define INFO_HEIGTH	8	/* The height of the info display    */

# define NB_LOG_COL		13	/* The number of log columns       */
# define LOG_WIDTH		26	/* The width of the log display   */
# define LOG_HEIGHT		4	/* The height of the log display */

/* ************************************************************************** */
/*                                  Typedefs                                  */
/* ************************************************************************** */

typedef struct s_raw_data	t_raw_data;	/* The raw log data  */
typedef struct s_log		t_log;		/* The log type     */
typedef struct s_info		t_info;		/* The info type   */

/* ************************************************************************** */
/*                                  Structs                                   */
/* ************************************************************************** */

struct s_raw_data
{
	const char	*status_str[12];	/* The status strings    */
	const char	*format[3];			/* The formated strings */
	t_time		start_time;			/* The start time      */
	sem_t		*print_lock;		/* The print lock     */
};

struct s_log
{
	const char	*msg;	/* The log message         */
	int			sec;	/* The log time in sec    */
	int			ms;		/* The log time in ms    */
	int			id;		/* The philosopher id   */
};

struct s_info
{
	t_log		logs[MAX_LOGS];	/* The log messages            */
	t_time		time_start;		/* The start time of the log  */
	int			start;			/* The first log to print    */
	int			nb_logs;		/* The number of logs       */
};

/* ************************************************************************** */
/*                                  Structs                                   */
/* ************************************************************************** */

// display.c

extern void	move_cursor(
				const int row,
				const int col
				);

#endif	// _INTERFACE_H