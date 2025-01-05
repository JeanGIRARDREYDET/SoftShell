/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mi_cmdsplitcmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard  <jegirard@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 11:38:34 by jegirard          #+#    #+#             */
/*   Updated: 2024/12/07 13:24:53 by jegirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"


void	mi_posdif(char *ln, int *s, int *i)
{

	while (ln && ln[*i] && ln[*i] != '\0' && ft_strchr(WSPACE, ln[*i]))
		(*i)++;
	
	*s = *i;
	if (ln && ln[*i] && ln[*i] != '\0' && (ln[*i] != '<' && ln[*i] != '>'))
	{
		while (ln && ln[*i] && ln[*i] != '\0'  && !ft_strchr(WSPACE, ln[*i]) 
		&& (ln[*i] != '<' && ln[*i] != '>'))
			(*i)++;
	}
	else if (ln && ln[*i] && ln[*i] != '\0'  && !ft_strchr(WSPACE, ln[*i]) 
	&& (ln[*i] == '<' || ln[*i] == '>'))
		{
			while (ln && ln[*i] && ln[*i] == ln[*s])
				(*i)++;
		}
}

void	mi_cntarg(char *ln ,int *x)
{
	mi_posdif(ln , &x[0], &x[1]);
	if (ln[x[0]] && x[1] > x[0])
	{
		x[0] = x[1];
		mi_cntarg( ln , x);
		x[2]++;;
	}
}

void	mi_cmdsplitcmd(t_cmd *mi_cmd)
{
	int	x[6];

	x[0] = 0;
	x[1] = 0;
	x[2] = 0;
	mi_cntarg(mi_cmd->full, x);
	if (x[0])
	{
		mi_cmd->split = ft_calloc(x[2] + 1, sizeof(char *));
		if (mi_cmd->split == NULL)
			return ;
		x[0] = 0;
		x[1] = 0;
		x[2] = 0;
		while (mi_cmd->full[x[0]])
		{	x[1] = x[0];
			mi_posdif(mi_cmd->full , &x[0], &x[1]);			
			if ( x[1]<1)
			{
				x[0]++;
				continue;
			}
			if (x[1] > x[0])
			{
				mi_cmd->split[x[2]] = ft_substr(mi_cmd->full, x[0], x[1] - x[0]);
				x[2]++;
			}
			x[0] = x[1];
		}
	}
}
