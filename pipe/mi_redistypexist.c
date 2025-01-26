/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mi_redistypexist.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 17:19:51 by jegirard          #+#    #+#             */
/*   Updated: 2025/01/19 17:20:00 by jegirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

bool	mi_redistypexist(int type, t_cmd *mi_cmd)
{
	t_red			*mi_red;

	mi_red = mi_cmd->red;
	while (mi_red)
	{
		if (mi_red->redir_type == type && mi_red->file_name)
		{
			if (access(mi_red->file_name, F_OK) != 0)
				return (true);
		}
		else if (!mi_red->next)
			return (false);
		mi_red = mi_red->next;
	}
	return (false);
}

void	mi_checkexist(t_red *mi_red, t_sys *mi_sys)
{
	if (access(mi_red->file_name, F_OK) != 0)
	{
		mi_logerror2(1, mi_red->file_name, 
			"Aucun fichier ou dossier de ce nom", mi_sys);
		mi_sys->code_error = 1;
	}
}
