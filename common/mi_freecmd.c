/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mi_freecmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doferet <doferet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 11:38:34 by jegirard          #+#    #+#             */
/*   Updated: 2025/01/17 16:07:20 by doferet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	mi_freered(t_cmd *mi_cmd)
{
	t_red	*tmp;

	if (!mi_cmd->red)
		return ;
	while (mi_cmd->red)
	{
		tmp = mi_cmd->red;
		if (tmp->fd && tmp->fd != -1)
			ft_fdclose(tmp->fd);
		if (tmp->redir_type == HEREDOC)
			unlink(tmp->file_name);
		if (tmp->redir_type == HEREDOC)
			free(mi_cmd->red->file_name);
		mi_cmd->red->file_name = NULL;
		mi_cmd->red = tmp->next;
		free(tmp);
	}
}

void	mi_freeonecmd(t_cmd *mi_cmd)
{
	if (!mi_cmd)
		return ;
	if (mi_cmd->args != NULL)
		ft_arrclose(mi_cmd->args);
	mi_cmd->args = NULL;
	if (mi_cmd->full != NULL)
		free(mi_cmd->full);
	mi_cmd->full = NULL;
	if (mi_cmd->split != NULL)
		ft_arrclose(mi_cmd->split);
	mi_cmd->split = NULL;
	if (mi_cmd->red != NULL)
		mi_freered(mi_cmd);
	mi_cmd->red = NULL;
	mi_cmd = NULL;
}

void	mi_freecmd(t_sys *mi_sys)
{
	t_cmd	*mi_cmd;
	t_cmd	*mi_nxcmd;

	if (!mi_sys->cmd)
		return ;
	mi_cmd = mi_sys->cmd;
	while (mi_cmd != NULL)
	{
		mi_cmd = mi_sys->cmd;
		mi_freeonecmd(mi_sys->cmd);
		if (!mi_cmd->next)
			break ;
		mi_nxcmd = mi_cmd->next;
		if (mi_cmd->full)
			free(mi_cmd->full);
		free (mi_cmd);
		mi_sys->cmd = mi_nxcmd;
	}
	free(mi_sys->cmd);
	mi_sys->cmd = NULL;
	mi_sys->nb_error = 0;
	mi_freeerror(mi_sys);
	if (mi_sys->input != NULL)
		free(mi_sys->input);
	g_signal = 0;
}
