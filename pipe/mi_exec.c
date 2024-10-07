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

void	mi_exec(t_pipe *pipe, t_sys *mi_sys)
{
	if (mi_sys->nb_pipe == 0)
		mi_execone(pipe, mi_sys);
	else
	{
		while(pipe)
		{
			mi_execone(pipe, mi_sys);
			pipe = pipe->next;
		}
	}
}
