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

void	mi_execonechild(t_cmd *mi_cmd, t_sys *mi_sys, int *out, int *in)
{
	if (!mi_cmd->args[0])
		return ;
	if (mi_redis(mi_cmd, INPUT) || mi_redis(mi_cmd, HEREDOC))
	{
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
	dprintf(2, "mi_cmd->args[0] = %s\n", mi_cmd->args[0]);
	mi_execonechildexe(mi_cmd, mi_sys);
}

void	mi_execoneerr(t_cmd *mi_cmd, t_sys *mi_sys)
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

void	mi_execoneerrandfork(t_cmd *mi_cmd, t_sys *mi_sys, int *out, int *in)
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
	if (mi_cmd->full)
		free(mi_cmd->full);
	mi_cmd->full = NULL;
	if (mi_sys->nb_pipe == 1 && (mi_cmd->builtin || mi_cmd->args[0] == NULL))
	{
		if (mi_redis(mi_cmd, OUTPUT) || mi_redis(mi_cmd, APPEND))
			mi_execbuiltin(mi_cmd,
				mi_lastred(mi_cmd->red, mi_sys, out), mi_sys);
		else
			mi_execbuiltin(mi_cmd, STDOUT_FILENO, mi_sys);
		return ;
	}
	mi_execoneerr(mi_cmd, mi_sys);
	if (mi_sys->error == NULL)
		mi_execoneerrandfork(mi_cmd, mi_sys, out, in);
	return ;
}
