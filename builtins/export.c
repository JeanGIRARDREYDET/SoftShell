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

void	print_export(t_sys *sys)
{
	int	i;

	i = 0;
	while (sys->env != NULL && sys->env[i] != 0)
	{
		printf("declare -x %s\n", sys->env[i]);
		i++;
	}
}

void	s_env_create_value(char *line, t_sys *s_sys)
{
	char		**ienv;
	int			i;

	s_sys->senv.len = s_sys->senv.len + 1;
	ienv = (char **)ft_calloc(s_sys->senv.len, sizeof(char *));
	i = -1;
	while (s_sys->env[++i])
		ienv[i] = ft_strdup(s_sys->env[i]);
	ienv[i] = line;
	free(s_sys->env);
	s_sys->env = ienv;
}

void	s_env_create_update_value(char *line, t_sys *s_sys)
{
	int			pos;

	pos = ft_get_confpos(line, '=', s_sys->env);
	if (pos == -1)
		s_env_create_value (line, s_sys);
	else
	{
		free(s_sys->env[pos]);
		s_sys->env[pos] = line;
	}
}

int	export_values(char *key, t_sys *s_sys)
{
	int			next_value;

	while (key[0] != '\0' && key[0] < 33)
		key++;
	if (key[0] == '=')
		printf("export: `%s': not a valid identifier\n", key);
	next_value = 0 ;
	while (key[next_value] != '\0' && key[next_value] > 32)
		next_value++;
	s_env_create_update_value(ft_strdupleft (key, next_value), s_sys);
	if (key[next_value] != '\0')
		export_values(key + next_value, s_sys);
	return (0);
}

void	builtin_export(char *key, t_sys *s_sys)
{
	if (key[0] == '\0')
		print_export(s_sys);
	else
		export_values(key, s_sys);
}
