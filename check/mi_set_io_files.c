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
		mi_logerror(((2 & mi_re->fd)>>1), "errormsg", mi_sys);
		close(mi_re->fd);
	}
	return ;
}

void	mi_heredoc(t_red *mi_red, t_sys *mi_sys)
{	
	char		*line;
	char		*bash;

	bash = ft_strjoin(mi_red->eof, ":>");
	mi_red->fd = open(mi_red->file_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	while (1)
	{
		line = readline(bash);
		if (ft_findword(mi_red->eof, line))
			break ;
		write(mi_red->fd, line, ft_strlen(line));
		write(mi_red->fd, "\n", 1);
	}
	free (bash);
	free (line);
	close (mi_red->fd);
	mi_sys->nb_herdoc++;
}
