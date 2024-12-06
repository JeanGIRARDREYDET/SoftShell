/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mi_syscmditer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:55:03 by jegirard          #+#    #+#             */
/*   Updated: 2024/12/06 17:55:26 by jegirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	mi_syscmditer(t_sys *mi_sys, void (*f)(t_cmd *mi_cmd, t_sys *mi_sys))
{
	t_cmd	*mi_cmd;

	if (mi_sys->nb_error > 0)
		return ;
	mi_cmd = mi_sys->cmd;
	while (mi_cmd != NULL)
	{
		(*f)(mi_cmd, mi_sys);
		mi_cmd = mi_cmd->next;
	}
}
