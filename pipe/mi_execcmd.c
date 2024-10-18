/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mi_execcmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 12:07:44 by jegirard          #+#    #+#             */
/*   Updated: 2024/07/24 12:07:48 by jegirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	mi_execcmd(t_cmd *mi_cmd, t_sys *mi_sys)
{
//	dprintf(2, "	mi_execcmd ('%s') \n", mi_cmd->cmd);
	if (mi_cmd->cmd == NULL)
		return (1);

//	dprintf(2, "		cmd exist\n");
	if (execve(mi_cmd->cmd, mi_cmd->split_cmd, mi_sys->env) == -1)
	{
//		dprintf(2, "		cmd error\n");
		perror(ft_strjoin("Command :", mi_cmd->cmd));
		mi_logerror(126, "Command found but in error ", &mi_cmd->error);
		return (errno);
	}
//	dprintf(2, "		cmd ret1./m\n");
	return (1);
}
