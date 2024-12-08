/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mi_checkbuiltin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard  <jegirard@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 19:31:05 by jegirard          #+#    #+#             */
/*   Updated: 2024/12/07 13:24:53 by jegirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	mi_checkbuiltin(t_cmd *mi_cmd)
{
	if (!mi_cmd->args || !mi_cmd->args[0])
		return ;
	if (ft_findword (BUILTINS, mi_cmd->args[0]))
	{
		mi_cmd->builtin = true;
		mi_cmd->args[0] = mi_cmd->args[0];
	}
	else
		mi_cmd->builtin = false;
}
