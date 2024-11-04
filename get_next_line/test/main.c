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

int	ft_strlen(const char *s)
{
	int i = 0;
	while (s[i])
		i++;
	return (i);
}

int test_get_next_line(int fd)
{
	int		sum = 0;
	char	*line = NULL;

	// while ((line = get_next_line(fd)) != NULL)
	// {
	// 	sum += printf("%s", line);
	// 	free(line);
	// }
	line = get_next_line(fd);
	if (line == NULL)
	{
		printf("%s", line);
		return (0);
	}
	sum = printf("%s", line);
	free(line);
	return (sum);
}

int main()
{
	int fd = open("test/one_line_no_nl.txt", O_RDONLY);

	// int sum = test_get_next_line(fd);
	printf("%s", get_next_line(fd));
	// printf("| sum=%d ", sum);

	close(fd);
	return 0;
}
