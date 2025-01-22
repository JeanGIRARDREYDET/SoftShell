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

bool ft_anti_negative(char **keys_values)
{
	int i;
	int j;

	i = 1;
	j = 0;
	while (keys_values[i])
	{
		j = 0;
		while (keys_values[i][j])
		{
			if (ft_isdigit(keys_values[i][0]) == true)
				return (true);
			if (keys_values[i][j] == '=')
				return (false);
			if (keys_values[i][j] == '-')
			return (true);
			j++;
		}
	i++;
	}
	return (false);
}

void	print_export(t_sys *mi_sys, int fd)
{
	int i;

	i = 0;
	if (mi_sys->env == NULL)
 		return ;
	while (i <= mi_sys->len_env)
	{
		write(fd, "declare -x \"", 12);
		write(fd, mi_sys->env[i], ft_strlen(mi_sys->env[i]));
		write(fd, "\"\n", 2);
			i++;
	}
}

void    builtin_export(char **keys_values, int fd, t_sys *mi_sys)
{
 	(void)fd;
    if (!mi_sys->env)
        mi_logerror(1, "export: env NULL", mi_sys);
    else if (ft_anti_negative(keys_values) == true)
        mi_logerror(1, "export: not a valid identifier", mi_sys);
    else if (keys_values && keys_values[1] != NULL)
        mi_export_values(keys_values, mi_sys);
    else
        print_export(mi_sys, fd);
}
