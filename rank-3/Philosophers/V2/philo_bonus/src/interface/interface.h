/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 20:25:33 by nduvoid           #+#    #+#             */
/*   Updated: 2025/05/06 13:56:01 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERFACE_H
# define INTERFACE_H

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
/*                                  Structs                                   */
/* ************************************************************************** */

// init.c

extern void	init_display(
				const t_philo_data data,
				const t_philo *restrict random_one,
				const int display
				);

// print.c

void		info(
				const int id,
				const char *msg
				);

void		info2(
				const int id,
				const char *msg
				);

// display.c

extern void	move_cursor(
				const int row,
				const int col
				);

void		raw_log(
				const void *ptr,
				const int info
				);

void		display_philo(
				const void *data,
				const int info
				);

#endif	// INTERFACE_H