/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mi_execbuiltin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard <jegirard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 13:50:25 by jegirard          #+#    #+#             */
/*   Updated: 2024/12/06 07:15:30 by jegirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	mi_execexitepipe(int status, t_sys *mi_sys)
{
	mi_freesys(mi_sys);
	exit((int)status);
}

void	mi_execbuiltin(t_cmd *mi_cmd, int fd, t_sys *mi_sys)
{
	char		*cmd;

	cmd = mi_cmd->args[0];
	if (mi_sys->env == NULL)
		dprintf(2, "			mi_exebuiltin env  NULL\n");
	if (ft_findword(cmd, "cd"))
		builtin_cd(mi_cmd->args, fd, mi_sys);
	else if (ft_findword(cmd, "echo"))
		builtin_echo(mi_cmd, fd);
	else if (ft_findword(cmd, "env"))
		builtin_env(mi_sys, fd);
	else if (ft_findword(cmd, "exit"))
		builtin_exit(mi_sys);
	else if (ft_findword(cmd, "export"))
		builtin_export(mi_cmd->args, fd, mi_sys);
	else if (ft_findword(cmd, "pwd"))
		builtin_pwd(fd);
	else if (ft_findword(cmd, "unset"))
		mi_cmdargsiter(mi_cmd->args, mi_sys, &builtin_unset);
	if (mi_sys->nb_pipe > 1)
		mi_execexitepipe(mi_sys->exit_status, mi_sys);
}
