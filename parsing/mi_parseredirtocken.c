/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mi_parseredirtocken.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard  <jegirard@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 11:38:34 by jegirard          #+#    #+#             */
/*   Updated: 2024/12/07 13:24:53 by jegirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	mi_parseredirtocken(int *i, int *n, t_cmd *mi_cmd, t_sys *mi_sys)
{
	int		j;
	char	redir;
	char	*msg_error;
	char	*str;

	j = 0;
	redir = mi_cmd->split[*i][0];
	while (redir == mi_cmd->split[*i][j])
		j++ ;
	if (j > 2)
	{
		str = ft_chrrepeat (redir, j);
		msg_error = ft_strjoin("syntax error near unexpected token", str);
		free(str);
		mi_logerror(2, msg_error, mi_sys);
		free(msg_error);
	}
	else
	{
		*i += 1;
		if (mi_cmd->split[*i])
			mi_crered(mi_cmd, mi_sys, (j - 1) | (redir & 2), mi_cmd->split[*i]);
	}
	(*n)++;
}
