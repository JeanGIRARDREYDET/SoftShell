/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mi_createcmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 19:48:29 by jegirard          #+#    #+#             */
/*   Updated: 2024/10/04 19:48:33 by jegirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_cmd	*mi_createcmd(t_sys *mi_sys)
{
	t_cmd	*mi_cmd;

	mi_cmd = ft_calloc(1, sizeof (t_cmd));
	if (!mi_cmd)
		return (NULL);
	mi_cmd->id = 0;
	mi_cmd->no = mi_sys->nb_pipe++;
	mi_cmd->full = NULL;
	mi_cmd->split = NULL;
	mi_cmd->arg = "";
	mi_cmd->args = NULL;
	mi_cmd->builtin = true;
	mi_cmd->type = NULL;
	mi_cmd->fd[0] = 0;
	mi_cmd->fd[1] = 0;
	mi_cmd->redirection = NULL;
	mi_cmd->next = NULL;
	mi_sys->fd_in = STDIN_FILENO;
	return (mi_cmd);
}

void	mi_creredirection(t_cmd *cmd, t_sys *sys, int type, char *file_name)
{
	t_redirection	*mi_redirection;

	if (!file_name)
	{
		mi_logerror(2, "syntax error near unexpected token", sys);
		return ;
	}
	mi_redirection = ft_calloc(1, sizeof (t_redirection));
	if (!mi_redirection)
		return ;
	mi_redirection->redir_type = type;
	mi_redirection->fd = 0;
	mi_redirection->file_name = file_name;
	mi_redirection->next = NULL;
	if (cmd->redirection == NULL)
		cmd->redirection = mi_redirection;
	else
	{
		while (cmd->redirection->next)
			cmd->redirection = cmd->redirection->next;
		cmd->redirection->next = mi_redirection;
	}
	return ;
}
