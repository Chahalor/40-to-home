/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 18:35:20 by nduvoid           #+#    #+#             */
/*   Updated: 2024/11/13 18:35:20 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *update_stock(char **s, char *buffer, size_t s_strt, size_t b_strt)
{
	size_t	s_len;
	size_t	b_len;
	char	*new_str;
	size_t	i;

	if (!s || !*s || !buffer)
		return (NULL);
	s_len = ft_strlen(*s + s_strt);
	b_len = ft_strlen(buffer + b_strt);
	new_str = (char *)malloc(sizeof(char) * (s_len + b_len + 1));
	if (!new_str)
		return (NULL);
	gnl_strcpy(new_str, *s, s_strt + 1);
	gnl_strcpy(*new_str + s_len, buffer, b_strt);
	free(*s);
	return (new_str);
}

static char *get_line_old_fd(char **s, char *buffer)
{
	char	tmp[BUFFER_SIZE + 1];
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (*s && (*s)[i] != '\n' && (*s)[i] != '\0' && i < BUFFER_SIZE)
	{
		tmp[i] = (*s)[i];
		i++;
	}
	if (*s && (*s)[i] == '\n')
	{
		tmp[i] = '\n';
		tmp[i + 1] = '\0';
		*s = update_stock(s, buffer, i, j);
		return (gnl_strdup(tmp));
	}
	while (buffer[j] != '\n' && buffer[j] != '\0' && i < BUFFER_SIZE)
		tmp[i++] = buffer[j++];
	if (buffer[j] == '\n' && i < BUFFER_SIZE)
		tmp[i++] = '\n';
	tmp[i] = '\0';
	*s = update_stock(s, buffer, i, j);
	return (gnl_strdup(tmp));
}

static char	*get_line_new_fd(char **s, char *buffer, size_t rbytes)
{
	size_t	i;
	char	tmp[BUFFER_SIZE + 1];

	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0' && i < BUFFER_SIZE)
	{
		tmp[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n' && i < BUFFER_SIZE)
		tmp[i++] = '\n';
	tmp[i] = '\0';
	*s = (char *)malloc(sizeof(char) * (rbytes - i + 1));
	if (!*s)
		return (NULL);
	gnl_strcpy(*s, buffer, i);
	return (gnl_strdup(tmp));
}

char	*get_next_line(int fd)
{
	static char	*stock[MAX_FD] = {NULL};
	char		buffer[BUFFER_SIZE + 1];
	ssize_t		rbytes;

	if (fd == -1 || fd > MAX_FD || BUFFER_SIZE <= 0)
		return (NULL);
	rbytes = read(fd, buffer, BUFFER_SIZE);
	if (rbytes == -1)
		return (NULL);
	buffer[rbytes] = '\0';
	if (stock[fd] != NULL)
		return (get_line_old_fd(&stock[fd], buffer));
	return (get_line_new_fd(&stock[fd], buffer, rbytes));
}

// int main(void)
// {
// 	// char	*s = "world ";
// 	// char	*buffer = "hello";
// 	// printf("line : %s\n", get_line(&s, buffer));
// 	// printf(update_stock(&s, buffer, 10, 0));
// 	int fd = open("test/langueur.txt", 0);
// 	printf("FD : %d\n", fd);
// 	char	*line = NULL;
// 	line = get_next_line(fd);
// 	printf("line : %s", line);
// 	free(line);	line = get_next_line(fd);
// 	printf("line : %s", line);
// 	free(line);	line = get_next_line(fd);
// 	printf("line : %s", line);
// 	free(line);
// 	close(fd);
// 	return (0);
// }