/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mi_cmdsplitcmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 10:33:58 by jegirard          #+#    #+#             */
/*   Updated: 2024/11/24 10:34:03 by jegirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	mi_cmdsplitcmd(t_cmd *mi_cmd)
{
	int	i;
	int	s;
	int	n;

	i = 0;
	n = 0;
	ft_cnt_arg(mi_cmd->full, &i, &n);
	if (n > 0)
	{
		mi_cmd->split = ft_calloc(n + 1, sizeof(char *));
		if (mi_cmd->split == NULL)
			return ;
		n = 0;
		i = 0;
		while (mi_cmd->full[i])
		{
			ft_pos_passspace(mi_cmd->full, &i);
			s = i;
			ft_pos_passstring(mi_cmd->full, &i);
			if (i-s<1)
				continue ;
			mi_cmd->split[n] = ft_substr(mi_cmd->full, s, i - s);
			ft_subchar(mi_cmd->split[n], '\"');
			n++;
		}
	}
}
