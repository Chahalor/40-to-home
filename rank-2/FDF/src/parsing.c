/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 14:38:20 by nduvoid           #+#    #+#             */
/*   Updated: 2024/12/13 15:40:01 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/** @todo */
static int	get_line_size(const char *line)
{
	int	size;
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == ' ' && line[i + 1] != ' ')
			size++;
		i++;
	}
	return (size);
}

/** @todo */
static void	line_to_map(t_map *map, char *line)
{
	char	**splits;
	int		i;

	splits = ft_split(line, ' ');
	if (!splits)
		return ;
	i = 0;
	while (splits[i])
	{
		map->data[map->height][i] = fdf_atoi(splits[i]);
		i++;
	}
	free(splits);
}

/** @todo */
t_map	*realloc_map(t_map *map)
{
	t_map	*new;
	int		i;

	new = (t_map *)ft_calloc(1, sizeof(t_map) + sizeof(t_type) * map->width * map->height);
	if (!new)
		return (MALLOC_ERROR);
	new->width = map->width;
	new->height = map->height;
	i = 0;
	while (i < map->height)
	{
		new->data[i] = map->data[i];
		i++;
	}
	free(map);
	return (new);
}

/** @todo */
t_map	*parse_file(char *file)
{
	int		fd;
	char	*line;
	t_map	*map;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (OPEN_ERROR);
	map = (map *)ft_calloc(1, sizeof(t_map));
	if (!map)
		return (MALLOC_ERROR);
	line = get_next_line(fd);
	map->width = get_line_size(line);
	while (line)
	{
		map->height++;
		map = realloc_map(map);
		if (!map)
			return (MALLOC_ERROR);
		line_to_map(map, line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (map);
}
