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

void	mi_cmdsplitcmd(t_cmd *mi_cmd)
{
	int	x[3];

	x[0] = 0;
	x[1] = 0;
	ft_cnt_arg(mi_cmd->full, &x[0], &x[1]);
	if (x[1] > 0)
	{
		mi_cmd->split = ft_calloc(x[1] + 1, sizeof(char *));
		if (mi_cmd->split == NULL)
			return ;
		x[1] = 0;
		x[0] = 0;
		while (mi_cmd->full[x[0]])
		{
			ft_pos_passspace(mi_cmd->full, &x[0]);
			x[2] = x[0];
			ft_pos_redir(mi_cmd->full, &x[0]);
			if (x[2] == x[0])
				ft_pos_passstring(mi_cmd->full, &x[0]);
			if (x[0] - x[2] < 1)
				continue ;
			mi_cmd->split[x[1]] = ft_substr(mi_cmd->full, x[2], x[0] - x[2]);
			x[1]++;
		}
	}
}
