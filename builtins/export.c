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
	while (sys->env != NULL && sys->env[i] != NULL)
	{
		printf("declare -x %s\n", sys->env[i]);
		i++;
	}
}

int	export_values(char *key, t_sys *s_sys)
{
	int		i;
	int		pos;
	char	**ienv;
	size_t	e;

	while (key[0] != '\0' && key[0] < 33)
		key++;

		
	pos = -1;
	e = 0;
	while (key[e] != '=' && key[e] != '\0' && key[e] > 33)
		e++;
	i = 0;
	if (key[0] == '=')
	{
		printf("export: `%s': not a valid identifier\n", key);
	}
	while (s_sys->env[i] && key[0] != '=')
	{
		if (ft_strncmp (s_sys->env[i], key, e) == 0 && ( s_sys->env[i][e] == '='|| s_sys->env[i][e] == 0 ))
		{
			pos = i;
			break ;
		}
		i++;
	}
	while (key[e] != '\0' && key[e] > 32)
		e++;
	if (key[e] != '\0')
		export_values(key + e, s_sys);
	if (key[0] == '=')
		return (1);
	key[e] = '\0';
	if (pos == -1)
	{
		s_sys->senv.len = s_sys->senv.len + 1;
		ienv = (char **)ft_calloc(s_sys->senv.len, sizeof(char *));
		i = -1;
		while (s_sys->env[++i])
			ienv[i] = ft_strdup(s_sys->env[i]);
		ienv[i] = ft_strdup(key);
		free(s_sys->env);
		s_sys->env = ienv;
	}
	else
	{
		free(s_sys->env[pos]);
		s_sys->env[pos] = ft_strdup(key);
	}
	return(0);
}

void	builtin_export(char *key, t_sys *s_sys)
{
	if (key[0] == '\0')
		print_export(s_sys);
	else
		export_values(key, s_sys);
}
