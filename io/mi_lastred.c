/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mi_lastred.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard  <jegirard@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 11:38:34 by jegirard          #+#    #+#             */
/*   Updated: 2024/12/07 13:24:53 by jegirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

bool	ft_intisinarray(int *array, int find)
{
	int			i;

	i = 0;
	while (array[i] != -1)
	{
		if (array[i] == find)
			return (true);
		i++;
	}
	return (false);
}

int	mi_lastred(t_red *mi_re, t_sys *mi_sys, int *find)
{
	t_red	*mi_return;

	mi_return = NULL;
	if (mi_re == NULL)
		return (-1);
	while (mi_re->next)
	{
		if (ft_intisinarray(find, mi_re->redir_type))
		{
			mi_set_io_files(mi_re, mi_sys);
			close(mi_re->fd);
			mi_return = mi_re;
		}
		mi_re = mi_re->next;
	}
	if (ft_intisinarray(find, mi_re->redir_type))
		mi_return = mi_re;
	mi_set_io_files(mi_return, mi_sys);
	return (mi_return->fd);
}
