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


void	mi_freecmd(t_cmd *mi_cmd)
{


//	if (mi_cmd->arg != NULL)
//		free(mi_cmd->arg);
//	if (mi_cmd->args != NULL)
//		ft_arrclose(mi_cmd->args);
	if (mi_cmd->full_cmd != NULL)
		free(mi_cmd->full_cmd);
	if (mi_cmd->split_cmd)
		ft_arrclose(mi_cmd->split_cmd);
	mi_cmd->split_cmd = NULL;
	if (mi_cmd->redirection != NULL)
		free(mi_cmd->redirection);
	//if (mi_cmd->next != NULL)
	//	mi_freecmd(mi_cmd->next);
	if (mi_cmd->cmd != NULL && mi_cmd->builtin == false) 
		free(mi_cmd->cmd);
	mi_cmd->cmd = NULL;
	mi_cmd->next = NULL;
	free(mi_cmd);
}
