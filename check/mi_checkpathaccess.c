/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mi_checkpathaccess.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard <jegirard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 01:00:49 by jegirard          #+#    #+#             */
/*   Updated: 2024/10/20 19:39:39 by jegirard         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../minishell.h"

void	mi_checkoneaccess(char *path, t_cmd *mi_cmd)
{
	char		*pathcmd;

	pathcmd = join_3(path, "/", mi_cmd->cmd);
	if (access(pathcmd, F_OK) == 0)
	{
		mi_cmd->cmd = ft_strdup(pathcmd);
		mi_cmd->cmd_found = true ;
	}
	free(pathcmd);
}

void	mi_checkenvpathaccess(t_cmd *mi_cmd, t_sys *mi_sys)
{
	int			i;
	char		**paths;
	char		*pathstring;

	pathstring = mi_getenv("PATH", mi_sys);
	if(pathstring != NULL)
	{
		paths = ft_split (pathstring, ':');
		// free(pathstring);
		i = 0;
		while (!mi_cmd->cmd_found && paths && paths[++i])
			mi_checkoneaccess(paths[i], mi_cmd);
		ft_arrclose(paths);
	}
	mi_checkoneaccess("/usr/bin", mi_cmd);
}

void	mi_checkpathaccess(t_cmd *mi_cmd, t_sys *mi_sys)
{
	char		*errormsg;

	mi_cmd->cmd_found = false;
	if (!mi_cmd->cmd || mi_cmd->builtin == true)
		return ;
	if (!mi_cmd->cmd_found && access(mi_cmd->cmd, F_OK) == 0)
	{
		mi_cmd->cmd = ft_strdup(mi_cmd->cmd);
		mi_cmd->cmd_found = true ;
	}
	mi_checkoneaccess(mi_getenv_env("PWD", mi_sys->env), mi_cmd);
	mi_checkenvpathaccess (mi_cmd, mi_sys);
	if (!mi_cmd->cmd_found)
	{
		errormsg = ft_strjoin("command not found ", mi_cmd->cmd);
		mi_cmd->cmd = ft_strdup(mi_cmd->cmd);
		mi_logerror(126, errormsg, &mi_cmd->error);
		free(errormsg);
	}
}
