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

static void	split_x_reset(int *x)
{
	x[0] = 0;
	x[1] = 0;
	x[2] = 0;
}

static void	split_loop(int *x, t_cmd *mi_cmd)
{
	split_x_reset(x);
	while (mi_cmd->full[x[0]])
	{
		x[1] = x[0];
		mi_posdif(mi_cmd->full, &x[0], &x[1]);
		if (x[1] < 1)
		{
			x[0]++;
			continue ;
		}
		if (x[1] > x[0])
		{
			mi_cmd->split[x[2]] = ft_substr(mi_cmd->full, x[0], x[1] - x[0]);
			x[2]++;
		}
		x[0] = x[1];
	}
}

void	mi_cmdsplitcmd(t_cmd *mi_cmd)
{
	int	x[3];

	split_x_reset(x);
	mi_cntarg(mi_cmd->full, x);
	if (x[0])
	{
		mi_cmd->split = ft_calloc(x[2] + 1, sizeof(char *));
		if (mi_cmd->split == NULL)
			return ;
		split_loop(x, mi_cmd);
	}
}
