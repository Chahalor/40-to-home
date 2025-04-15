/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 09:19:51 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/15 09:59:25 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARGS_H
# define ARGS_H

# pragma once

/* ************************************************************************** */
/*                                 Headers                                    */
/* ************************************************************************** */

/* Systeme */
	//...

/* Global */
# include "config.h"
# include "types.h"

/* Internal */
	//...

/* ************************************************************************** */
/*                                 Defines                                    */
/* ************************************************************************** */

//...

/* ************************************************************************** */
/*                                 Typedefs                                   */
/* ************************************************************************** */

typedef struct s_args	t_args;

/* ************************************************************************** */
/*                                 Enums                                      */
/* ************************************************************************** */

//...

/* ************************************************************************** */
/*                                 Structs                                    */
/* ************************************************************************** */

struct s_args
{
	int		argc;			/**/
	char	**argv;			/**/
	t_bool	help	: 1;	/**/
	t_bool	version	: 1;	/**/
	int		invalid;		/**/
};

/* ************************************************************************** */
/*                                 Prototypes                                 */
/* ************************************************************************** */

t_args	parseur_args(
	register const int argc,
	const char **argv
);

#endif	// ARGS_H