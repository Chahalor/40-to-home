/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 14:38:20 by nduvoid           #+#    #+#             */
/*   Updated: 2024/12/18 14:01:37 by nduvoid          ###   ########.fr       */
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
	i = -1;
	while (splits[++i] && i < map->width)
		map->map[map->height][i] = fdf_atoi(splits[i]);
		// map->map[map->height] = NULL;
	free(splits);
	free(line);
}

/** @todo */
t_map	*realloc_map(t_map *map)
{
	t_type	**new_map;

	map->height++;
	new_map = (t_type **)ft_calloc(map->height, sizeof(t_type *) * map->width);
	if (!new_map)
		return (free(map), NULL);
	if (map->map)
	{
		ft_memcpy(new_map, map->map, map->height - 1);
		free(map->map);
	}
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
	free(map->map);
	free(map);
}
