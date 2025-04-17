/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 09:53:52 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/15 10:40:32 by nduvoid          ###   ########.fr       */
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
	const char *msg,
	const int errnum
);

extern t_bool	is_alpha(
	const char c
);

extern int		randint(
	int min,
	int max
);

#endif	// UTILS_H