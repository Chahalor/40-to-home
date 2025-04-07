/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 08:09:23 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/07 08:13:15 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STR_H
# define STR_H

#pragma once

/* Includes */
	/* System */
		//...

	/* Global */
		//...

	/* Modules */
		// ...


/* Prototypes */

int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_atoi(const char *nptr);

char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);

char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *s, char c);
char				*ft_itoa(int n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_striteri(char *s, void (*f)(unsigned int, char*));
char				*ft_strchr(const char *s, int c);
int					ft_strlen(const char *s);


#endif	/* STR_H */