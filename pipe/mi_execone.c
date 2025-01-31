/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mi_execone.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard  <jegirard@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 11:38:34 by jegirard          #+#    #+#             */
/*   Updated: 2024/12/07 13:24:53 by jegirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	mi_execonepipe(t_cmd *mi_cmd, t_sys *mi_sys)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGINT, signal_handle_sigint_cat);
	signal(SIGQUIT, signal_handle_sigquit);
	if (mi_cmd->next != NULL)
	{
		if (pipe(mi_cmd->fd) == -1)
		{
			mi_intlogerror (mi_sys, "pipe out failed", 1);
			return ;
		}
	}
	return ;
}

void	mi_execone(t_cmd *mi_cmd, t_sys *mi_sys)
{
	int	*out;

	out = (int []){OUTPUT, APPEND};
	if (mi_cmd->args && *mi_cmd->args == 0)
		mi_cmd->builtin = true;
	if (mi_cmd->full && mi_cmd->full[0] == '\0')
	{
		mi_logerror(2, "erreur de syntaxe : fin de fichier prématurée", mi_sys);
		ft_fdclose (mi_sys->fd_in);
		return ;
	}
	if (mi_sys->nb_pipe == 1 && (mi_cmd->builtin == true))
	{
		if (mi_redis(mi_cmd, OUTPUT) || mi_redis(mi_cmd, APPEND))
			mi_execbuiltin(mi_cmd,
				mi_lastred(mi_cmd->red, mi_cmd, mi_sys, out), mi_sys);
		else
			mi_execbuiltin(mi_cmd, STDOUT_FILENO, mi_sys);
		return ;
	}
	mi_execonepipe(mi_cmd, mi_sys);
	if (mi_sys->error == NULL)
		mi_execonefork(mi_cmd, mi_sys, out);
	return ;
}
