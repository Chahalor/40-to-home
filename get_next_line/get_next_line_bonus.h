/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 08:52:35 by nduvoid           #+#    #+#             */
/*   Updated: 2024/11/04 10:05:31 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# ifndef MAX_FD
#  define MAX_FD 1024
# endif

typedef struct s_fd
{
	char	buffer[BUFFER_SIZE];
	ssize_t	buffer_use;
}	t_fd;

// utils
ssize_t	linelen(char *buffer, ssize_t start, ssize_t max);
char	*gnl_substr(const char *buffer, ssize_t start, size_t size);
ssize_t	get_buffer_use(t_fd lst_fd[MAX_FD]);

char	*get_next_line(int fd);

#endif
