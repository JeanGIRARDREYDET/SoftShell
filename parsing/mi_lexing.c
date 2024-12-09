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

bool	mi_lexinglincheckerr(char *ln, t_cmd *mi_cmd, t_sys *mi_sys)
{
	char		*msg_err;

	if (mi_cmd->full == NULL)
	{
		msg_err = join_3("syntax error near ", ln, " unexpected token");
		mi_sys->nb_pipe = 0;
		mi_logerror(2, msg_err, mi_sys);
		free(msg_err);
		mi_freecmd(mi_sys);
		return (true);
	}
	return (false);
}

void	mi_lexingline(char *ln, t_sys *mi_sys)
{
	t_cmd		*mi_cmd;
	size_t		i[2];

	mi_sys->nb_pipe = 0;
	mi_cmd = mi_createcmd(mi_sys);
	i[1] = 0;
	i[0] = 0;
	mi_sys->cmd = mi_cmd;
	while (ft_strlen(ln) >= i[1] && ln[i[1]])
	{
		if (ft_strin(TECHAP, ln[i[1]]))
			mi_pospasscote(ln, &i[1], mi_sys);
		else if (ln[i[1]] == '|')
		{
			mi_cmd->full = ft_strtrimparam(ln, i[0], i[1], WSPACE);
			if (mi_lexinglincheckerr(ln, mi_cmd, mi_sys))
				return ;
			mi_cmd->next = mi_createcmd(mi_sys);
			mi_cmd = mi_cmd->next;
			i[0] = i[1] + 1;
		}
		i[1]++;
	}
	mi_cmd->full = ft_strtrimparam(ln, i[0], i[1], WSPACE);
	mi_cmd->next = NULL;
}
