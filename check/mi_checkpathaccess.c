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

void	mi_checkpathaccess (t_cmd *mi_cmd, t_sys *mi_sys)
{
	int			i;
	char		*pathcmd;
	char		**paths;
	char		*pathstring;

	if (!mi_cmd->cmd || access(mi_cmd->cmd, F_OK) == 0 || mi_cmd->builtin == true)
		return ;
 	pathcmd = join_3(mi_getenv_env("PWD", mi_sys->env), "/", mi_cmd->cmd);
	if (access(pathcmd, F_OK) == 0)
		return ;
	pathstring = ft_strdup(mi_getenv("PATH", mi_sys));
	paths = ft_split (pathstring, ':');
	i = 0;
	
	while (paths && paths[++i])
	{
		pathcmd = join_3(paths[i], "/", mi_cmd->cmd);
		if (access(pathcmd, F_OK) == 0)
		{
			mi_cmd->cmd = pathcmd;
			free(paths);
			return ;
		}
		free(pathcmd);
	}
}
