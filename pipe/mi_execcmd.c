/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mi_execcmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard  <jegirard@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 11:38:34 by jegirard          #+#    #+#             */
/*   Updated: 2024/12/07 13:24:53 by jegirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	mi_execcmd(t_cmd *mi_cmd, t_sys *mi_sys)
{
	int	error;

	signal(SIGINT, SIG_DFL);
	if (mi_cmd->args[0] == NULL)
		return (1);
	if (mi_cmd->builtin == true)
	{
		mi_execbuiltin(mi_cmd, STDOUT_FILENO, mi_sys);
		mi_freesys(mi_sys);
		return (127);
	}
	if (!mi_cmd->found)
		mi_logerror2(127, mi_cmd->args[0], ": command not found", mi_sys);
	if (!mi_cmd->found || mi_cmd->fd[1] == -1)
	{
		error = mi_sys->error->code_error;
		mi_freesys(mi_sys);
		exit(error);
	}
	else if (execve(mi_cmd->args[0], mi_cmd->args, mi_sys->env) == -1)
	{
		mi_logerror(126, "Command found but in error ", mi_sys);
		return (126);
	}
	return (127);
}
