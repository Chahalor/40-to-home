/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 09:53:52 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/16 15:09:37 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# pragma once

/* ************************************************************************** */
/*                                 Headers                                    */
/* ************************************************************************** */

/* Systeme */
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

/* Global */
# include "config.h"
# include "types.h"

/* Internal */
	//...

/* ************************************************************************** */
/*                                 Prototypes                                 */
/* ************************************************************************** */

extern void	exit_error(
	const char *restrict msg,
	const int errnum
);

extern t_bool	is_alpha(
	const char c
);

extern int		randint(
	int min,
	int max
);

char	*ft_strdup(
	const char *restrict s
);

extern int	ft_strcmp(
	const char *restrict s1,
	const char *restrict s2
);

#endif	// UTILS_H