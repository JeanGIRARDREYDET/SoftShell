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
			mp->args[0] = NULL;
			mp->args[1] = NULL;
		}
 		mp->args++;
	}
}

void	mi_pipeparsse(t_pipe *mi_pipe)
{	int i;
	if (mi_pipe->full_cmd == NULL)
		return ;
	i = ft_pos_left_chars(mi_pipe->full_cmd, WSPACE);
	if (mi_pipe->full_cmd[i] =='\0')
		mi_pipe->arg = NULL;
	else
		mi_pipe->arg = ft_post_left_sep(mi_pipe->full_cmd, WSPACE);
	mi_pipe->cmd = ft_left_sep(mi_pipe->full_cmd, WSPACE);
}

char	*ft_chrrepeat(char c, int n)
{
	char	*str;
	int		i;

	i = 0;
	str = ft_calloc (n + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	while (i < n)
	{
		str[i] = c;
		i++;
	}
	str[i] = '\0';
	return (str);
}

void mi_parseredirtocken(t_pipe *mi_pipe, int *i, int *n)
{
	int		j;
	char	capt_redir;

	j = 0;
	capt_redir = mi_pipe->full_cmd[*i];
	while (capt_redir == mi_pipe->full_cmd[*i + j])
		j++ ;
	if (j > 2 || mi_pipe->full_cmd[*i+j] == '\0' || mi_pipe->full_cmd[*i+j] == '<' || mi_pipe->full_cmd[*i+j] == '>')
		mi_logerrorlong(2, "syntax error near unexpected token", ft_chrrepeat(capt_redir, j), "", &mi_pipe->error);
	else
	{
		mi_pipe->split_cmd[*n] = ft_chrrepeat(capt_redir, j);
	}
	(*n)++;
	*i += j;
	ft_pos_passspace(mi_pipe->full_cmd, i);
}

void	mi_pipesplitcmd(t_pipe *mi_pipe)
{
	int	i;
	int	s;
	int	n;

	i = 0;
	n = 0;
	ft_cnt_arg(mi_pipe->full_cmd, &i, &n);
	if (n > 0)
	{
		mi_pipe->split_cmd = ft_calloc(n + 1 , sizeof (char *));
		if (mi_pipe->split_cmd == NULL)
			return ;
		n = 0;
		i = 0;
		while (mi_pipe->full_cmd[i])
		{
			ft_pos_passspace(mi_pipe->full_cmd, &i);
			if( mi_pipe->full_cmd[i] == '<' || mi_pipe->full_cmd[i] == '>')
				mi_parseredirtocken (mi_pipe, &i, &n);
			s = i;
			ft_pos_passstring(mi_pipe->full_cmd, &i);
			mi_pipe->split_cmd[n] = ft_substr(mi_pipe->full_cmd, s, i -s);
			n++;
		}
	}
}
