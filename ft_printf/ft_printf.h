/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:37:23 by nduvoid           #+#    #+#             */
/*   Updated: 2024/10/23 15:54:35 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft.h"

# define LST_INC "cspdiuxX%"

enum	e_bool {
	FALSE,
	TRUE
};

enum e_bool		in_lst(const void *lst, unsigned char item, size_t lstlen);
unsigned int	nb_include(const char *str);
t_list			*build_arg_lst(const char *str, va_list *arg);

int				ft_printf(const char *, ...);	// dont touch
# endif