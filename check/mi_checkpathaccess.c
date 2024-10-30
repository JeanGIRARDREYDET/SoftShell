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

void	mi_checkenvpathaccess(t_cmd *mi_cmd, t_sys *mi_sys)
{
	int			i;
	char		*pathcmd;
	char		**paths;
	char		*pathstring;

	pathstring = ft_strdup(mi_getenv("PATH", mi_sys));
	paths = ft_split (pathstring, ':');
	free(pathstring);
	i = 0;
	while (paths && paths[++i])
	{
		pathcmd = join_3(paths[i], "/", mi_cmd->cmd);
		if (access(pathcmd, F_OK) == 0)
		{
			mi_cmd->cmd = ft_strdup(pathcmd);
			free(pathcmd);
			ft_arrclose(paths);
			return ;
		}
		free(pathcmd);
	}
	ft_arrclose(paths);
	mi_logerrorlong(126, "command not found " ,"",mi_cmd->cmd, &mi_cmd->error);
}

void	mi_checkpathaccess(t_cmd *mi_cmd, t_sys *mi_sys)
{
	char		*pathcmd;

	pathcmd = NULL;
	if (!mi_cmd->cmd || mi_cmd->builtin == true)
		return ;
	if (access(mi_cmd->cmd, F_OK) == 0)
	{
		mi_cmd->cmd = ft_strdup(mi_cmd->cmd);
		return ;
	}
	pathcmd = join_3(mi_getenv_env("PWD", mi_sys->env), "/", mi_cmd->cmd);
	if (access(pathcmd, F_OK) == 0)
	{
		mi_cmd->cmd = pathcmd;
		return ;
	}
	if (pathcmd)
		free(pathcmd);
	mi_checkenvpathaccess (mi_cmd, mi_sys);
}
