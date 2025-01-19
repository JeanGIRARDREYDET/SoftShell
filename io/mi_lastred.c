/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mi_lastred.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doferet <doferet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 11:38:34 by jegirard          #+#    #+#             */
/*   Updated: 2025/01/17 16:40:10 by doferet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

bool	ft_intisinarray(int *array, int find)
{
	int			i;

	i = 0;
	if (!array)
		return (false);
	while (array && i < 2)
	{
		if (array[i] == find)
			return (true);
		i++;
	}
	return (false);
}

int	mi_lastred(t_red *mi_re, t_sys *mi_sys, int *finds)
{
	t_red	*mi_return;

	mi_return = NULL;
	if (mi_re == NULL)
		return (-1);
	while (mi_re)
	{
		if (ft_intisinarray(finds, mi_re->redir_type))
		{
			mi_set_io_files(mi_re, mi_sys);
			if (mi_re->fd != -1)
				ft_fdclose(mi_re->fd);
			mi_return = mi_re;
		}
		mi_re = mi_re->next;
	}
	mi_set_io_files(mi_return, mi_sys);
	return (mi_return->fd);
}
