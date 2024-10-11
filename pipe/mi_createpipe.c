/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mi_createpipe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 19:48:29 by jegirard          #+#    #+#             */
/*   Updated: 2024/10/04 19:48:33 by jegirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_pipe	*mi_createpipe(t_sys *mi_sys)
{
	t_pipe	*pipe;

	pipe = ft_calloc(1, sizeof (t_pipe));
	if (!pipe)
		return (NULL);
	pipe->id = 0;
	pipe->no = ++mi_sys->nb_pipe;
	pipe->full_cmd = NULL;
	pipe->cmd = NULL;
	pipe->arg = NULL;
	pipe->args = NULL;
	pipe->builtin = true;
	pipe->error.msg = NULL;
	pipe->fdd[0] = 0;
	pipe->fdd[1] = 0;
	pipe->file = NULL;
	pipe->next = NULL;
	return (pipe);
}
