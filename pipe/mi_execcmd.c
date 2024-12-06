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
	char	*errormsg;

	if (mi_cmd->args[0] == NULL )
		return (1);
	if (mi_cmd->builtin == true)
	{
		mi_execbuiltin(mi_cmd, STDOUT_FILENO, mi_sys);
		return (127);
	}
	if (!mi_cmd->found)
	{
		errormsg = ft_strjoin(mi_cmd->args[0], ": command not found");
		mi_logerror(127, errormsg, mi_sys);
		free(errormsg);
		mi_freesys(mi_sys);
		exit(127);
		return (127);
	}
	else if (execve(mi_cmd->args[0], mi_cmd->args, mi_sys->env) == -1)
	{
		mi_logerror(126, "Command found but in error ", mi_sys);
		return (126);
	}
	return (127);
}
