/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mi_set_io_files.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 21:47:30 by jegirard          #+#    #+#             */
/*   Updated: 2024/08/03 21:47:33 by jegirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	mi_set_io_files(t_redirection *mi_re, t_sys *mi_sys)
{
	if (mi_re == NULL)
		return ;
	if (mi_re->redir_type == INPUT)
		mi_re->fd = open(mi_re->file_name, O_RDONLY);
	else if (mi_re->redir_type == OUTPUT)
		mi_re->fd = open(mi_re->file_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (mi_re->redir_type == APPEND)
		mi_re->fd = open(mi_re->file_name, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (mi_re->fd == -1 && mi_re->redir_type != HEREDOC)
	{
		mi_logerror(((2 & mi_re->fd)>>1), "errormsg", mi_sys);
		close(mi_re->fd);
	}
	return ;
}
