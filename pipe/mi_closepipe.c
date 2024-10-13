/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mi_closepipe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 11:37:18 by jegirard          #+#    #+#             */
/*   Updated: 2024/10/08 11:37:20 by jegirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	mi_closepipe(t_pipe *mi_pipe, int nb)
{
	nb++;
	while (nb--)
	{
		if (mi_pipe->fdd[0] != -1)
			close(mi_pipe->fdd[0]);
		if (mi_pipe->fdd[1] != -1)
			close(mi_pipe->fdd[1]);
	}
}
