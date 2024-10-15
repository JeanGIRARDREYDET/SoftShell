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
	printf("on cree un pipe ici : %p\n", mi_cmd);
	mi_cmd->id = 0;
	mi_cmd->no = ++mi_sys->nb_pipe;
	mi_cmd->full_cmd = NULL;
	mi_cmd->cmd = NULL;
	mi_cmd->arg = "";
	mi_cmd->args = NULL;
	mi_cmd->builtin = true;
	mi_cmd->error.msg = "";
	mi_cmd->error.code_error = 0;
	mi_cmd->type = NULL;
	mi_cmd->fdd[0] = 0;
	mi_cmd->fdd[1] = 0;
	mi_cmd->redirection = NULL;
	mi_cmd->next = NULL;
	return (mi_cmd);
}

t_redirection	*mi_createredirection(int redir_type)
{
	t_redirection	*mi_redirection;

	mi_redirection = ft_calloc(1, sizeof (t_redirection));
	if (!mi_redirection)
		return (NULL);
	mi_redirection->redir_type = redir_type;
	mi_redirection->fd_here_doc = 0;
	mi_redirection->file_name = NULL;
	mi_redirection->next = NULL;
	return (mi_redirection);
}
