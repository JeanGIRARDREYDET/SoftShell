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

