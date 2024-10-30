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

// # define BUFFER_SIZE 1

typedef struct s_data
{
	int				fd;
	size_t			size;
	struct s_data	*next;
}	t_data;

// get_next_line_utils.c	5
size_t	linelen(char *s, size_t max);
t_data	*new_t_data(int fd, size_t content_size);
size_t	get_buffer_use(t_data *data);
void	add_end_lst(t_data **lst, t_data *elt);
int		is_fd_already_read(int fd, t_data **data);

// get_next_line.c
char	*get_next_line(int fd);
char	*rd_until_nxt_line(int fd, size_t buffer_use);

#endif