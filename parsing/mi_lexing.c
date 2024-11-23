/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mi_lexing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 17:27:50 by jegirard          #+#    #+#             */
/*   Updated: 2024/11/02 17:27:55 by jegirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	mi_lexingline(char *ln, t_sys *mi_sys)
{
	t_cmd		*new_cmd;
	t_cmd		*mi_cmd;
	char		*msg_error;
	size_t		start;
	size_t		i;

	mi_sys->nb_pipe = 0;
	mi_cmd = mi_createcmd(mi_sys);
	i = 0;
	start = i;
	mi_sys->cmd = mi_cmd;
	while (ft_strlen(ln) >= i && ln[i])
	{
		if (ft_strin(TECHAP, ln[i]))
			mi_pospasscote(ln, &i, mi_sys);
		else if (ln[i] == '|')
		{
			mi_cmd->full = ft_strtrim_param(ln, start, i, WSPACE);
			if (mi_cmd->full == NULL)
			{
				msg_error = join_3("syntax error near ", ln, " unexpected token");
				mi_sys->nb_pipe = 0;
				mi_logerror(2, msg_error, mi_sys);
				free(msg_error);
				mi_freecmd(mi_sys);
				return ;
			}
			new_cmd = mi_createcmd(mi_sys);
			mi_cmd->next = new_cmd;
			mi_cmd = new_cmd;
			start = i + 1;
		}
		i++;
	}
	mi_cmd->full = ft_strtrim_param(ln, start, i -1, WSPACE);
	mi_cmd->next = NULL;
}
