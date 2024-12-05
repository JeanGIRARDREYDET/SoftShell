/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mi_freecmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 11:40:01 by jegirard          #+#    #+#             */
/*   Updated: 2024/10/08 11:40:05 by jegirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	mi_freered(t_cmd *mi_cmd)
{
	t_red	*tmp;

	if (!mi_cmd->red)
		return ;
	while (mi_cmd->red && mi_cmd->red != NULL)
	{
		tmp = mi_cmd->red->next;
		if (mi_cmd->red->fd)
			close(mi_cmd->red->fd);
		if (mi_cmd->red->redir_type == HEREDOC)
			unlink(mi_cmd->red->file_name);
		if (mi_cmd->red->file_name)
			free(mi_cmd->red->file_name);
		free(mi_cmd->red);
		mi_cmd->red = tmp;
	}
	mi_cmd->red = NULL;
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
	if (mi_cmd != NULL)
		free(mi_cmd);
	mi_cmd = NULL;
}

void	mi_freecmd(t_sys *mi_sys)
{
	t_cmd	*tmp;

	if (!mi_sys->cmd)
		return ;
	while (mi_sys->cmd && mi_sys->cmd != NULL)
	{	
		tmp = mi_sys->cmd->next;
		mi_freeonecmd(mi_sys->cmd);
		mi_sys->cmd = tmp;
	}
	mi_sys->cmd = NULL;
	mi_sys->nb_error = 0;
	mi_freeerror(mi_sys);
}
