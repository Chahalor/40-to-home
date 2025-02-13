/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:36:35 by nduvoid           #+#    #+#             */
/*   Updated: 2025/02/13 09:49:50 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* -----| Header |----- */
// Global
#include "struct.h"
#include "type.h"
#include "config.h"

// Modules
//...

// Internes
# include "interne/_debug.h"

//└── ├──
void	d_print_cmd(t_cmd *cmd)
{
	if (!DEBUG)
		return ;
	if (!cmd)
		return ((void)write(1, "cmd=(null)\n", 11));
	ft_printf("cmd: %p\n", cmd);
	ft_printf("├──cmd->bin: %s\n", cmd->bin);
	ft_printf("├──cmd->cmd: %s\n", cmd->cmd);
	ft_printf("└──cmd->args: %p\n", cmd->args);
	while (cmd->args && *cmd->args)
		ft_printf("   ├──cmd->args: %s\n", *cmd->args++);
	ft_printf("   └──cmd->args: %s\n", *cmd->args);
	
}

void	d_print_args(t_args *args)
{
	if (!DEBUG)
		return ;
	if (!args)
		return ((void)write(1, "args=(null)\n", 12));
	ft_printf("args: %p\n", args);
	ft_printf("├──args->file_in: %s\n", args->file_in);
	ft_printf("├──args->file_out: %s\n", args->file_out);
	ft_printf("├──args->path: %s\n", args->path);
	ft_printf("├──args->envp: %p\n", args->envp);
	while (args->envp && *args->envp)
		ft_printf("│   ├──args->envp: %s\n", *args->envp++);
	ft_printf("│   └──args->envp: %s\n", *args->envp);
	ft_printf("└──args->cmd: %p\n", args->cmd);
	while (args->cmd && *args->cmd)
		ft_printf("   ├──args->cmd: %s\n", *args->cmd++);
	ft_printf("   └──args->cmd: %s\n", *args->cmd);
}

void	d_print_fork(const t_fork *fork)
{
	if (!DEBUG)
		return ;
	if (!fork)
		return ((void)write(1, "fork=(null)\n", 12));
	ft_printf("fork: %p\n", fork);
	ft_printf("├──fork->pid: %d\n", fork->pid);
	ft_printf("└──fork->status: %d\n", fork->status);
}