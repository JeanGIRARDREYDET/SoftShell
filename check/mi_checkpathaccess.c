/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mi_checkpathaccess.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard  <jegirard@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 09:43:56 by jegirard          #+#    #+#             */
/*   Updated: 2024/12/07 13:24:53 by jegirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <sys/types.h>
#include <dirent.h>

static void	mi_checkoneaccess(char *path, t_cmd *mi_cmd)
{
	char		*pathcmd;

	pathcmd = join_3(path, "/", mi_cmd->args[0]);
	if (access(pathcmd, F_OK) == 0)
	{
		free(mi_cmd->args[0]);
		mi_cmd->args[0] = ft_strdup(pathcmd);
		mi_cmd->found = true ;
	}
	free(pathcmd);
}

static void	mi_checkenvpathaccess(t_cmd *mi_cmd, t_sys *mi_sys)
{
	int			i;
	char		**paths;
	char		*pathstring;

	pathstring = mi_getenv("PATH", mi_sys);
	if (pathstring != NULL)
	{
		paths = ft_split (pathstring, ':');
		i = 0;
		while (!mi_cmd->found && paths && paths[i])
		{
			mi_checkoneaccess(paths[i], mi_cmd);
			i++;
		}
		ft_arrclose(paths);
	}
	if (mi_sys->senv->path != NULL)
		mi_checkoneaccess(mi_sys->senv->path, mi_cmd);
}

static void	mi_checkdireaccess(t_cmd *mi_cmd)
{
	if (!mi_cmd || !mi_cmd->args || !mi_cmd->args[0])
		return ;
	mi_cmd->isdir = false;
	if (chdir(mi_cmd->args[0]) == 0)
	{
		mi_cmd->isdir = true;
		mi_cmd->builtin = true;
	}
	return ;
}

void	mi_checkpathaccess(t_cmd *mi_cmd, t_sys *mi_sys)
{
	mi_cmd->found = false;
	if (mi_cmd->isdir == true)
		return ;
	if (!mi_cmd || mi_cmd->builtin == true || !mi_cmd->args || !mi_cmd->args[0])
		return ;
	if (!mi_cmd->found && access(mi_cmd->args[0], F_OK) == 0)
	{
		mi_cmd->found = true ;
	}
	if (mi_cmd->full && mi_cmd->full[0] != '.')
		mi_checkenvpathaccess (mi_cmd, mi_sys);
	mi_checkdireaccess(mi_cmd);
	mi_checkoneaccess(mi_getenv_env("PWD", mi_sys), mi_cmd);
}
