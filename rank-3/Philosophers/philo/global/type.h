/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 13:56:58 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/07 15:44:04 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_H
# define TYPE_H

#pragma once

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>

/*                   */

typedef struct s_args		t_args;
typedef struct s_philo_data	t_philo_data;
typedef struct s_philo		t_philo;

/*                   */

# pragma pack(push, 1)

struct s_philo_data
{
	int		nb_philo;		/**/
	int		time_to_die;	/**/
	int		time_to_eat;	/**/
	int		time_to_sleep;	/**/
	int		nb_meals;		/**/
};

#pragma pack(pop)

struct s_args
{
	int				argc;			/**/
	const char		**argv;			/**/
	t_philo_data	data;			/**/
	int				error;			/**/
	int				help	: 1;	/**/
	int				debug	: 1;	/**/
};

struct s_philo
{
	pthread_mutex_t	*left_fork;		/**/
	pthread_mutex_t	*right_fork;	/**/
	t_philo			*prev;			/**/
	t_philo			*next;			/**/
	int				id;				/**/
	int				nb_meals;		/**/
	int				last_meal;		/**/
	int				state;			/**/
	int				color;			/**/
};

#endif	/* TYPE_H */