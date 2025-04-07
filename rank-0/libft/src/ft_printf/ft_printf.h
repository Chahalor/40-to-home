/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:37:23 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/07 08:17:58 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

# define LST_INC "cspdiuxX%"
# define LHEX_CHAR "0123456789abcdef"
# define UHEX_CHAR "0123456789ABCDEF"

enum	e_bool
{
	FALSE,
	TRUE
};

// utils.c
size_t			ft_strlen(const char *str);

// write part
int				writechar(char c);
int				writestr(char *s);
int				writeptr(void *ptr);
int				writedec(int dec);
int				writeuint(unsigned int uint);
int				writelhex(int nb);
int				writeuhex(int nb);

enum e_bool		in_lst(const void *lst, unsigned char item, size_t lstlen);
int				write_loop(const char *s, va_list args, __uint32_t strlen,
	int *nb_char);
int				ft_printf(const char *str, ...)
				__attribute__ ((format(printf, 1, 2)));

#endif