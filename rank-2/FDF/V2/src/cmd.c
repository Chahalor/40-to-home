/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 10:52:40 by nduvoid           #+#    #+#             */
/*   Updated: 2025/02/03 15:13:42 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/**
 * @brief Get the length of a command.
 * 
 * @param cmd The command.
 * 
 * @return int The length of the command.
 */
static int	len_cmd(char **cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
		i++;
	return (i);
}

static void	get_status(t_fdf *fdf)
{
	ft_printf("fdf->pos = %p\n", fdf->pos);
	ft_printf("├──fdf->pos->zoom = %d\n", fdf->pos->zoom);
	ft_printf("├──fdf->pos->rotationx = %f\n", fdf->pos->rotationx);
	ft_printf("├──fdf->pos->rotationy = %f\n", fdf->pos->rotationy);
	ft_printf("├──fdf->pos->paddingx = %d\n", fdf->pos->paddingx);
	ft_printf("└──fdf->pos->paddingy = %d\n", fdf->pos->paddingy);
}

/**
 * @brief Parse the input command.
 * 
 * @param line The command.
 * 
 * @return t_cmd The command.
 */
static t_cmd	parse_input(char *line)
{
	t_cmd	action;

	if (strcmp(line, "exit\n") == 0)
		action = exit_cmd;
	else if (strcmp(line, "help\n") == 0)
		action = help_cmd;
	else if (strcmp(line, "reset\n") == 0)
		action = reset_cmd;
	else if (strcmp(line, "zoom\n") == 0)
		action = zoom_cmd;
	else if (strcmp(line, "rotate") == 0)
		action = rotate_cmd;
	else if (strcmp(line, "move") == 0)
		action = move_cmd;
	else if (strcmp(line, "draw\n") == 0)
		action = draw_cmd;
	else if (strcmp(line, "quit\n") == 0 || strcmp(line, "q\n") == 0)
		action = quit_cmd;
	else if (strcmp(line, "reset\n") == 0)
		action = reset_cmd;
	else if (strcmp(line, "status\n") == 0)
		action = status_cmd;
	else
		action = not_found;
	return (action);
}

/**
 * @brief Execute the command by calling the corresponding function.
 * 
 * @param fdf The fdf structure.
 * @param action The command.
 * @param cmd The command.
 * 
 * @return void
 */
static void	do_cmd(t_fdf *fdf, t_cmd action, char **cmd, char *line)
{
	int	len;

	len = len_cmd(cmd);
	if (action == exit_cmd || action ==  quit_cmd)
		return ;
	else if (action == help_cmd)
		print_help(fdf->args->argv[0]);
	else if (action == zoom_cmd && len == 2)
		zoom_model(fdf, ft_atoi(cmd[1]));
	else if (action == rotate_cmd && len == 3)
		rotate_model(fdf, ft_atoi(cmd[1]), ft_atoi(cmd[2]));
	else if (action == move_cmd && len == 3)
		translat_model(fdf, ft_atoi(cmd[1]), ft_atoi(cmd[2]));
	else if (action == draw_cmd)
		draw_projection(fdf);
	else if (action == status_cmd)
		get_status(fdf);
	else if (action == reset_cmd)
	{
		clear_model(fdf);
		draw_projection(fdf);
	}
	else
		ft_printf("invalide commande: %s", line);
}

/**
 * @brief Get the command from the user and execute it.
 * 
 * @param data The fdf structure.
 * 
 * @return void
 * 
 * @note Available commands:
 * 
 * - exit: Exit the program.
 * 
 * - quit/q: Quit the cmd.
 * 
 * - help: Display this help.
 * 
 * - reset: Reset the program.
 * 
 * - zoom: Zoom the model.
 * 
 * - rotate: Rotate the model.
 * 
 * - move: Move the model.
 * 
 * - reset: reset the model.
 * 
 * - status: Display the status of the model.
 * 
 * - cmd: Enter a new command.
 */
void	cmd(t_fdf *data)
{
	char	*line;
	char	**_cmd;
	t_cmd	action;
	int		len;

	ft_printf(">>cmd: ");
	line = get_next_line(0);
	if (!line)
		return ;
	_cmd = ft_split(line, ' ');
	len = len_cmd(_cmd);
	action = parse_input(_cmd[0]);
	do_cmd(data, action, _cmd, line);
	free(line);
	while (len--)
		free(_cmd[len]);
	free(_cmd);
	if (action == exit_cmd)
		exiting(data, no_error, NULL);
	else if (action == not_found)
		cmd(data);
}
