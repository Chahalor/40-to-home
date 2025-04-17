/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 09:54:15 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/16 16:36:04 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# pragma once

/* ************************************************************************** */
/*                                 Headers                                    */
/* ************************************************************************** */

/* Systeme */
	//...

/* Global */
# include "config.h"

/* Modules  */
# include "dico.h"

/* Internal */
# include "args.h"

/* ************************************************************************** */
/*                                 Prototypes                                 */
/* ************************************************************************** */

// word.c

int		start_game(
	t_dico *restrict dico
);

// menu.c

int		main_menu(
	const t_args args,
	t_dico *restrict dico
);

// checker.c

int		check_input(
	char *input,
	const char *restrict word,
	char checker[MAX_WORD_SIZE],
	t_dico2 *dico
);

char *get_input(
	const int fd
);

#endif	// GAME_H