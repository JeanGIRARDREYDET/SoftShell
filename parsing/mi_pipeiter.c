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

void	mi_pipeiter(t_pipe *lst, void (*f)(t_pipe *lst))
{
	t_pipe	*i_element;

	i_element = lst;
	while (i_element != NULL)
	{
		(*f)(i_element);
		i_element = i_element->next;
	}
}

void	mi_syspipeiter(t_sys *sys, void (*f)(t_pipe *lst, t_sys *sys))
{
	t_pipe	*mi_pipe;

	mi_pipe = sys->pipe;
	while (mi_pipe)
	{
		(*f)(mi_pipe, sys);
		mi_pipe = mi_pipe->next;
	}
}
