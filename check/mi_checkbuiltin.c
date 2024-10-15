/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mi_checkbuiltin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard <jegirard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 00:49:45 by jegirard          #+#    #+#             */
/*   Updated: 2024/10/14 00:50:47 by jegirard         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../minishell.h"

void	mi_checkbuiltin(t_cmd *mi_cmd)
{
	if (ft_findword (BUILTINS, mi_cmd->cmd))
		mi_cmd->builtin = true;
	else
		mi_cmd->builtin = false;
}
