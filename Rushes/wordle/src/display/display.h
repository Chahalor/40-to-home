/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:35:59 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/16 13:54:02 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_H
# define DISPLAY_H

# pragma once

# define HEADER "Big Header"	// @todo: the true header
# define SEPARATOR "\n====================================================================\n"

/* ************************************************************************** */
/*                                 Prototypes                                 */
/* ************************************************************************** */

extern void	print_header(
	void
);

void	print_str_to_art(
	const char *str
);

void	print_str_to_art_patern(
	const char *str,
	char patern[MAX_WORD_SIZE]
);

#endif	// DISPLAY_H