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
	while (array && array[i] && array[i] != -1)
	{
		if (array[i] == find)
			return (true);
		i++;
	}
	return (false);
}
//		<<a ls o >a
int	mi_lastred(t_red *mi_re, t_sys *mi_sys, int *find)
{
	t_red	*mi_return;

	mi_return = NULL;
	if (mi_re == NULL)
		return (-1);
	while (mi_re->next)
	{
		dprintf(2, "mi_lastred 40 : %s\n", mi_re->file_name);
		dprintf(2, "mi_lastred 41 : %d\n", mi_re->redir_type);
		if (ft_intisinarray(find, mi_re->redir_type))
		{
			mi_set_io_files(mi_re, mi_sys);
			close(mi_re->fd);
			mi_return = mi_re;
		}
		mi_re = mi_re->next;
	}
	dprintf(2, "mi_lastred 40  redir_type : %d\n", mi_re->redir_type);
	if (ft_intisinarray(find, mi_return->redir_type))
		mi_return = mi_re;
	dprintf(2, "mi_lastred 52 : %s\n", mi_return->file_name);
	dprintf(2, "mi_lastred 43 : %d\n", mi_return->redir_type);
	mi_set_io_files(mi_return, mi_sys);
	dprintf(2, "mi_lastred 55\n");
	dprintf(2, "mi_return->fd = %d\n", mi_return->fd);
	return (mi_return->fd);
}
