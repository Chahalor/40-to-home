/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 11:48:47 by nduvoid           #+#    #+#             */
/*   Updated: 2025/02/07 11:21:20 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/**
 * @brief Get the size of a line.
 * 
 * @param line The line.
 * @return The size of the line.
 * 
 * @example
 * ```c
 * int size = get_line_size("1 2 3 4 5"); // size = 4
 * ```
 */
static int	get_line_size(const char *line)
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

/**
 * @brief Convert a line to a map, extract all int from the line
 * and store them in the map.
 * 
 * @param map The map.
 * @param line The line.
 * 
 * @example
 * ```c
 * line_to_map(map, "1 2 3 4 5"); // map = {1, 2, 3, 4, 5}
 * ```
 */
static void	line_to_map(t_map *map, char *line)
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
	while (splits[i])
		free(splits[i++]);
	free(splits[i]);
	free(splits);
	free(line);
	line = NULL;
}

/**
 * @brief Reallocate the map, and free the old one.
 * 
 * @param map The map.
 * @return The new map.
 */
static t_map	*realloc_map(t_map *map)
{
	int	**new_map;
	int	i;

	map->height++;
	new_map = (int **)ft_calloc(map->height, sizeof(int *));
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
			new_map[i] = (int *)ft_calloc(map->width, sizeof(int));
	map->map = new_map;
	return (map);
}

/**
 * @brief parse the map from a file, we assume that the file is well formated.
 * but the parsing is error proof.
 * 
 * @param path The path to the file.
 * @return The map.
 * 
 * @example
 * ```c
 * t_map *map = parse_map("map.fdf");
 * ```
 */
t_map	*parse_map(const char *path)
{
	int		fd;
	char	*line;
	t_map	*map;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	ft_printf("Parsing map from %s\n", path);
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
	return (free(line), map);
}

/**
 * @brief Free the map.
 * 
 * @param map The map.
 */
void	free_map(t_map *map)
{
	int	i;

	i = -1;
	while (++i < map->height)
		free(map->map[i]);
	free(map->iso_map);
	free(map->map);
	free(map);
}
