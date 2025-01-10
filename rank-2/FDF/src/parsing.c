/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 14:38:20 by nduvoid           #+#    #+#             */
/*   Updated: 2025/01/09 09:09:37 by nduvoid          ###   ########.fr       */
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
		{
			i++;
			size++;
		}
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
	i = -1;
	while (splits[++i] && i < map->width)
	{
		map->map[map->height - 1][i] = ft_atoi(splits[i]);
		free(splits[i]);
	}
	free(splits[i]);
	free(splits);
	free(line);
}

/** @todo */
t_map	*realloc_map(t_map *map)
{
	t_type	**new_map;
	int		i;

	map->height++;
	new_map = (t_type **)ft_calloc(map->height, sizeof(t_type *));
	if (!new_map)
		return (free_map(map), NULL);
	if (map->map)
	{
		i = -1;
		while (++i < map->height - 1)
			new_map[i] = map->map[i];
		free(map->map);
	}
	i = -1;
	while (++i < map->height)
		if (!new_map[i])
			new_map[i] = (t_type *)ft_calloc(map->width, sizeof(t_type));
	map->map = new_map;
	return (map);
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
	map = (t_map *)ft_calloc(1, sizeof(t_map));
	if (!map)
		return (NULL);
	map->height = 0;
	map->width = get_line_size(line);
	map->map = NULL;
	map->iso_map = NULL;
	while (line)
	{
		map = realloc_map(map);
		if (!map)
			return (free(line), NULL);
		line_to_map(map, line);
		line = get_next_line(fd);
	}
	close(fd);
	return (free(line), map);
}

/** @todo */
void	free_map(t_map *map)
{
	t_type	i;

	i = 0;
	while (i < map->height)
	{
		free(map->map[i]);
		i++;
	}
	free(map->iso_map);
	free(map->map);
	free(map);
}
