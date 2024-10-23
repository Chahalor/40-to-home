/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:36:25 by nduvoid           #+#    #+#             */
/*   Updated: 2024/10/23 15:53:23 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


/*
renvoie la taille d un str bien formater (avec le \0 quoi)
@param const char *s
@return unsigned long int
*/
unsigned long int	ft_strlen(const char *s)
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

/*
Verifie si item est dans lst
@param const void *lst | la list\n
@param unsigned char item | l item que l on veux verifier
@param size_t lstlen | la taille de la list
@return enum _bool | si oui ou non dans la list
*/
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

/*
trouve le nombre de % valide dans le str
@param const char *str
@return unsigned int
*/
unsigned int	nb_include(const char *str)
{
	unsigned int	r;
	size_t			i;
	size_t			str_len;

	r = 0;
	str_len = ft_strlen(str);
	i = 0;
	while (i < str_len)
	{
		if (str[i] == '%')
			if (in_lst(LST_INC, str[i + 1], 9))
			{
				r++;
				i++;
			}
		i++;
	}
	return (r);
}

t_list	*build_arg_lst(const char *str, t_list *list, va_list *arg)
{
	unsigned int	nb_arg;

	nb_arg = nb_include(str);

}

int ft_printf(const char *str, ...)
{
	va_arg	args;
}