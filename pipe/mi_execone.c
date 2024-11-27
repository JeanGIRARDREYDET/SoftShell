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

void	mi_exepermis(t_cmd *mi, t_sys *mi_sys)
{
	if (access(mi->args[0], X_OK) == 0)
		return ;
	mi_logerrorlong(126, "mi: ", mi->args[0], ": Permission denied", mi_sys);
	mi_sys->nb_error++;
}

void	mi_execone(t_cmd *mi_cmd, t_sys *mi_sys)
{
	int	*out;
	int	*in;


	out = (int[]){OUTPUT, APPEND};
	in = (int[]){INPUT, INPUT};
	if (mi_cmd->full)
		free(mi_cmd->full);
	mi_cmd->full = NULL;
	if (mi_sys->nb_pipe == 1 && mi_cmd->builtin)
	{	
		if (mi_redis(mi_cmd, OUTPUT) || mi_redis(mi_cmd, APPEND) )
			mi_execbuiltin(mi_cmd, mi_lastred(mi_cmd->red, mi_sys ,out), mi_sys);
		else
			mi_execbuiltin(mi_cmd, STDOUT_FILENO, mi_sys);
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
	mi_sys->max_id = mi_cmd->id;
	if (mi_cmd->id == -1)
	{
		mi_intlogerror (mi_sys, "fork out failed", 1);
		return ;
	}
	if (mi_cmd->id == 0)
	{
		if (mi_redis(mi_cmd, INPUT) )
		{
			close (mi_cmd->fd[0]);
			mi_cmd->fd[0] = mi_lastred(mi_cmd->red, mi_sys,in);
			dup2(mi_cmd->red->fd, STDIN_FILENO);
			close (mi_cmd->red->fd);
		}
		if (mi_cmd->no != 0)
		{
			if (dup2(mi_sys->fd_in, STDIN_FILENO) == -1)
				return ;
			close (mi_sys->fd_in);
		}
		if (mi_redis(mi_cmd, OUTPUT) || mi_redis(mi_cmd, APPEND) )
		{
			close (mi_cmd->fd[1]);
			mi_cmd->fd[1] = mi_lastred(mi_cmd->red, mi_sys,out);
			dup2(mi_cmd->red->fd, STDOUT_FILENO);
//			close (mi_cmd->redirection->fd);
		}
		if (mi_cmd->next != NULL)
		{
			if (dup2(mi_cmd->fd[1], STDOUT_FILENO) == -1)
				return ;
			close (mi_cmd->fd[0]);
			close (mi_cmd->fd[1]);
		}
		if (mi_cmd->args[0] != NULL)
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
