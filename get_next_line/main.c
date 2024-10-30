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
#include <unistd.h>
#include <fcntl.h>

int main(void)
{
	// char	*line = "sus \nhey \nAmOgUs";
	// printf("linelen('%s') = %zu\n", line, linelen(line, 17));
	// char	*new = gnl_strdup(line, 5);
	// printf("new : %s\n", new);
	// free(new);

	int fd = open("tkt.txt", O_RDONLY);
	if (fd == -1)
		return (1);
	printf("fd %d, line 1 : %s", fd, get_next_line(fd));
	// printf("fd %d, line 2 : %s", fd, get_next_line(fd));

	close(fd);

	// char	buff[1024];
	// read(STDIN_FILENO, buff, 1024);
	// printf("stdin : %s\n", buff);
	return 0;
}
