/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 10:52:40 by nduvoid           #+#    #+#             */
/*   Updated: 2025/02/10 12:08:59 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/internal_cmd.h"
#include "cmd.h"

__attribute__((unused, cold)) static void	get_status(t_fdf *fdf)
{
	if (DEBUG == 1)
		d_print_fdf(fdf);
	else
	{
		ft_printf("fdf->pos = %p\n", fdf->pos);
		ft_printf("├──fdf->pos->zoom = %d\n", fdf->pos->zoom);
		ft_printf("├──fdf->pos->rotationx = %f\n", fdf->pos->rotationx);
		ft_printf("├──fdf->pos->rotationy = %f\n", fdf->pos->rotationy);
		ft_printf("├──fdf->pos->paddingx = %d\n", fdf->pos->paddingx);
		ft_printf("└──fdf->pos->paddingy = %d\n", fdf->pos->paddingy);
	}
}

/**
 * @brief Execute the command by calling the corresponding function.
 * 
 * @param fdf The fdf structure.
 * @param action The command.
 * @param cmd The command.
 * 
 * @return void
 * 
 * @todo change cmd_type and put avery function call into change_algo()
 */
__attribute__((cold)) static void	do_cmd(t_fdf *fdf, t_cmd action, char **cmd,
	int len)
{
	if (action == cmd_exit || action == cmd_not_found)
		return ;
	else if (action == cmd_help)
		print_help(fdf->args->argv[0]);
	else if (action == cmd_zoom && len == 2)
		zoom_model(fdf, ft_atoi(cmd[1]));
	else if (action == cmd_rotate && len == 3)
		rotate_model(fdf, ft_atoi(cmd[1]), ft_atoi(cmd[2]));
	else if (action == cmd_move && len == 3)
		translat_model(fdf, ft_atoi(cmd[1]), ft_atoi(cmd[2]));
	else if (action == cmd_draw)
		draw_projection(fdf);
	else if (action == cmd_status)
		get_status(fdf);
	else if (action == cmd_reset)
		draw_projection(fdf);
	else if (action == cmd_type && len == 2)
		change_algo(fdf, ft_atoi(cmd[1]));
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
__attribute__((cold)) void	cmd(t_fdf *data)
{
	char	*line;
	char	**_cmd;
	t_cmd	action;
	int		len;
	void	*func();

	ft_printf("%s:\n└──> ", data->args->argv[0]);
	line = get_next_line(0);
	if (!line)
		return ;
	_cmd = ft_split(line, ' ');
	action = parse_input(_cmd[0]);
	len = len_cmd(_cmd);
	do_cmd(data, action, _cmd, len);
	if (action == cmd_not_found)
		ft_printf("Command not found: %s\n", _cmd[0]);
	free(line);
	while (len--)
		free(_cmd[len]);
	free(_cmd);
	if (action == cmd_exit)
		exiting(data, no_error, NULL);
	else if (action == cmd_not_found)
		cmd(data);
}
