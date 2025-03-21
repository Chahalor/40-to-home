/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 12:34:09 by nduvoid           #+#    #+#             */
/*   Updated: 2025/03/21 12:48:46 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief ft_va_printf is a function that will print a formatted string
 * to the standard output
 * 
 * @param s the string to print
 * @param args the arguments to print
 * 
 * @return int the number of characters printed
 */
int	ft_va_printf(const char *s, va_list args)
{
	__uint32_t	strlen;
	int			nb_char;

	if (write(1, "", 0) == -1)
		return (-1);
	else if (!s)
		return (-1);
	strlen = ft_strlen(s);
	nb_char = 0;
	nb_char = write_loop(s, args, strlen, &nb_char);
	return (nb_char);
}

#if DEBUG == 0

int	dbg_printf(const char *s, ...)
{
	(void)s;
	return (0);
}

#else

/** */
__attribute__ ((format(printf, 1, 2)))
int	dbg_printf(const char *s, ...)
{
	va_list		args;
	__uint32_t	strlen;
	int			nb_char;

	if (write(1, "", 0) == -1)
		return (-1);
	else if (!s)
		return (-1);
	va_start(args, s);
	strlen = ft_strlen(s);
	nb_char = 0;
	nb_char = write_loop(s, args, strlen, &nb_char);
	va_end(args);
	return (nb_char);
}

#endif	/* DEBUG || DEBUG == 0 */

/**
 * @file ft_printf.c
 * @dir ft_printf
 * @brief ft_printf is a function that will print a formatted string
 * to the standard output (aka printf of wish)
 * @author nduvoid
 * 
 * @param s the string to print
 * @param ... the arguments to print
 * @return int the number of characters printed
 */
__attribute__ ((format(printf, 1, 2)))
int	ft_printf(const char *s, ...)
{
	va_list		args;
	__uint32_t	strlen;
	int			nb_char;

	if (write(1, "", 0) == -1)
		return (-1);
	else if (!s)
		return (-1);
	va_start(args, s);
	nb_char = 0;
	strlen = ft_strlen(s);
	nb_char = write_loop(s, args, strlen, &nb_char);
	va_end(args);
	return (nb_char);
}
