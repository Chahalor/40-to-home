/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 14:49:45 by nduvoid           #+#    #+#             */
/*   Updated: 2025/05/07 10:39:36 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROCESS_H
# define PROCESS_H

# pragma once

/* ************************************************************************** */
/*                                  Headers                                   */
/* ************************************************************************** */

/* Systemes */
# include <unistd.h>
# include <signal.h>
# include <sys/wait.h>

/* Globals  */
# include "config.h"
# include "type.h"

/* Internal */
	//...

/* Modules  */
# include "parsing.h"
# include "philosophers.h"

/* ************************************************************************** */
/*                                  Prototypes                                */
/* ************************************************************************** */

extern int	launch_simu(
				t_philo *philos,
				const t_args args,
				const t_semaphores *semaphores
				);

#endif /* PROCESS_H */