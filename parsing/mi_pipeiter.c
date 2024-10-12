/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mi_pipeiter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 18:38:45 by jegirard          #+#    #+#             */
/*   Updated: 2024/10/04 18:38:48 by jegirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	mi_pipeiter(t_pipe *mi_pipe, void (*f)(t_pipe *mi_pipe))
{
	while (mi_pipe != NULL)
	{
		(*f)(mi_pipe);
		mi_pipe = mi_pipe->next;
	}
}

void	mi_syspipeiter(t_sys *me_sys, void (*f)(t_pipe *mi_pipe, t_sys *me_sys))
{
	t_pipe	*mi_pipe;

	mi_pipe = me_sys->pipe;
	while (mi_pipe!= NULL)
	{
		(*f)(mi_pipe, me_sys);
		mi_pipe = mi_pipe->next;
	}
}
