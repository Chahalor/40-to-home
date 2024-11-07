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
#include "../get_next_line.h"

int test_get_next_line(int fd)
{
	int		sum = 0;
	char	*line = NULL;
	int		i = 0;

	i = 0;
	if (fd == 0)
	{
		line = get_next_line(fd);
		sum = printf("%s", line);
		free(line);
		return (sum);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		sum += printf("%s", line);
		free(line);
		i++;
	}
	return (i);
}

int	*test_gnl_bonus(int fd1, int fd2, int result[3])
{
	int		sum1 = 0;
	int		sum2 = 0;
	char	*line1 = NULL;
	char	*line2 = NULL;

	while ((line1 = get_next_line(fd1)) != NULL || (line2 = get_next_line(fd2)) != NULL)
	{
		sum1 += printf("1 : %s", line1);
		sum2 += printf("2 : %s", line2);
		free(line1);
		free(line2);
	}
	result[0] = sum1;
	result[1] = sum2;
	result[2] = sum1 + sum2;
	return (result);
}

int main(int argc, const char *argv[])
{
	int fd1 = -1;
	int	fd2 = -1;

	if (argc > 1)
	{
		fd1 = open(argv[1], O_RDWR);
		fd2 = open(argv[2], O_RDWR);
	}
	else
	{
		fd1 = open("test/langueur.txt", O_RDWR);
		fd2 = open("test/endormi.txt", O_RDWR);
	}

	printf("%s", get_next_line(fd1));
	// printf("%s", get_next_line(fd1));
	// printf("%s", get_next_line(fd1));
	// printf("%s", get_next_line(fd1));
	// printf("%s", get_next_line(fd1));
	// printf("%s", get_next_line(fd1));
	// printf("%s", get_next_line(fd1));
	// printf("%s", get_next_line(fd1));

	close(fd1);
	close(fd2);

	return 0;
}
