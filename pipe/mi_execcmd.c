/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mi_execcmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 12:07:44 by jegirard          #+#    #+#             */
/*   Updated: 2024/07/24 12:07:48 by jegirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void mi_exebuiltin(t_cmd *mi_cmd, t_sys *mi_sys)
{
	if (mi_sys->env == NULL)
	{
		dprintf(2, "			mi_exebuiltin env  NULL\n");
	}
	if (ft_findword("cd", mi_cmd->cmd))
		builtin_cd(mi_cmd->arg, mi_sys);
	else if (ft_findword("echo", mi_cmd->cmd))
		builtin_echo(mi_cmd->arg);
	else if (ft_findword("env", mi_cmd->cmd))
		builtin_env(mi_sys);
	else if (ft_findword("exit", mi_cmd->cmd))
		builtin_exit();
	else if (ft_findword("export", mi_cmd->cmd))
		builtin_export(mi_cmd->arg, mi_sys);
	else if (ft_findword("pwd", mi_cmd->cmd))
		builtin_pwd();
	else if (ft_findword("unset", mi_cmd->cmd))
		builtin_unset(mi_cmd->arg, mi_sys);
}


int	mi_execcmd(t_cmd *mi_cmd, t_sys *mi_sys)
{
	dprintf(2, "	mi_execcmd ('%s') \n", mi_cmd->cmd);

if (mi_sys->env == NULL)
	{
		dprintf(2, "			mi_execcmd env  NULL\n");

	}

	if (mi_cmd->cmd == NULL)
		return (1);
	//		dprintf(2, "		cmd builtin\n");	
	if(mi_cmd->builtin == true)
	{
		dprintf(2, "	<cmd builtin>\n");
		mi_exebuiltin(mi_cmd, mi_sys);
		dprintf(2, "	</cmd builtin>\n");
	}else if (execve(mi_cmd->cmd, mi_cmd->split_cmd, mi_sys->env) == -1)
	{
//		dprintf(2, "		cmd error\n");
		perror(ft_strjoin("Command :", mi_cmd->cmd));
		mi_logerror(126, "Command found but in error ", &mi_cmd->error);
		return (errno);
	}
//	dprintf(2, "		cmd ret1./m\n");
	return (1);
}
