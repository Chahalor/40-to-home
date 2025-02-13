/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 10:14:58 by nduvoid           #+#    #+#             */
/*   Updated: 2025/02/13 10:34:01 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* -----| Header |----- */
// Global
#include "struct.h"
#include "type.h"

// Modules
//...

// Internes
#include "interne/_parsing_env.h"

__attribute__((malloc)) char *build_path(const char *dir, const char *file)
{
	char	*path;

	path = (char *)malloc(sizeof(char) * (ft_strlen(dir) + ft_strlen(file) + 2));
	if (!path)
		return (NULL);
	ft_strlcpy(path, dir, ft_strlen(dir) + 1);
	ft_strlcat(path, "/", ft_strlen(dir) + 2);
	ft_strlcat(path, file, ft_strlen(dir) + ft_strlen(file) + 2);
	return (path);
}

static char	*find_bin(const char *cmd, const char **paths)
{
	char	*path;
	int		i;

	i = -1;
	while (paths[++i])
	{
		path = build_path(paths[i], cmd);
		if (!path)
			return (NULL);
		if (access(path, F_OK) == 0)
			return (path);
		free(path);
	}
	return (NULL);
}

t_cmd	*parse_cmd(t_args *args)
{
	t_cmd	*cmd;
	char	**paths;

	paths = ft_split(args->path, ':');
	if (!paths)
		return (NULL);
	while (args->cmd)
	{
		cmd = (t_cmd *)malloc(sizeof(t_cmd));
		if (!cmd)
			return (NULL);
		cmd->bin = find_bin(args->cmd, (const char **)paths);
		if (!cmd->bin)
			return (NULL);
		cmd->cmd = args->cmd;
		cmd->args = args->args;
		args++;
	}
}