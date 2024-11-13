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

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <ctype.h>
#include "../get_next_line.h"

int	nduvoid_test_gnl(int fd, int nb_iter)
{
	printf("NUMBER OF ITERATION	: %d\n", nb_iter);
	printf("FILE DESCRIPTOR		: %d\n", fd);
	printf("BUFFER_SIZE		: %d\n", BUFFER_SIZE);
	printf("\n");

	int	i = 0;
	while (i < nb_iter)
	{
		char	*line = get_next_line(fd);
		printf(".%d : %s", i, line);
		if (line == NULL)
			printf("\n");
		printf("----\n");
		free(line);
		i++;
	}
	return (i);
}

int main(int argc, const char *argv[])
{
	int		fd1 = -1;
	int		fd2 = -1;
	char	*file1 = NULL;
	char	*file2 = NULL;

	if (argc > 2)
	{
		file1 = (char *)argv[1];
		file2 = (char *)argv[2];
		fd1 = open(file1, O_RDWR);
		fd2 = open(file2, O_RDWR);
	}
	else
	{
		file1 = "test/langueur.txt";
		file2 = "test/endormi.txt";
		fd1 = open(file1, O_RDWR);
		fd2 = open(file2, O_RDWR);
	}

	printf("FILE			: %s\n", file1);
	printf("\niteration=%d\n", nduvoid_test_gnl(fd1, 10));

	close(fd1);
	close(fd2);
	return (0);
}
