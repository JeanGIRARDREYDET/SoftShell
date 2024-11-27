/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mi_lastred.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 11:23:07 by jegirard          #+#    #+#             */
/*   Updated: 2024/11/26 11:23:13 by jegirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int mi_lastred(t_red *mi_re,t_sys *mi_sys, int *find)
{
	t_red	*mi_return;

	mi_return = NULL;
	if (mi_re == NULL)
		return (-1);
	while (mi_re->next)
	{
		if (mi_re->redir_type == find[0] || mi_re->redir_type == find[1])
		{
			mi_set_io_files(mi_re, mi_sys);
			close(mi_re->fd);
			mi_return = mi_re;
		}	
		mi_re = mi_re->next;
	}
	if (mi_re->redir_type == find[0] || mi_re->redir_type == find[1])
		mi_return = mi_re;
	mi_set_io_files(mi_return, mi_sys);
	return (mi_return->fd);
}
