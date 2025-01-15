/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mi_exefind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard  <jegirard@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 11:38:34 by jegirard          #+#    #+#             */
/*   Updated: 2024/12/07 13:24:53 by jegirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

bool	mi_execheckfind(t_cmd *mi_cmd, t_sys *mi_sys)
{
	char		*cmd;

	if (access(mi_cmd->args[0], F_OK) == 0)
		return (true);
	cmd = join_3(mi_getenv("PWD", mi_sys), "/", mi_cmd->args[0]);
	if (access(mi_cmd->args[0], F_OK) == 0)
	{
		free(cmd);
		return (true);
	}
	free(cmd);
	return (false);
}

void	mi_exefind(t_cmd *mi_cmd, t_sys *mi_sys)
{
	char		*cmd;
	char		**paths;
	int			i;

	i = 0;
	if (mi_execheckfind(mi_cmd, mi_sys))
		return ;
	paths = ft_split (mi_getenv("PATH", mi_sys), ':');
	while (paths && paths[++i])
	{
		cmd = join_3(paths[i], "/", mi_cmd->args[0]);
		if (access(cmd, F_OK) == 0)
		{
			mi_cmd->args[0] = ft_strdup(cmd);
			free(paths);
			return ;
		}
		free(cmd);
	}
	mi_logerror2(126, mi_cmd->args[0], ": command not found", mi_sys);
	free(paths);
	return ;
}
