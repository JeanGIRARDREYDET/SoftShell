/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mi_cmdparsse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 18:39:21 by jegirard          #+#    #+#             */
/*   Updated: 2024/10/04 18:39:25 by jegirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	mi_cmdherdoc(t_cmd *mp)
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

void	mi_parseredirtocken(int *i, int *n, t_cmd *mi_cmd, t_sys *mi_sys)
{
	int		j;
	char	capt_redir;

	j = 0;
	capt_redir = mi_cmd->split[*i][0];
	while (capt_redir == mi_cmd->split[*i][j])
		j++ ;
	if (j > 2)
		mi_logerrorlong(2, "syntax error near unexpected token", ft_chrrepeat(capt_redir, j), "", mi_sys);
	else
	{
		*i += 1;
		if (mi_cmd->split[*i])
			mi_creredirection(mi_cmd, mi_sys, (j-1)|(capt_redir&2), mi_cmd->split[*i]);
	}
	(*n)++;
}

void	mi_cmdparsse(t_cmd *mi_cmd, t_sys *mi_sys)
{
	int	i;
	int n ;

	n = 0;
	i = 0;
	if (mi_cmd->full == NULL)
		return ;
	while (mi_cmd->split[i])
	{
		if (mi_cmd->split[i + 1] && (mi_cmd->split[i][0] == '<' || mi_cmd->split[i][0] == '>'))
			mi_parseredirtocken(&i, &n, mi_cmd, mi_sys);
		i++;
	}

	mi_cmd->args = ft_calloc(i-(2*n)+1 , sizeof(char *));
	i=0;
	n=0;
	while (mi_cmd->split[i])
	{
		if (mi_cmd->split[i + 1] && (mi_cmd->split[i][0] == '<' || mi_cmd->split[i][0] == '>'))
			i++;
		else
		{
			mi_cmd->args[n] = ft_strdup(mi_cmd->split[i]);
			n++;
		}
		i++;
	}
}
void	mi_cmdsplitcmd(t_cmd *mi_cmd)
{
	int	i;
	int	s;
	int	n;

	i = 0;

	n = 0;
	ft_cnt_arg(mi_cmd->full, &i, &n);
	if (n > 0)
	{
		mi_cmd->split = ft_calloc(n + 1, sizeof(char *));
		if (mi_cmd->split == NULL)
			return ;
		n = 0;
		i = 0;
		while (mi_cmd->full[i])
		{
			ft_pos_passspace(mi_cmd->full, &i);
//			if (mi_cmd->full[i] == '<' || mi_cmd->full[i] == '>')
//				mi_parseredirtocken(&i, &n, mi_cmd, mi_sys);
			s = i;
			ft_pos_passstring(mi_cmd->full, &i);
			if(i-s<1)
				continue;
			mi_cmd->split[n] = ft_substr(mi_cmd->full, s, i - s);
			ft_subchar(mi_cmd->split[n], '\"');
			n++;
		}
	}
}
