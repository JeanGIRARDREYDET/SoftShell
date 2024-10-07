/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mi_create_pipe.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 19:48:29 by jegirard          #+#    #+#             */
/*   Updated: 2024/10/04 19:48:33 by jegirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_pipe	*mi_createpipe(void)
{
	t_pipe	*pipe;

	pipe = ft_calloc(1, sizeof (t_pipe));
	if (!pipe)
		return (NULL);
	pipe->pid = 0;
	pipe->full_cmd = NULL;
	pipe->cmd = NULL;
	pipe->arg = NULL;
	pipe->args = NULL;
	pipe->bultin = true;
	pipe->error.num = 0;
	pipe->error.msg = NULL;
	pipe->duplexe_canal[0] = 0;
	pipe->duplexe_canal[1] = 0;
	pipe->fdd[0][0] = 0;
	pipe->fdd[0][1] = 0;
	pipe->fdd[1][0] = 0;
	pipe->fdd[1][1] = 0;
	pipe->file = NULL;
	pipe->next = NULL;
	return (pipe);
}
