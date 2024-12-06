/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mi_exefind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:44:23 by jegirard          #+#    #+#             */
/*   Updated: 2024/12/06 17:44:37 by jegirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	mi_exefind(t_cmd *mi_cmd, t_sys *mi_sys)
{
	char		*cmd;
	char		**paths;
	int			i;
	char		*error_msg;

	if (access(mi_cmd->args[0], F_OK) == 0)
		return ;
	i = 0;
	cmd = join_3(mi_getenv("PWD", mi_sys), "/", mi_cmd->args[0]);
	if (access(mi_cmd->args[0], F_OK) == 0)
	{
		free(cmd);
		return ;
	}
	free(cmd);
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
	error_msg = join_3 ("minishell: ", mi_cmd->args[0], ": command not found\n");
	mi_logerror(126, error_msg, mi_sys);
	free(paths);
	return ;
}
