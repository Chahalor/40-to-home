/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 10:36:54 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/07 14:35:51 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# pragma once

/* Prototypes */

// utils.c

extern int	ft_strlen(const char *str);
extern void	ft_error(const char *msg);
int			ft_strncmp(const char *s1, const char *s2, const size_t n);
int			ft_atoi(const char *nptr);

// utils2.c
int			is_nbr(const char *str);


#endif	/* UTILS_H */