/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _game.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 12:42:54 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/16 16:42:41 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _GAME_H
# define _GAME_H

#pragma once

/* ************************************************************************** */
/*                                 Headers                                    */
/* ************************************************************************** */

/* Systeme */
# include <fcntl.h>
# include <unistd.h>
# include <string.h>

/* Global */
# include "config.h"

/* Modules  */
# include "dico.h"

/* Internal */
	// ...

/* ************************************************************************** */
/*                                 typedefs                                   */
/* *************************************************************
************* */

typedef struct s_screen	t_screen;	/* some information about the "screen" state */

/* ************************************************************************** */
/*                                 Structs                                    */
/* ************************************************************************** */

struct s_screen
{
	char	*word;
	char	pattern[MAX_WORD_SIZE];
};

/* ************************************************************************** */
/*                                 Prototypes                                 */
/* ************************************************************************** */

extern t_bool	_is_finish(
	const char checker[MAX_WORD_SIZE]
);

extern void	_clear_memory(
	t_screen *memory,
	const int i
);

void	_updateValues(
	char *values,
	char *input,
	char *checker
);

void	_displayAlpha(
	char *values
);

#endif	// _GAME_H