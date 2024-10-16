/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 09:35:29 by marvin            #+#    #+#             */
/*   Updated: 2024/10/16 09:35:29 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
unsigned int	ft_strlen(const char s);

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*result;

	result = malloc(sizeof(char) * ft_strlen(s));
	if (!result)
		return (NULL);
	i = 0;
	while (s[i])
		result[i++] = f(i, s[i]);
	return (result);
}
