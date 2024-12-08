/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard  <jegirard@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 11:38:34 by jegirard          #+#    #+#             */
/*   Updated: 2024/12/07 13:24:53 by jegirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
export sans argument a un comportement indefini donc il faut le definir export
transfere une donnee entree dans le parent ex : $myname = "dollyne" si on fit un
echo, le parent renvoie bien dollyne, si on ouvre un autre bash, il n'aura pas
cette variable donc si on utilise exporte l'enfant a bien la variable myname
*/

void	print_export(t_sys *mi_sys, int fd)
{
	int	i;

	i = 0;
	if (mi_sys->env == NULL)
		return ;
	while (mi_sys->env[i])
	{
		write(fd, "declare -x \"", 12);
		write(fd, mi_sys->env[i], ft_strlen(mi_sys->env[i]));
		write(fd, "\"\n", 2);
		i++;
	}
}

void	builtin_export(char **key, int fd, t_sys *mi_sys)
{
	if (!mi_sys->env)
		mi_logerror(1, "export: env NULL", mi_sys);
	else if (key && key[1] != NULL)
		mi_export_values(key, mi_sys);
	else
		print_export(mi_sys, fd);
}
