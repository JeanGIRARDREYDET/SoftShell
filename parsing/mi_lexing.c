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

void mi_lexingline(char *ln, int i, t_cmd *mi_cmd, t_sys *mi_sys)
{
	t_cmd	*new_cmd;
	char	*msg_error;
	int		start;

	start = i;
	while (ln[i] && ln[i] != '\0')
	{
		if (ft_strin(TECHAP, ln[i]))
			mi_pospasscote(ln, &i, mi_sys);
		else if (ln[i] == '|')
		{
			new_cmd = mi_createcmd(mi_sys);
			mi_cmd->full_cmd = ft_strtrim_param(ln, start, i, WSPACE);
			if (!mi_cmd->full_cmd)
			{
				msg_error = join_3("syntax error near ", ln, " unexpected token");
				mi_logerror(2, msg_error, mi_sys);
				free(msg_error);
				return;
			}
			mi_cmd->next = new_cmd;
			mi_cmd = new_cmd;
			start = i + 1;
		}
		i++;
	}

	mi_cmd->full_cmd = ft_strtrim_param(ln, start, i, WSPACE);
	mi_cmd->next = NULL;
}
