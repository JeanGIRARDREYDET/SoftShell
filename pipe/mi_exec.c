/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mi_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 19:48:48 by jegirard          #+#    #+#             */
/*   Updated: 2024/10/04 19:48:51 by jegirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
 
void	mi_exec(t_cmd *mi_cmd, t_sys *mi_sys)
{
	if (mi_sys->nb_pipe == 0)
		mi_execone(mi_cmd, mi_sys);
	else
	{
		while (mi_cmd)
		{
			printf("debut mi_exec %s\n", mi_cmd->cmd);
//			if (!mi_cmd->next && pipe(mi_cmd->fdd) == -1)
//				mi_logerror(126, "pipe", &mi_cmd->error);
			mi_execone(mi_cmd, mi_sys);
			mi_cmd = mi_cmd->next;
			printf("fin mi_exec\n");
		}
		mi_waitingpipe (mi_sys);
	}
}
