/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mi_pipe_parsse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 18:39:21 by jegirard          #+#    #+#             */
/*   Updated: 2024/10/04 18:39:25 by jegirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	mi_pipeherdoc(t_pipe *mp)
{
	while (*mp->args)
	{
		if (*mp->args && *mp->args[0] == '<' && *mp->args[1] == '<')
		{
			mp->here_doc = true;	
			mp->heredoc = ft_strdup(mp->args[1]);
			mp->args[0] = NULL;
			mp->args[1] = NULL;
		}
 		mp->args++;
	}
}

void	mi_pipeparsse(t_pipe *pipe)
{
	pipe->arg = ft_post_left_sep(pipe->full_cmd, WSPACE);
	pipe->cmd = ft_left_sep(pipe->full_cmd, WSPACE);
}

void	mi_pipeargparsse(t_pipe *mi_pipe)
{
	int	i;
	int	s;
	int	n;

	i = 0;
	n = 0;
	ft_cnt_arg(mi_pipe->full_cmd, &i, &n);
	if (n > 0)
	{
		mi_pipe->args = ft_calloc(n + 1, sizeof (char *));
		if (mi_pipe->args == NULL)
			return ;
		n = 0;
		i = 0;
		while (mi_pipe->full_cmd[i])
		{
			ft_pos_passspace(mi_pipe->full_cmd, &i);
			s = i;
			ft_pos_passstring(mi_pipe->full_cmd, &i);
			mi_pipe->args[n] = ft_substr(mi_pipe->full_cmd, s, i -s);
			n++;
		}
	}
}
