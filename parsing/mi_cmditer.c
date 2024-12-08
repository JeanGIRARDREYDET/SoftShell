/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mi_cmditer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard  <jegirard@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 11:38:34 by jegirard          #+#    #+#             */
/*   Updated: 2024/12/07 13:24:53 by jegirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	mi_cmditer(t_sys *mi_sys, void (*f)(t_cmd *mi_cmd))
{
	t_cmd	*mi_cmd;

	if (mi_sys->nb_error > 0)
		return ;
	mi_cmd = mi_sys->cmd;
	while (mi_cmd != NULL)
	{
		(*f)(mi_cmd);
		mi_cmd = mi_cmd->next;
	}
}

void	mi_cmdargsiter(char **r, t_sys *s, void (*f)(char *r, t_sys *s))
{
	int	i;

	i = 1;
	while (r[i] != NULL)
	{
		(*f)(r[i], s);
		i++;
	}
}

void	mi_sysargsiter(t_sys *mi_sys, void (*f)(char *r, t_sys *mi_sys))
{
	t_cmd			*mi_cmd;
	int				i;

	if (mi_sys->nb_error > 0)
		return ;
	mi_cmd = mi_sys->cmd;
	while (mi_cmd != NULL)
	{
		i = 1;
		while (*mi_cmd->args && mi_cmd->args[i])
		{
			(*f)(mi_cmd->args[i], mi_sys);
			i++;
		}
		mi_cmd = mi_cmd->next;
	}
}

void	mi_rediriter(t_red *r, t_sys *s, int t, void (*f)(t_red *r, t_sys *s ))
{
	while (r && r != NULL)
	{
		if (r->redir_type == t)
			(*f)(r, s);
		r = r->next ;
	}
}

void	mi_sysrediter(t_sys *sys, int type, void (*f)(t_red *red, t_sys *sys))
{
	t_cmd	*mi_cmd;

	if (sys->nb_error > 0)
		return ;
	mi_cmd = sys->cmd;
	while (mi_cmd != NULL)
	{
		mi_rediriter(mi_cmd->red, sys, type, f);
		mi_cmd = mi_cmd->next;
	}
}
