/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mi_createpipe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 19:48:29 by jegirard          #+#    #+#             */
/*   Updated: 2024/10/04 19:48:33 by jegirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_cmd	*mi_createpipe(t_sys *mi_sys)
{
	t_cmd	*pipe;

	pipe = ft_calloc(1, sizeof (t_cmd));
	if (!pipe)
		return (NULL);
	printf("on cree un pipe ici : %p\n", pipe);
	pipe->id = 0;
	pipe->no = ++mi_sys->nb_pipe;
	pipe->full_cmd = NULL;
	pipe->cmd = NULL;
	pipe->arg = "";
	pipe->args = NULL;
	pipe->builtin = true;
	pipe->error.msg = "";
	pipe->error.code_error = 0;
	pipe->type = NULL;
	pipe->fdd[0] = 0;
	pipe->fdd[1] = 0;
	pipe->redirection = NULL;
	pipe->next = NULL;
	return (pipe);
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

