/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mi_heredoc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 16:37:07 by jegirard          #+#    #+#             */
/*   Updated: 2024/12/03 16:37:13 by jegirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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
