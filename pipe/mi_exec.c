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



void	mi_exec(t_pipe *mi_pipe, t_sys *mi_sys)
{
	if (mi_sys->nb_pipe == 0)
		mi_execone(mi_pipe, mi_sys);
	else
	{
		while (mi_pipe)
		{
			if (pipe(mi_pipe->fdd[1]) == -1)
				mi_logerror(126, "pipe", &mi_pipe->error);
			mi_execone(mi_pipe, mi_sys);
			mi_pipe = mi_pipe->next;
		}
	}
}
