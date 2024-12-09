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

void	mi_lexinglineerr(char *ln, t_sys *mi_sys)

{
	char		*msg_err;

	msg_err = join_3("syntax error near ", ln, " unexpected token");
	mi_sys->nb_pipe = 0;
	mi_logerror(2, msg_err, mi_sys);
	free(msg_err);
	mi_freecmd(mi_sys);
}
void	mi_lexingline(char *ln, t_sys *mi_sys)
{
	t_cmd		*mi_cmd;
	t_cmd		*new_cmd;

	size_t		start;
	size_t		i;

	mi_sys->nb_pipe = 0;
	mi_cmd = mi_createcmd(mi_sys);
	i = 0;
	start = 0;
	mi_sys->cmd = mi_cmd;
	while (ft_strlen(ln) >= i && ln[i])
	{
		if (ft_strin(TECHAP, ln[i]))
			mi_pospasscote(ln, &i, mi_sys);
		else if (ln[i] == '|')
		{
			mi_cmd->full = ft_strtrimparam(ln, start, i, WSPACE);
			if (mi_cmd->full == NULL)
			{
				mi_lexinglineerr(ln, mi_sys);
				return ;
			}
			new_cmd = mi_createcmd(mi_sys);
			mi_cmd->next = new_cmd;
			mi_cmd = new_cmd;
			start = i + 1;
		}
		i++;
	}
	mi_cmd->full = ft_strtrimparam(ln, start, i, WSPACE);
	mi_cmd->next = NULL;
}
