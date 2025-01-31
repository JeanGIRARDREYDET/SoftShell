/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mi_lexing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard  <jegirard@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 11:38:34 by jegirard          #+#    #+#             */
/*   Updated: 2024/12/07 13:24:53 by jegirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

bool	mi_lexinglincheckerr( t_cmd *mi_cmd, t_sys *mi_sys)
{
	if (mi_cmd->full == NULL)
	{
		mi_sys->nb_pipe = 0;
		mi_logerror(2, "syntax error near unexpected token `|'", mi_sys);
		return (true);
	}
	return (false);
}

void	mi_lexingline( t_sys *mi_sys)
{
	t_cmd		*mi_cmd;
	size_t		i[2];

	mi_sys->nb_pipe = 0;
	mi_cmd = mi_createcmd(mi_sys);
	ft_bzero(i, sizeof(size_t) * 2);
	mi_sys->cmd = mi_cmd;
	while (ft_strlen(mi_sys->input) >= i[1] && mi_sys->input[i[1]])
	{
		if (ft_strin(TECHAP, mi_sys->input[i[1]]))
			mi_pospasscote(mi_sys->input, &i[1], mi_sys);
		else if (mi_sys->input[i[1]] == '|')
		{
			mi_cmd->full = ft_strtrimparam(mi_sys->input, i[0], i[1], WSPACE);
			if (mi_lexinglincheckerr(mi_cmd, mi_sys))
				return ;
			mi_cmd->next = mi_createcmd(mi_sys);
			mi_cmd = mi_cmd->next;
			i[0] = i[1] + 1;
		}
		i[1]++;
	}
	mi_cmd->full = ft_strtrimparam(mi_sys->input, i[0], i[1], WSPACE);
	mi_cmd->next = NULL;
}
