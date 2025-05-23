/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 08:53:29 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/29 12:12:54 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef THREADS_H
# define THREADS_H

# pragma once

/* ************************************************************************** */
/*                                  Headers                                   */
/* ************************************************************************** */

/* Systemes */
# include <unistd.h>

/* Globals  */
# include "config.h"
# include "type.h"
# include "formating.h"

/* Internal */
	//...

/* Modules  */
# include "states.h"
# include "threads.h"
# include "philosophers.h"
# include "utils.h"
# include "interface.h"

/* ************************************************************************** */
/*                                  Prototypes                                */
/* ************************************************************************** */

int	launch_simu(
		t_philo *philosophers,
		const t_philo_data data,
		const int display
		);

#endif	// THREADS_H