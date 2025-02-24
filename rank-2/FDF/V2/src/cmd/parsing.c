/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 10:24:20 by nduvoid           #+#    #+#             */
/*   Updated: 2025/02/24 11:29:08 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"

/**
 * @brief Parse the input command.
 * 
 * @param line The command.
 * 
 * @return t_cmd The command.
 */
__attribute__((cold)) t_cmd	parse_input(char *line)
{
	if (ft_strncmp(line, "exit\n", 5) == 0)
		return (cmd_exit);
	else if (ft_strncmp(line, "help\n", 5) == 0)
		return (cmd_help);
	else if (ft_strncmp(line, "reset\n", 6) == 0)
		return (cmd_reset);
	else if (ft_strncmp(line, "zoom", 4) == 0)
		return (cmd_zoom);
	else if (ft_strncmp(line, "rotate", 6) == 0)
		return (cmd_rotate);
	else if (ft_strncmp(line, "move", 4) == 0)
		return (cmd_move);
	else if (ft_strncmp(line, "draw\n", 5) == 0)
		return (cmd_draw);
	else if (ft_strncmp(line, "quit\n", 5) == 0
		|| ft_strncmp(line, "q\n", 2) == 0)
		return (cmd_quit);
	else if (ft_strncmp(line, "reset\n", 6) == 0)
		return (cmd_reset);
	else if (ft_strncmp(line, "status\n", 7) == 0)
		return (cmd_status);
	else if (ft_strncmp(line, "type", 4) == 0)
		return (cmd_type);
	return (cmd_not_found);
}
