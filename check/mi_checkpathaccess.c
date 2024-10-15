/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mi_checkpathaccess.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard <jegirard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 01:00:49 by jegirard          #+#    #+#             */
/*   Updated: 2024/10/15 02:49:03 by jegirard         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../minishell.h"

void	mi_checkpathaccess (t_cmd *mi_cmd, t_sys *mi_sys)
{
	int			i;
	char		*pathcmd;
	char		**paths;
	char		*pathstring;

	if (!mi_cmd->cmd || access(mi_cmd->cmd, F_OK) == 0)
		return ;
 	pathcmd = join_3(mi_getenv("PWD", mi_sys), "/", mi_cmd->cmd);
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
