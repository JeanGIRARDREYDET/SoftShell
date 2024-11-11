/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mi_execcmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 12:07:44 by jegirard          #+#    #+#             */
/*   Updated: 2024/07/24 12:07:48 by jegirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

//	dprintf(2, "	mi_execcmd ('%s') \n", mi_cmd->cmd);

int	mi_execcmd(t_cmd *mi_cmd, t_sys *mi_sys)
{
	if (mi_cmd->cmd == NULL && mi_cmd->cmd == NULL )
		return (1);
	if (mi_sys->error)
		exit(0);
	if (mi_cmd->builtin == true)
	{
		mi_execbuiltin(mi_cmd, mi_sys);
		return (1);
	}
	else if (execve(mi_cmd->cmd, mi_cmd->split_cmd, mi_sys->env) == -1)
	{
		mi_logerror(126, "Command found but in error ", mi_sys);
		return (errno);
	}
	mi_logerror(127, "command not found ", mi_sys);
	return (errno);
}
