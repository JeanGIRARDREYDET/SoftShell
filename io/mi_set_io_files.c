/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mi_set_io_files.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doferet <doferet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 19:44:12 by jegirard          #+#    #+#             */
/*   Updated: 2025/01/17 16:21:12 by doferet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	mi_set_io_files(t_red *mi_re, t_sys *mi_sys)
{
	
	if (mi_re == NULL)
		return ;
	if (mi_re->redir_type == INPUT)
		mi_re->fd = open(mi_re->file_name, O_RDONLY);
	else if (mi_re->redir_type == OUTPUT)
		mi_re->fd = open(mi_re->file_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (mi_re->redir_type == APPEND)
		mi_re->fd = open(mi_re->file_name, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else if (mi_re->redir_type == HEREDOC)
		mi_re->fd = open(mi_re->file_name, O_RDONLY);
	if (mi_re->fd == -1)
	{
		mi_logerror2(1, mi_re->file_name, strerror(errno), mi_sys);
		close(mi_re->fd);
	}
	//dup2(mi_re->fd, STDOUT_FILENO);
	return ;
}
