/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mi_lexingline.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 18:36:52 by jegirard          #+#    #+#             */
/*   Updated: 2024/10/04 18:36:56 by jegirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	mi_lexingline(char *ln, int i, t_pipe *cmd_pipe, t_sys *mi_sys)
{	
	t_pipe		*new_pipe;

	i = mi_pospasscote(ln, i, &cmd_pipe->error);
	while (ln[i] && ft_strchr(WSPACE, ln[i]))
		i++;
	if (ln[i] == '\0')
	{
		cmd_pipe->full_cmd = ft_strtrim_param(ln, 0, i, WSPACE);
		cmd_pipe->next = NULL;
		return ;
	}
	else if (ln[i] == '|')
	{
		new_pipe = ft_calloc(1, sizeof (t_pipe));
		if (!new_pipe)
			return ;
		cmd_pipe->full_cmd = ft_strtrim_param(ln, 0, i -1, WSPACE);
		cmd_pipe->next = new_pipe;
		new_pipe->no = ++mi_sys->nb_pipe;
		mi_lexingline (ln + (++i), 0, new_pipe, mi_sys);
	}
	else
		mi_lexingline (ln, ++i, cmd_pipe, mi_sys);
}
