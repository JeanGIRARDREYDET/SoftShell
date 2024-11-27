/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mi_parseredirtocke.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 10:09:36 by jegirard          #+#    #+#             */
/*   Updated: 2024/11/24 10:09:41 by jegirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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
			mi_crered(mi_cmd, mi_sys, (j-1)|(capt_redir&2), mi_cmd->split[*i]);
	}
	(*n)++;
}
