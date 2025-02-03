/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mi_heredoc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doferet <doferet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 09:43:56 by jegirard          #+#    #+#             */
/*   Updated: 2025/01/17 16:00:56 by doferet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	verif_signal(void)
{
	signal(SIGINT, signal_in_heredoc);
	signal(SIGQUIT, SIG_IGN);
	rl_event_hook = sigint_heredoc;
}

void	mi_heredocsignalbarke(t_sys *mi_sys)
{
	write(2, "warning: here-document delimited by end-of-file (wanted `", 57);
	write(2, mi_sys->cmd->red->eof, ft_strlen(mi_sys->cmd->red->eof));
	write(2, "')\n", 3);
}

void	mi_heredocwrite(t_red *mi_red, char *line, t_sys *mi_sys)
{
	int	len;

	len = ft_strlen(line);
	if (len > 0)
	{
		mi_expand(&line, 0, mi_sys);
		if (write(mi_red->fd, line, ft_strlen(line)))
			return ;
	}
	if (write(mi_red->fd, "\n", 1))
		return ;
}

void	mi_heredoc(t_red *mi_red, t_sys *mi_sys)
{
	char		*line;
	char		*bash;

	verif_signal();
	bash = ft_strjoin(mi_red->eof, ":>");
	mi_red->fd = open(mi_red->file_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	while (1)
	{
		line = readline(bash);
		if (!line)
		{
			mi_heredocsignalbarke(mi_sys);
			break ;
		}
		if (ft_findword(mi_red->eof, line))
			break ;
		mi_heredocwrite(mi_red, line, mi_sys);
		if (g_signal == SIGINT)
			return (free(bash), free(line), mi_logerror(130, NULL, mi_sys));
	}
	ft_fdclose (mi_red->fd);
	return (free(line), free(bash), mi_sys->nb_herdoc++, (void) NULL);
}

void	mi_createdoc(t_red *mi_red, t_sys *mi_sys)
{
	int			i;

	if (mi_sys->error == NULL && mi_red)
	{
		i = open(mi_red->file_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		ft_fdclose (i);
	}
	return ;
}
