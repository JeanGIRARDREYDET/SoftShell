/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mi_execcmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doferet <doferet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 11:38:34 by jegirard          #+#    #+#             */
/*   Updated: 2025/01/17 16:36:14 by doferet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	mi_execcmd(t_cmd *mi_cmd, t_sys *mi_sys)
{
	int	error;

	if (mi_cmd->args[0] == NULL)
		return (1);
	if (mi_cmd->builtin == true)
	{
		mi_execbuiltin(mi_cmd, STDOUT_FILENO, mi_sys);
		mi_freesys(mi_sys);
		return (125);
	}
	if (!mi_cmd->found)
		mi_logerror2(127, mi_cmd->args[0], "command not found 28", mi_sys);
	if (!mi_cmd->found || mi_cmd->fd[1] == -1)
	{
		error = mi_sys->error->code_error;
		mi_freesys(mi_sys);
		exit(error);
	}
	else if (execve(mi_cmd->args[0], mi_cmd->args, mi_sys->env) == -1)
	{
		mi_logerror2(123, mi_cmd->args[0], "command not found 37", mi_sys);
		if (access(mi_cmd->args[0], X_OK) != 0) 
       		mi_freecmdsysexit(0, 126, mi_sys);
		mi_freecmdsysexit(0, 127, mi_sys);
	}
	return (122);
}
