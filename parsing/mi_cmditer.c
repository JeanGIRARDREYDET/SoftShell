/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mi_cmditer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard <jegirard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 18:38:45 by jegirard          #+#    #+#             */
/*   Updated: 2024/10/14 10:50:17 by jegirard         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../minishell.h"

void	mi_cmditer(t_cmd *mi_cmd, void (*f)(t_cmd *mi_cmd))
{
	while (mi_cmd != NULL)
	{
		(*f)(mi_cmd);
		mi_cmd = mi_cmd->next;
	}
}

void	mi_syscmditer(t_sys *mi_sys, void (*f)(t_cmd *mi_cmd, t_sys *mi_sys))
{
	t_cmd	*mi_cmd;

	dprintf(2, "mi_syscmditer\n");
	mi_cmd = mi_sys->cmd;
	while (mi_cmd != NULL)
	{
		dprintf(2, "	syscmditer\n");
		(*f)(mi_cmd, mi_sys);
		mi_cmd = mi_cmd->next;
	}
	dprintf(2, "/mi_syscmditer\n");
}
