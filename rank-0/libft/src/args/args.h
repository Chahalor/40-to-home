/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 08:20:14 by nduvoid           #+#    #+#             */
/*   Updated: 2025/06/27 15:27:53 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARGS_H
# define ARGS_H

#pragma once

/* Typedefs */

typedef enum e_types	t_types;

typedef struct s_args	t_args;

/* Enums */

enum e_types
{
	e_none,
	e_flag,
	e_int,
	e_str,
};

/* Prototypes */

int add_args(t_types type, const char *name, const char *value);

#endif	/* ARGS_H */