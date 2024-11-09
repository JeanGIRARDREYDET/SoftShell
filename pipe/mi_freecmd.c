/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mi_freecmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 11:40:01 by jegirard          #+#    #+#             */
/*   Updated: 2024/10/08 11:40:05 by jegirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	mi_freeerror(t_sys *mi_sys)
{
	t_error	*tmp;
	t_error	*tmp2;

	tmp = mi_sys->error;
	while (tmp != NULL)
	{
		tmp2 = tmp->next;
		free(tmp);
		tmp = tmp2;
	}
}

void	mi_freeonecmd (t_cmd *mi_cmd)
{
	if (!mi_cmd || !(mi_cmd->id > 0))
		return ;
	if (mi_cmd->args != NULL)
		ft_arrclose(mi_cmd->args);
	if (mi_cmd->full_cmd != NULL)
		free(mi_cmd->full_cmd);
	if (mi_cmd->split_cmd)
		ft_arrclose(mi_cmd->split_cmd);
	if (mi_cmd->redirection != NULL)
		free(mi_cmd->redirection);
	if (mi_cmd->cmd != NULL)
		free(mi_cmd->cmd);
	free(mi_cmd);
}

void	mi_freecmd (t_cmd *mi_cmd, t_sys *mi_sys)
{
	t_cmd	*tmp;

	if (!mi_cmd || !(mi_cmd->id > 0))
		return ;
	while (mi_cmd && mi_cmd != NULL)
	{
		tmp = (mi_cmd)->next;
		mi_freeonecmd(mi_cmd);
		mi_cmd = tmp;
	}
	mi_sys->cmd = NULL;
	mi_freeerror(mi_sys);
}

void	mi_freesys(t_sys *mi_sys)
{
	if (mi_sys == NULL)
		return ;
	if (mi_sys->env != NULL && mi_sys->env != NULL)
		ft_arrclose(mi_sys->env);
	if (mi_sys->senv != NULL && mi_sys->senv->shlvl && mi_sys->senv->shlvl != NULL)
		free(mi_sys->senv->shlvl);
	if (mi_sys->cmd && mi_sys->cmd != NULL)
		mi_freecmd(mi_sys->cmd, mi_sys);
	if (mi_sys->env != NULL && mi_sys->env != NULL)
		free(mi_sys->senv);
}
