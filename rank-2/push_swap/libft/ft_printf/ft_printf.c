/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:36:25 by nduvoid           #+#    #+#             */
/*   Updated: 2025/03/21 12:34:22 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

enum e_bool	in_lst(const void *lst, unsigned char item, size_t lstlen)
{
	size_t	i;

	i = 0;
	while (i < lstlen)
	{
		if (((unsigned char *)lst)[i] == item)
			return (TRUE);
		i++;
	}
	return (FALSE);
}

static int	write_arg(const char *s, va_list args)
{
	char	symb;

	symb = s[1];
	if (symb == 'c')
		return (writechar(va_arg(args, int)));
	else if (symb == 's')
		return (writestr(va_arg(args, char *)));
	else if (symb == 'p')
		return (writeptr(va_arg(args, void *)));
	else if (symb == 'd' || symb == 'i')
		return (writedec(va_arg(args, int)));
	else if (symb == 'u')
		return (writeuint(va_arg(args, unsigned int)));
	else if (symb == 'x')
		return (writelhex(va_arg(args, int)));
	else if (symb == 'X')
		return (writeuhex(va_arg(args, int)));
	else if (symb == '%')
		return (writechar('%'));
	else
		return (0);
}

static int	write_loop(const char *s, va_list args, __uint32_t strlen,
				int *nb_char)
{
	__uint32_t	i;
	int			wout;

	i = 0;
	while (i < strlen)
	{
		if (s[i] == '%')
		{
			wout = write_arg(&s[i], args);
			if (wout == -1)
				return (*nb_char);
			*nb_char += wout;
			i++;
		}
		else
		{
			wout = write(1, &s[i], 1);
			if (wout == -1)
				return (*nb_char);
			*nb_char += wout;
		}
		i++;
	}
	return (*nb_char);
}
