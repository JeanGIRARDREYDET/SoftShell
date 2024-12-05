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
	mi_cmd->builtin = false;
	mi_cmd->type = NULL;
	mi_cmd->fd[0] = 0;
	mi_cmd->fd[1] = 0;
	mi_cmd->red = NULL;
	mi_cmd->next = NULL;
	mi_sys->fd_in = STDIN_FILENO;
	return (mi_cmd);
}

static int	fname(char *file, long n, int len, long lb)
{
	if (n >= lb)
		len = (fname(file, n / lb, len, lb));
	if (file[len + 24])
		file[len + 24] = *(&B64[n % lb]);
	return (++len);
}

void	mi_creredfilename(t_red *mi_re, int type, char *file_name)
{
	uintptr_t			addresse;

	if (type == HEREDOC)
	{
		mi_re->eof = file_name;
		addresse = (uintptr_t)mi_re;
		mi_re->file_name = ft_strdup(HERDOCTEMPLATE);
		fname(mi_re->file_name, addresse, 0, 64);
	}
	else
		mi_re->file_name = file_name;
}

void	mi_crered(t_cmd *cmd, t_sys *sys, int type, char *file_name)
{
	t_red	*mi_red;
	t_red	*li_red;

	if (!file_name)
	{
		mi_logerror(2, "syntax error near unexpected token", sys);
		return ;
	}
	li_red = cmd->red;
	mi_red = ft_calloc(1, sizeof (t_red));
	if (!mi_red)
		return ;
	mi_red->redir_type = type;
	mi_red->fd = 0;
	mi_creredfilename(mi_red, type, file_name);
	mi_red->next = NULL;
	if (cmd->red == NULL)
		cmd->red = mi_red;
	else
	{
		while (li_red->next)
			li_red = li_red->next;
		li_red->next = mi_red;
	}
	return ;
}
