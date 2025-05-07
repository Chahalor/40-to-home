/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 20:25:33 by nduvoid           #+#    #+#             */
/*   Updated: 2025/05/07 12:13:32 by nduvoid          ###   ########.fr       */
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