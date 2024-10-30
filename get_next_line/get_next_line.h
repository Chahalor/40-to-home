/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 08:23:23 by nduvoid           #+#    #+#             */
/*   Updated: 2024/10/27 08:23:23 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
#include <stdio.h>	// rm

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# define LST_FD_SZ 1024 + 1
# define MAX_FD 1024
enum	e_bool
{
	FALSE,
	TRUE
};

typedef struct s_lst_fd
{
	char	*content;
	int		readed;
}	t_lst_fd;

// utils
ssize_t	linelen(char *buffer, ssize_t max);
char	*gnl_strdup(const char *buffer, ssize_t size);

char		*get_next_line(int fd);

#endif