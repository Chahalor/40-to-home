/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:02:24 by nduvoid           #+#    #+#             */
/*   Updated: 2024/11/07 15:20:32 by nduvoid          ###   ########.fr       */
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
	if (val1 < val2)
		return (val1);
	return (val2);
}

size_t	get_line_len(char *s, size_t max);
char	*gnl_strdup(char *buffer, ssize_t size);
ssize_t	get_nl_pos(char buffer[BUFFER_SIZE]);
size_t	gnl_strcpy(const char buffer[BUFFER_SIZE], char *dest, size_t max);
size_t	get_stock_size(char *stock);

char	*get_next_line(int fd);

#endif