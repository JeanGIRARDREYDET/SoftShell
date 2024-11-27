/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard <jegirard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 13:47:28 by doferet           #+#    #+#             */
/*   Updated: 2024/11/26 21:21:56 by jegirard         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

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
		write(fd,"\"\n",2);
		i++;
	}
}

void	s_env_create_value(char *line, t_sys *mi_sys)
{
	char		**ienv;
	int			i;

	mi_sys->len_env += 2;
	ienv = (char **)ft_calloc(mi_sys->len_env, sizeof(char *));
	if (ienv == NULL)
	{
		mi_logerror(126, "Cannot allocate memory", mi_sys);
		mi_sys->exit_status = EXIT_FAILURE;
	}
	i = -1;
	while (mi_sys->env[++i])
		ienv[i] = ft_strdup(mi_sys->env[i]);
	if (ienv != NULL && ienv[i] == NULL)
		ienv[i] = line;
	free (mi_sys->env);
	mi_sys->env = ienv;
}

void	s_env_create_update_value(char *key, t_sys *mi_sys)
{
	int			pos;
	char		*msg;

	if (!key || key[0] == '=')
	{
		msg = join_3("export: `", key, "' not a valid identifier");
		mi_logerror(1, msg, mi_sys);
		free(msg);
		mi_sys->exit_status = EXIT_FAILURE;
		return ;
	}
	pos = ft_get_confpos(key, '=', mi_sys->env);
	if (pos == -1)
		s_env_create_value (ft_strdup(key), mi_sys);
	else
	{
		free(mi_sys->env[pos]);
		mi_sys->env[pos] = key;
	}
	mi_sys->exit_status = EXIT_SUCCESS;
}

int	mi_export_values(char **key, t_sys *mi_sys)
{
	int			i;

	i = 1;
	while (key[i] != NULL)
		s_env_create_update_value(key[i++], mi_sys);
	return (mi_sys->exit_status);
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
