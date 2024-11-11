/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mi_execone.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 19:50:42 by jegirard          #+#    #+#             */
/*   Updated: 2024/10/04 19:50:46 by jegirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	mi_exefind(t_cmd *mi_cmd, t_sys *mi_sys)
{
	char		*cmd;
	char		**paths;
	int			i;
	char		*error_msg;

	i = 0;
	if (access(mi_cmd->cmd, F_OK) == 0)
		return ;
	i = 0;
	cmd = join_3(mi_getenv("PWD", mi_sys), "/", mi_cmd->cmd);
	if (access(mi_cmd->cmd, F_OK) == 0)
		return ;
	paths = ft_split (mi_getenv("PATH", mi_sys), ':');
	while (paths && paths[++i])
	{
		cmd = join_3(paths[i], "/", mi_cmd->cmd);
		if (access(cmd, F_OK) == 0)
		{
			mi_cmd->cmd = ft_strdup(cmd);
			free(paths);
			return ;
		}
		free(cmd);
	}
	error_msg = join_3 ("minishell: ", mi_cmd->cmd, ": command not found\n");
	mi_logerror(126, error_msg, mi_sys);
	free(cmd);
	free(paths);
	return ;
}

void	mi_exepermis(t_cmd *mi, t_sys *mi_sys)
{
	if (access(mi->cmd, X_OK) == 0)
		return ;
	mi_logerrorlong(126, "mi: ", mi->cmd, ": Permission denied", mi_sys);
	mi_sys->nb_error++;
}

void	mi_execone(t_cmd *mi_cmd, t_sys *mi_sys)
{
	if (mi_sys->nb_pipe == 1 && mi_cmd->builtin)
	{
		mi_execbuiltin(mi_cmd, mi_sys);
		return ;
	}
	if (mi_cmd->next != NULL)
	{
		if (pipe(mi_cmd->fd) == -1)
		{	
			mi_intlogerror (mi_sys, "pipe out failed", 1);
			return ;
		}
	}
	mi_cmd->id = fork();
	if (mi_cmd->id == -1)
	{
		mi_intlogerror (mi_sys, "fork out failed", 1);
		return ;
	}
	if (mi_cmd->id == 0)
	{
		if (mi_cmd->no != 0)
		{
			if (dup2(mi_sys->fd_in, STDIN_FILENO) == -1)
				return ;
			close (mi_sys->fd_in);
		}
		if (mi_cmd->next != NULL)
		{
			if (dup2(mi_cmd->fd[1], STDOUT_FILENO) == -1)
				return ;
			close (mi_cmd->fd[0]);
			close (mi_cmd->fd[1]);
		}
		if (mi_cmd->cmd != NULL)
			mi_execcmd(mi_cmd, mi_sys);
	}
	if (mi_cmd->no != 0)
		close (mi_sys->fd_in);
	if (mi_cmd->next != NULL)
	{
		close (mi_cmd->fd[1]);
		mi_sys->fd_in = mi_cmd->fd[0];
	}
	return ;
}
