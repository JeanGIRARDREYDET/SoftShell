/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mi_execbuiltin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 13:50:25 by jegirard          #+#    #+#             */
/*   Updated: 2024/11/02 13:50:30 by jegirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	mi_execbuiltin(t_cmd *mi_cmd, t_sys *mi_sys)
{
	char	*cmd;

	cmd = mi_cmd->cmd;
	if (mi_sys->env == NULL)
	{
		dprintf(2, "			mi_exebuiltin env  NULL\n");
	}
	if (ft_findword("cd", cmd))
		builtin_cd(mi_cmd->arg, mi_sys);
	else if (ft_findword("echo", cmd))
		builtin_echo(mi_cmd->arg);
	else if (ft_findword("env", cmd))
		builtin_env(mi_sys);
	else if (ft_findword("exit", cmd))
		builtin_exit();
	else if (ft_findword("export", cmd))
		builtin_export(mi_cmd->arg, mi_sys);
	else if (ft_findword("pwd", cmd))
		builtin_pwd();
	else if (ft_findword("unset", cmd))
		builtin_unset(mi_cmd->arg, mi_sys);
	else
		exit (EXIT_FAILURE);
	if (mi_sys->nb_pipe> 1)
		exit(mi_sys->exit_status);
}
