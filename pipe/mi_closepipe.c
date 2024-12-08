/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mi_closepipe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard  <jegirard@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 17:30:32 by jegirard          #+#    #+#             */
/*   Updated: 2024/12/07 13:24:53 by jegirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	mi_closepipe(t_cmd *mi_cmd, int nb)
{
	nb++;
	while (nb--)
	{
		if (mi_cmd->fd[0] != -1)
			close(mi_cmd->fd[0]);
		if (mi_cmd->fd[1] != -1)
			close(mi_cmd->fd[1]);
	}
}
