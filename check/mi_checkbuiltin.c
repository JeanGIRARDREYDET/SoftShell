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

void	mi_checkbuiltin(t_pipe *mi_pipe)
{
	if(ft_findword (BUILTINS, mi_pipe->cmd))
		mi_pipe->builtin = true;
	else
		mi_pipe->builtin = false;
}