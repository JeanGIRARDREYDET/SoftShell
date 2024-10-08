/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mi_freepipe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 11:40:01 by jegirard          #+#    #+#             */
/*   Updated: 2024/10/08 11:40:05 by jegirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"


void	mi_freepipe(t_pipe *mi_pipe)
{
//	ft_arrfree(mi_pipe->paths);
	if (mi_pipe->cmd != NULL)
		free(mi_pipe->cmd);
	if (mi_pipe->cmd != NULL)
		free(mi_pipe->cmd);
}
