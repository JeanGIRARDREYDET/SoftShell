/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard  <jegirard@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 19:49:29 by jegirard          #+#    #+#             */
/*   Updated: 2024/12/07 13:24:53 by jegirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// unset values and attributes of variables and functions
// unset peut supprimer une variable cree dans env

void	builtin_unset(char *key, t_sys *mi_sys)
{
	int	pos;

	if (key && ft_findword(key, "PATH"))
		mi_sys->senv->path = NULL;
	pos = ft_get_confpos(key, mi_sys);
	if (pos != -1)
	{

		free(mi_sys->env[pos]);
		while (mi_sys->env[pos + 1] != NULL)
		{
			mi_sys->env[pos] = mi_sys->env[pos + 1];
			pos++;
		}
		mi_sys->env[pos] = NULL;
		mi_sys->len_env--;
	}
}
