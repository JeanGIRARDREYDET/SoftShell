/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mi_execbuiltin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard  <jegirard@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 11:38:34 by jegirard          #+#    #+#             */
/*   Updated: 2024/12/07 13:24:53 by jegirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	mi_freesysexit(int status, t_sys *mi_sys)
{
	mi_freesys(mi_sys);
	exit (status);
}

void	mi_iddir(t_cmd *mi_cmd, t_sys *mi_sys)
{
	if (mi_cmd->full && mi_cmd->full[0] == '.')
		mi_logerror2(126, mi_cmd->args[0], "Is a directory", mi_sys);
	else if (mi_cmd->args && mi_cmd->args[0] && mi_cmd->args[0][0] == '/')
		mi_logerror2(126, mi_cmd->args[0], "No such file or directory", mi_sys);
	else
		mi_logerror2(127, mi_cmd->args[0], "command not found", mi_sys);
}

void	mi_execbuiltinbody(t_cmd *mi_cmd, int fd, t_sys *mi_sys)
{
	char		*cmd;

	cmd = mi_cmd->args[0];
	if (!mi_cmd->full)
		;
	else if (ft_findword(cmd, "cd"))
		builtin_cd(mi_cmd->args, fd, mi_sys);
	else if (ft_findword(cmd, "echo"))
		builtin_echo(mi_cmd, fd);
	else if (ft_findword(cmd, "env"))
		builtin_env(mi_sys, fd);
	else if (ft_findword(cmd, "exit"))
		builtin_exit(mi_cmd->args, mi_sys);
	else if (ft_findword(cmd, "export"))
		builtin_export(mi_cmd->args, fd, mi_sys);
	else if (ft_findword(cmd, "pwd"))
		builtin_pwd(fd);
	else if (ft_findword(cmd, "unset"))
		mi_cmdargsiter(mi_cmd->args, mi_sys, &builtin_unset);
	else if (mi_cmd->isdir == true)
		mi_iddir(mi_cmd, mi_sys);
}

void	mi_execbuiltin(t_cmd *mi_cmd, int fd, t_sys *mi_sys)
{
	if (mi_sys->error)
		return ;
	if (mi_redistypexist(INPUT, mi_cmd))
		mi_logerror2(1, "file_name", "No such file or directory", mi_sys);
	mi_execbuiltinbody(mi_cmd, fd, mi_sys);
	if (mi_sys->nb_pipe > 1)
		mi_freesysexit(mi_sys->exit_status, mi_sys);
}
