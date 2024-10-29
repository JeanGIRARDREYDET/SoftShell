/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mi_execcmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 12:07:44 by jegirard          #+#    #+#             */
/*   Updated: 2024/07/24 12:07:48 by jegirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	mi_exebuiltin(t_cmd *mi_cmd, t_sys *mi_sys)
{
	char	*cmd;

	cmd = mi_cmd->builtin_cmd;
	if (mi_sys->env == NULL)
	{
		dprintf(2, "			mi_exebuiltin env  NULL\n");
	}
	if (ft_findword("cd", cmd))
		builtin_cd(mi_cmd->arg, mi_sys);
	else if (ft_findword("echo", cmd))
		builtin_echo(mi_cmd->arg);
	else if (ft_findword("env", cmd))
		builtin_env(mi_sys);
	else if (ft_findword("exit", cmd))
		builtin_exit();
	else if (ft_findword("export", cmd))
		builtin_export(mi_cmd->arg, mi_sys);
	else if (ft_findword("pwd", cmd))
		builtin_pwd();
	else if (ft_findword("unset", cmd))
		builtin_unset(mi_cmd->arg, mi_sys);
}

//	dprintf(2, "	mi_execcmd ('%s') \n", mi_cmd->cmd);

int	mi_execcmd(t_cmd *mi_cmd, t_sys *mi_sys)
{
	if (mi_cmd->cmd == NULL && mi_cmd->builtin_cmd == NULL)
		return (1);
	if (mi_cmd->builtin == true)
		mi_exebuiltin(mi_cmd, mi_sys);
	else if (execve(mi_cmd->cmd, mi_cmd->split_cmd, mi_sys->env) == -1)
	{
		perror(ft_strjoin("Command :", mi_cmd->cmd));
		mi_logerror(126, "Command found but in error ", &mi_cmd->error);
		return (errno);
	}
	return (1);
}
