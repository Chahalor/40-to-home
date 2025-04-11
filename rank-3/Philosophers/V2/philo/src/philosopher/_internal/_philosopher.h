/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _philosopher.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 14:57:37 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/11 15:41:39 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _PHILOSOPHER_H
# define _PHILOSOPHER_H

# pragma once

/* ************************************************************************** */
/*                                 Headers                                    */
/* ************************************************************************** */
/* --- Systeme ---*/
# include <pthread.h>

/* --- Global --- */
# include "config.h"
# include "type.h"

/* --- Modules --- */
# include "utils.h"

/* ************************************************************************** */
/*                                 Prototypes                                 */
/* ************************************************************************** */

/* --- _philosopher.c --- */

extern t_philo *init_mutex(
	t_philo *philosophers,
	const t_data data
);

void	info(
	const int id,
	t_status status,
	const int timer
);

/* --- _life.c --- */

void	_eat(
	t_philo *philosopher
);

void	_sleep(
	t_philo *philosopher
);

void	_think(
	t_philo *philosopher
);

void	_death(
	t_philo *philosopher
);


#endif	/* _PHILOSOPHER_H */