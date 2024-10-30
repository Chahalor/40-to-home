/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 08:47:30 by nduvoid           #+#    #+#             */
/*   Updated: 2024/10/27 08:47:30 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int main(void)
{
	char	*line = "sus\n";

	printf("linelen=%d\n", linelen(line, BUFFER_SIZE));
	t_data	*data = new_t_data(1, 10);
	add_end_lst(&data, new_t_data(2, 11));
	add_end_lst(&data, new_t_data(3, 12));

	t_data	*tmp = data;
	while (tmp)
	{
		printf("fd=%d, size=%d, next=%p\n", tmp->fd, tmp->size, tmp->next);
		tmp = tmp->next;
	}
	printf("buffer use=%d\n", get_buffer_use(data));
	printf("already read ? %d\n", is_fd_already_read(4, &data));
	return 0;
}
