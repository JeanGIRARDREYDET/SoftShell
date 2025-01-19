/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mi_execone.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard  <jegirard@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 11:38:34 by jegirard          #+#    #+#             */
/*   Updated: 2024/12/07 13:24:53 by jegirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	mi_execonechildexe(t_cmd *mi_cmd, t_sys *mi_sys)
{
	if (mi_cmd->fd[0] == -1)
		return ;
	if (mi_cmd->next != NULL)
	{
		if (dup2(mi_cmd->fd[1], STDOUT_FILENO) == -1)
			return ;
		close (mi_cmd->fd[0]);
		if (mi_cmd->fd[1] == -1)
			return ;
		close (mi_cmd->fd[1]);
	}
	if (mi_cmd->args[0] != NULL)
		mi_execcmd(mi_cmd, mi_sys);
}

void	mi_execonechild(t_cmd *mi_cmd, t_sys *mi_sys, int *out, int *in)
{
	if (!mi_cmd->args[0])
	{
		dup2(mi_cmd->red->fd, STDOUT_FILENO);
		close (mi_cmd->red->fd);
		mi_execexitepipe(mi_sys->exit_status, mi_sys);
	}
	if (mi_redis(mi_cmd, INPUT) || mi_redis(mi_cmd, HEREDOC))
	{
		dprintf(2, "mi_execonechild mi_cmd->red->file_name = %s\n", mi_cmd->red->file_name);
		mi_cmd->fd[0] = mi_lastred(mi_cmd->red, mi_sys, in);
		dup2(mi_cmd->red->fd, STDIN_FILENO);
		close (mi_cmd->red->fd);
	}
	if (mi_cmd->no != 0)
	{
		if (dup2(mi_sys->fd_in, STDIN_FILENO) == -1)
			return ;
		close (mi_sys->fd_in);
	}
	if (mi_redis(mi_cmd, OUTPUT) || mi_redis(mi_cmd, APPEND))
	{
		close (mi_cmd->fd[1]);
		mi_cmd->fd[1] = mi_lastred(mi_cmd->red, mi_sys, out);
		dup2(mi_cmd->red->fd, STDOUT_FILENO);
	}
	mi_execonechildexe(mi_cmd, mi_sys);
}

void	mi_execonepipe(t_cmd *mi_cmd, t_sys *mi_sys)
{
	if (mi_cmd->next != NULL)
	{
		if (pipe(mi_cmd->fd) == -1)
		{
			mi_intlogerror (mi_sys, "pipe out failed", 1);
			return ;
		}
	}
	return ;
}

void	mi_execonefork(t_cmd *mi_cmd, t_sys *mi_sys, int *out, int *in)
{
	mi_cmd->id = fork();
	mi_sys->max_id = mi_cmd->id;
	if (mi_cmd->id == -1)
	{
		mi_intlogerror (mi_sys, "fork out failed", 1);
		return ;
	}
	if (mi_cmd->id == 0)
		mi_execonechild(mi_cmd, mi_sys, out, in);
	if (mi_cmd->no != 0)
		close (mi_sys->fd_in);
	if (mi_cmd->next != NULL)
	{
		close (mi_cmd->fd[1]);
		mi_sys->fd_in = mi_cmd->fd[0];
	}
}

void	mi_execone(t_cmd *mi_cmd, t_sys *mi_sys)
{
	int	*out;
	int	*in;

	out = (int []){OUTPUT, APPEND};
	in = (int []){INPUT, HEREDOC};
	if (mi_cmd->full && mi_cmd->full[0] == '\0')
	{
		mi_logerror(2, "erreur de syntaxe : fin de fichier prématurée", mi_sys);
		close (mi_sys->fd_in);
		return ;
	}
	if (mi_sys->nb_pipe == 1 && mi_cmd->builtin == true)
	{
		if (mi_redis(mi_cmd, OUTPUT) || mi_redis(mi_cmd, APPEND))
			mi_execbuiltin(mi_cmd,
				mi_lastred(mi_cmd->red, mi_sys, out), mi_sys);
		else
			mi_execbuiltin(mi_cmd, STDOUT_FILENO, mi_sys);
		return ;
	}
	mi_execonepipe(mi_cmd, mi_sys);
	if (mi_sys->error == NULL && mi_cmd->args)
		mi_execonefork(mi_cmd, mi_sys, out, in);
	return ;
}
