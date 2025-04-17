/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _args.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 09:41:38 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/15 09:52:42 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _ARGS_H
# define _ARGS_H

# pragma once

/* ************************************************************************** */
/*                                 Headers                                    */
/* ************************************************************************** */

/* Systeme */
#include <errno.h>
#include <string.h>
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

extern void		show_usage(t_bool exiting);
extern void		show_version(t_bool exiting);
extern void		show_help(void);

#endif	// _ARGS_H