/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mi_execonechildout.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 13:08:43 by jegirard          #+#    #+#             */
/*   Updated: 2025/01/30 13:08:47 by jegirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	mi_execonechildout(t_cmd *mi_cmd, t_sys *mi_sys, int *out)
{
	if (mi_sys->nb_pipe > 1)
		ft_fdclose (mi_cmd->fd[1]);
	if (mi_sys->nb_pipe >= 1 && mi_cmd->next != NULL)
		ft_fdclose (mi_cmd->fd[0]);
	mi_cmd->fd[1] = mi_lastred(mi_cmd->red, mi_cmd, mi_sys, out);
	if (mi_cmd->fd[1] == -1)
		mi_freecmdsysexit(STDOUT_FILENO, 1, mi_sys);
	dup2(mi_cmd->fd[1], STDOUT_FILENO);
	if (mi_sys->nb_pipe <= 1)
		ft_fdclose (mi_cmd->fd[1]);
}
