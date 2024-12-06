/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mi_freesys.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:01:58 by jegirard          #+#    #+#             */
/*   Updated: 2024/12/05 16:02:02 by jegirard         ###   ########.fr       */
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

void	mi_freesev(t_sys *mi_sys)
{
	if (mi_sys->senv)
	{
		if (mi_sys->senv->oldpwd)
			free(mi_sys->senv->oldpwd);
		if (mi_sys->senv->pwd)
			free(mi_sys->senv->pwd);
		if (mi_sys->senv->shlvl)
			free(mi_sys->senv->shlvl);
		free(mi_sys->senv);
	}
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
	mi_freesev(mi_sys);
	rl_clear_history();
}
