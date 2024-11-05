/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:02:24 by nduvoid           #+#    #+#             */
/*   Updated: 2024/11/05 15:52:23 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
#include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef MAX_FD
#  define MAX_FD 1024
# endif

typedef struct s_fd
{
	char	buffer[BUFFER_SIZE];
	int		size;
}	t_fd;

static inline int	min(int val1, int val2)
{
	if (val1 < val1)
		return (val1);
	return (val2);
}
size_t	ft_strlen(const char *s);
ssize_t	linelen(char buffer[BUFFER_SIZE], ssize_t max);
void	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);

char	*get_next_line(int fd);

#endif