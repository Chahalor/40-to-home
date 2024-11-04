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
#include "../get_next_line.h"

int	ft_strlen(const char *s)
{
	int i = 0;
	while (s[i])
		i++;
	return (i);
}

int test_get_next_line(int fd, int fd2)
{
	char	*line;
	char	*line2;
	int sum = 0;

	while ((line = get_next_line(fd)) != NULL || (line2 = get_next_line(fd2)) != NULL)
	{
		sum += printf("%s", line);
		sum += printf("%s", line2);
		free(line);
		free(line2);
	}
	return (sum);
}

int main()
{
	int fd = open("test/empty.txt", O_RDONLY);
	int fd2 = open("test/langueur.txt", O_RDONLY);

	int sum = 0;
	// sum = test_get_next_line(fd, fd2);
	sum += printf("%s", get_next_line(fd));
	sum += printf("%s", get_next_line(fd2));
	sum += printf("%s", get_next_line(fd));
	sum += printf("%s", get_next_line(fd2));
	printf("\n sum=%d\n", sum);

	close(fd);
	close(fd2);
	return 0;
}
