/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mi_execonefork.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 17:19:51 by jegirard          #+#    #+#             */
/*   Updated: 2025/01/19 17:20:00 by jegirard         ###   ########.fr       */
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
		if (mi_cmd->fd[0] == -1)
			exit (1);
		ft_fdclose (mi_cmd->fd[0]);
		if (mi_cmd->fd[1] == -1)
			exit (1);
		ft_fdclose (mi_cmd->fd[1]);
	}
	if (mi_cmd->args[0] != NULL)
		mi_execcmd(mi_cmd, mi_sys);
}

void	mi_execonechildnoarg(t_cmd *mi_cmd, t_sys *mi_sys)
{
	dup2(mi_cmd->red->fd, STDOUT_FILENO);
	ft_fdclose (mi_cmd->red->fd);
	mi_freesysexit(mi_sys->exit_status, mi_sys);
}
/*
	if (type == INPUT && sys->error == NULL && !(access(file_name, R_OK) == 0))
	{
		dprintf(2, "minishell: %s: No such file or directory\n", file_name);
		mi_logerror2(1, file_name, "No such file or directory", sys);
		return ;
	}

*/

void	mi_execonechildin(t_cmd *mi_cmd, t_sys *mi_sys)
{
	int	*in;

	in = (int []){INPUT, HEREDOC};
	mi_cmd->fd[0] = mi_lastred(mi_cmd->red, mi_sys, in);
	if (mi_cmd->fd[0] == -1)
		mi_freesysexit(mi_sys->exit_status, mi_sys);
	dup2(mi_cmd->fd[0], STDIN_FILENO);
	ft_fdclose (mi_cmd->fd[0]);
}

void	mi_execonechild(t_cmd *mi_cmd, t_sys *mi_sys, int *out)
{
	//dprintf(2, "  mi_execonechild %s\n", mi_cmd->args[0]);
	g_signal = 1;
	if (!mi_cmd->args[0])
		mi_execonechildnoarg(mi_cmd, mi_sys);

	if (mi_cmd->no != 0)
	{
		if (dup2(mi_sys->fd_in, STDIN_FILENO) == -1)
			return ;
		ft_fdclose (mi_sys->fd_in);
	}
	if (mi_redis(mi_cmd, INPUT) || mi_redis(mi_cmd, HEREDOC))
		mi_execonechildin(mi_cmd, mi_sys);
	
	if (mi_redis(mi_cmd, OUTPUT) || mi_redis(mi_cmd, APPEND))
	{
		if (mi_sys->nb_pipe > 1)
			ft_fdclose (mi_cmd->fd[1]);
		mi_cmd->fd[1] = mi_lastred(mi_cmd->red, mi_sys, out);
		//dprintf(2, "mi_execonechild mi_cmd->fd[1] = %s\n", mi_cmd->type);
		if (mi_cmd->fd[1] == -1)
			mi_freecmdsysexit(mi_cmd->fd[1], 1, mi_sys);
		dup2(mi_cmd->fd[1], STDOUT_FILENO);
		if (mi_sys->nb_pipe <= 1)
			ft_fdclose (mi_cmd->fd[1]);
	}
	mi_execonechildexe(mi_cmd, mi_sys);
}

bool	mi_redistypexist(int type, t_cmd *mi_cmd)
{
	t_red			*mi_red;

	mi_red = mi_cmd->red;
	while (mi_red)
	{
		if (mi_red->redir_type == type && mi_red->file_name)
		{
			if (access(mi_red->file_name, F_OK) != 0)
				return true ;
		}
		else if (!mi_red->next)
			return (false);
		mi_red = mi_red->next;
	}
	return (false);
}

void	mi_execonefork(t_cmd *mi_cmd, t_sys *mi_sys, int *out)
{
	//dprintf(2, "mi_execonefork %s\n", mi_cmd->args[0]);
	mi_cmd->id = fork();
	mi_sys->max_id = mi_cmd->id;
	if (mi_cmd->id == -1)
	{
		mi_intlogerror (mi_sys, "fork out failed", 1);
		return ;
	}
	if (mi_cmd->id == 0)
		mi_execonechild(mi_cmd, mi_sys, out);
	if (mi_cmd->no != 0)
		ft_fdclose (mi_sys->fd_in);
	if (mi_cmd->next != NULL)
	{
		//dprintf(2, " mi_execonefork mi_cmd->next != NULL\n");
		ft_fdclose (mi_cmd->fd[1]);
		mi_sys->fd_in = mi_cmd->fd[0];
	}
	//dprintf(2, "end fork %s\n", mi_cmd->args[0]);
}
