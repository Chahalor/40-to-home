/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 08:46:34 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/16 17:17:44 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_H
# define CONFIG_H

# pragma once

/* ************************************************************************** */
/*                                 Headers                                    */
/* ************************************************************************** */

/* Systeme */
	//...

/* Global */
	//...

/* Internal */
	//...

/* ************************************************************************** */
/*                                 Defines                                    */
/* ************************************************************************** */

# define VERSION_MAJOR	1
# define VERSION_MINOR	0
# define VERSION_PATCH	0

# define MAX_WORD_SIZE	5

# define DEFAULT_DATA_DIR	"data/"
# define DEFAULT_DICO_FILE	"words.txt"

# ifndef DEBUG
#  define DEBUG	0	// 0: no debug, 1: debug
# endif

# define MAX_TRY	6	/* the numbre of try to guess the word*/

/* ... */

#endif	// CONFIG_H