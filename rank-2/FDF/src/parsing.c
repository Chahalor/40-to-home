/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 14:38:20 by nduvoid           #+#    #+#             */
/*   Updated: 2024/12/17 14:56:23 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/** @todo */
int	get_line_size(const char *line)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (line[i])
	{
		if (line[i] == ' ' && line[i + 1] != ' ')
			size++;
		i++;
	}
	return (size);
}

/** @todo */
void	line_to_map(t_map *map, char *line)
{
	char	**splits;
	int		i;

	splits = ft_split(line, ' ');
	if (!splits)
		return ;
	i = 0;
	(void)map;
	while (splits[i])
	{
		map->map[map->height][i] = fdf_atoi(splits[i]);
		i++;
	}
	free(splits);
}

/** @todo */
t_map	*realloc_map(t_map *map)
{
	t_map	*new;
	t_type	i;

	if (!map || !map->width || !map->height || !map->map)
		return (free(map), NULL);
	new = (t_map *)ft_calloc(1, sizeof(t_map)
			+ sizeof(t_type) * map->width * map->height);
	if (!new)
		return (free(map), NULL);
	new->width = map->width;
	new->height = map->height;
	i = 0;
	while (i < map->height - 1)
	{
		new->map[i] = map->map[i];
		i++;
	}
	return (free(map), new);
}

/** @todo */
t_map	*parse_file(char *file)
{
	int		fd;
	char	*line;
	t_map	*map;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	line = get_next_line(fd);
	map = (t_map *)ft_calloc(1, sizeof(t_map) + sizeof(t_type) * get_line_size(line));
	if (!map)
		return (free(line), NULL);
	map->width = get_line_size(line);
	while (line)
	{
		map->height++;
		map = realloc_map(map);
		if (!map)
			return (free(line), NULL);
		line_to_map(map, line);
		free(line);
		line = get_next_line(fd);
	};
	close(fd);
	return (free(line), map);
}
