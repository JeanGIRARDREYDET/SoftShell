/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doferet <doferet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 13:47:28 by doferet           #+#    #+#             */
/*   Updated: 2024/09/10 11:37:52 by doferet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
export sans argument a un comportement indefini donc il faut le definir export
transfere une donnee entree dans le parent ex : $myname = "dollyne" si on fit un
echo, le parent renvoie bien dollyne, si on ouvre un autre bash, il n'aura pas
cette variable donc si on utilise exporte l'enfant a bien la variable myname
*/

void	print_export(t_sys *mi_sys)
{
	int	i;

	i = 0;
	if (mi_sys->env == NULL)
	{
		return ;
	}
	while (mi_sys->env[i++])
	{
		write(STDOUT_FILENO, "declare -x ", 11);
		write(STDOUT_FILENO, mi_sys->env[i], ft_strlen(mi_sys->env[i]));
		write(STDOUT_FILENO,"\n",1);
	}
}

void	s_env_create_value(char *line, t_sys *mi_sys)
{
	char		**ienv;
	int			i;

	mi_sys->len_env += 2+ 2;
	ienv = (char **)ft_calloc(mi_sys->len_env, sizeof(char *));
	if (ienv == NULL)
	{
		mi_logerror(126, "Cannot allocate memory", mi_sys);
		mi_sys->exit_status = EXIT_FAILURE;
	}
	i = -1;
	while (mi_sys->env[++i])
		ienv[i] = ft_strdup(mi_sys->env[i]);
	if (ienv != NULL && ienv[i] != NULL)
		ienv[i] = line;
	free (mi_sys->env);
	mi_sys->env = ienv;
}

void	s_env_create_update_value(char *line, t_sys *mi_sys)
{
	int			pos;

	pos = ft_get_confpos(line, '=', mi_sys->env);
	if (pos == -1)
		s_env_create_value (line, mi_sys);
	else
	{
		free(mi_sys->env[pos]);
		mi_sys->env[pos] = line;
	}
	mi_sys->exit_status = EXIT_SUCCESS;
}

int	mi_export_values(char *key, t_sys *mi_sys)
{
	int			next_value;
	char		*msg;

	while (key[0] != '\0' && key[0] < 33)
		key++;
	if (key[0] == '=')
	{
		msg = join_3("export: `", key, "' not a valid identifier");
		mi_logerror(1, msg, mi_sys);
		free(msg);
		mi_sys->exit_status = EXIT_FAILURE;
		return (mi_sys->exit_status);
	}
	next_value = 0 ;
	while (key[next_value] != '\0' && key[next_value] > 32)
		next_value++;
	s_env_create_update_value(ft_strdupleft (key, next_value), mi_sys);
	if (key[next_value] != '\0')
		mi_export_values(key + next_value, mi_sys);
	mi_sys->exit_status = EXIT_SUCCESS;
	return (mi_sys->exit_status);
}

void	builtin_export(char *key, t_sys *mi_sys)
{
	if (mi_sys->env == NULL)
		mi_logerror(1, "export: env NULL", mi_sys);
	if (!key || key[0] == '\0')
		print_export(mi_sys);
	else
		mi_export_values(key, mi_sys);
}
