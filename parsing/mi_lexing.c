/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mi_lexingline.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 18:36:52 by jegirard          #+#    #+#             */
/*   Updated: 2024/10/04 18:36:56 by jegirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	mi_lexingline(char *ln, int i, t_pipe *cmd_pipe, t_sys *mi_sys)
{	
	t_pipe		*new_pipe;
	// const char *redir_token[] = {"<", ">", ">>", "<<", NULL};

	if (ft_strin(TECHAP, ln[i]))
	{
		i = mi_pospasscote(ln, i, &cmd_pipe->error);
		mi_lexingline (ln, ++i, cmd_pipe, mi_sys);
	}
	else if (ln[i] == '\0')
	{
		cmd_pipe->full_cmd = ft_strtrim_param(ln, 0, i, WSPACE);
		cmd_pipe->next = NULL;
		return ;
	}
	else if (ln[i] == '|')
	{
		new_pipe = mi_createpipe(mi_sys);
		cmd_pipe->full_cmd = ft_strtrim_param(ln, 0, i -1, WSPACE);
		cmd_pipe->next = new_pipe;
		mi_lexingline (ln + (++i), 0, new_pipe, mi_sys);
	}
	else
		mi_lexingline (ln, ++i, cmd_pipe, mi_sys);
}
