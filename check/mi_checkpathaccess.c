/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mi_checkpathaccess.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard <jegirard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 01:00:49 by jegirard          #+#    #+#             */
/*   Updated: 2024/10/14 20:05:18 by jegirard         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../minishell.h"

void	mi_checkpathaccess (t_pipe *mi_pipe, t_sys *mi_sys)
{
	int			i;
	char		*pathcmd;
	char		**paths;
	char		*pathstring;


	// printf("avant access\n");
	// printf("mi_pipe->cmd = %s et addr = %p\n", mi_pipe->cmd, mi_pipe->cmd);
	// printf("mi_pipe->cmd = %s et addr = %p\n", mi_pipe->next->cmd, mi_pipe->next->cmd);
	if (mi_pipe->cmd || access(mi_pipe->cmd, F_OK) == 0)
		return ;
	// printf("apre access\n");
	// printf("mi_pipe->cmd = %s et addr = %p\n", mi_pipe->cmd, mi_pipe->cmd);
	// printf("mi_pipe->cmd = %s et addr = %p\n", mi_pipe->next->cmd, mi_pipe->next->cmd);
	pathcmd = join_3(mi_getenv("PWD", mi_sys), "/", mi_pipe->cmd);
	if (access(pathcmd, F_OK) == 0)
		return ;
	pathstring = ft_strdup(mi_getenv("PATH", mi_sys));
	paths = ft_split (pathstring, ':');
	i = 0;
	while (paths && paths[++i])
	{
		pathcmd = join_3(paths[i], "/", mi_pipe->cmd);
		if (access(pathcmd, F_OK) == 0)
		{
			mi_pipe->cmd = pathcmd;
			free(paths);
			return ;
		}
		free(pathcmd);
	}
}
