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

	mi_sys->code_error = 0;
	if (mi_sys->error == NULL)
		return ;
	while (mi_sys->error && mi_sys->error != NULL)
	{
		mi_sys->code_error = mi_sys->error->code_error;
		tmp = mi_sys->error->next;
		free(mi_sys->error);
		mi_sys->error = tmp;
	}
	mi_sys->error = NULL;
}

void	mi_freeonecmd(t_cmd *mi_cmd)
{
	if (!mi_cmd)
		return ;
	if (mi_cmd->args != NULL)
		ft_arrclose(mi_cmd->args);
	mi_cmd->args = NULL;
	if (mi_cmd->full != NULL)
		free(mi_cmd->full);
	mi_cmd->full = NULL;
	if (mi_cmd->split != NULL)
		ft_arrclose(mi_cmd->split);
	mi_cmd->split = NULL;
	if (mi_cmd->red != NULL)
		free(mi_cmd->red);
	mi_cmd->red = NULL;
	if (mi_cmd != NULL)
		free(mi_cmd);
	mi_cmd = NULL;
}

void	mi_freecmd(t_sys *mi_sys)
{
	t_cmd	*tmp;

	if (!mi_sys->cmd)
		return ;
	while (mi_sys->cmd && mi_sys->cmd != NULL)
	{	
		tmp = mi_sys->cmd->next;
		mi_freeonecmd(mi_sys->cmd);
		mi_sys->cmd = tmp;
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
	if (mi_sys->cmd && mi_sys->cmd != NULL)
		mi_freecmd(mi_sys);
	if (mi_sys->error != NULL)
		mi_freeerror(mi_sys);
	rl_clear_history();
}
