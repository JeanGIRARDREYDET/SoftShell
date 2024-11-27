/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mi_lastredirection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 11:23:07 by jegirard          #+#    #+#             */
/*   Updated: 2024/11/26 11:23:13 by jegirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int mi_lastredirection(t_redirection *mi_re,t_sys *mi_sys)
{
	t_redirection	*mi_return;

	mi_return = NULL;
	if (mi_re == NULL)
		return (-1);
	while (mi_re->next)
	{
		if (mi_re->redir_type != HEREDOC)
		{	
			mi_set_io_files(mi_re, mi_sys);
			close(mi_re->fd);
			mi_return = mi_re;
		}
			
		mi_re = mi_re->next;
	}
	if ( mi_re->redir_type != HEREDOC)
		mi_return = mi_re;
	mi_set_io_files(mi_return, mi_sys);
	return (mi_return->fd);
}
