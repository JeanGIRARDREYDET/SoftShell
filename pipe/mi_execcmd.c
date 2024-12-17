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
	char	*errormsg;
	int 	i;
	i = 0;
	while (mi_sys->env[i])
	{
		dprintf(2, "mi_execcmd env %s \n",mi_sys->env[i]);
		i++;
	}
	
	i = 0;
	while (mi_cmd->args[i])
	{
		dprintf(2, "mi_execcmd args %s \n",mi_cmd->args[i]);
		i++;
	}
	
	if (mi_cmd->args[0] == NULL )
		return (1);
	if (mi_cmd->builtin == true)
	{
		// les argirmnt doivent se terminer par un null
		mi_execbuiltin(mi_cmd, STDOUT_FILENO, mi_sys);
		mi_freesys(mi_sys);
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
