/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 13:19:03 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/14 08:51:52 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

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
/*                                 Typedefs                                   */
/* ************************************************************************** */

typedef struct s_philo	t_philo;	/**/

typedef enum e_status	t_status;	/**/

/* ************************************************************************** */
/*                                 Enums                                      */
/* ************************************************************************** */

enum e_status
{
	thinking	= 0,	/**/
	eating		= 1,	/**/
	sleeping	= 2,	/**/
	dead		= 3,	/**/
	take_fork	= 4,	/**/
	finished	= 5,	/**/
};

/* ************************************************************************** */
/*                                 Struct                                     */
/* ************************************************************************** */

struct s_philo
{
	t_mutex			*lock;			/**/
	t_mutex			*left_fork;		/**/
	t_mutex			*right_fork;	/**/
	t_data			data;			/**/
	int				id;				/**/
	unsigned int	last_meal;		/**/
	unsigned int	eat_count;		/**/
	t_status		status	: 3;	/**/ // @todo: check the bitfield size
};

/* ************************************************************************** */
/*                                 Prototypes                                 */
/* ************************************************************************** */

void	*life(
	void *arg
);

extern void	reaper(
	t_philo *philosophers,
	int i
);

t_philo	*build_philos(
	t_data data
);

#endif	/* PHILOSOPHER_H */