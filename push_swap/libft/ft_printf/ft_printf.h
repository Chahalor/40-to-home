/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:37:23 by nduvoid           #+#    #+#             */
/*   Updated: 2024/10/30 14:31:25 by nduvoid          ###   ########.fr       */
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
int				ft_printf(const char *str, ...)
				__attribute__ ((format(printf, 1, 2)));

#endif