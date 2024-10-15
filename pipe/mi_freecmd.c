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
//	ft_arrfree(mi_cmd->paths);
	if (mi_cmd->cmd != NULL)
		free(mi_cmd->cmd);
	if (mi_cmd->cmd != NULL)
		free(mi_cmd->cmd);
}
