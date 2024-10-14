/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mi_pipeiter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard <jegirard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 18:38:45 by jegirard          #+#    #+#             */
/*   Updated: 2024/10/14 10:50:17 by jegirard         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../minishell.h"

void	mi_pipeiter(t_pipe *mi_pipe, void (*f)(t_pipe *mi_pipe))
{
	while (mi_pipe != NULL)
	{
		(*f)(mi_pipe);
		mi_pipe = mi_pipe->next;
	}
}

void	mi_syspipeiter(t_sys *mi_sys, void (*f)(t_pipe *mi_pipe, t_sys *mi_sys))
{
	t_pipe	*mi_pipe;

	mi_pipe = mi_sys->pipe;
	while (mi_pipe!= NULL)
	{
		printf("mi_syspipeiter, pipe = %p\n", mi_pipe);
		printf("mi_pipe->full_cmd addr  = %p \n", mi_pipe->full_cmd);
		printf("mi_pipe->full_cmd = %s\n", mi_pipe->full_cmd);

		(*f)(mi_pipe, mi_sys);
		mi_pipe = mi_pipe->next;
	}
}
