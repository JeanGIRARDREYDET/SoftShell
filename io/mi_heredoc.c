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
			printf("warning: here-document delimited by end-of-file (wanted `%s')\n", mi_red->eof);
			break ;
		}
		if (ft_findword(mi_red->eof, line))
			break ;
		if (ft_strlen(line) > 0)
			mi_expand(&line, 0, mi_sys);
		if (g_signal == SIGINT)
			return (free(bash), free(line));
		write(mi_red->fd, line, ft_strlen(line));
		write(mi_red->fd, "\n", 1);
	}
	free(bash);
	return (free(line), ft_fdclose (mi_red->fd), mi_sys->nb_herdoc++, (void) NULL);
}
