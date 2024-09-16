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

// export sans argument a un comportement indefini donc il faut le definir
// export transfere une donnee entree dans le parent ex : $myname = "dollyne" si on fit un echo, le parent 
// renvoie bien dollyne, si on ouvre un autre bash, il n'aura pas cette variable donc si on utilise exporte
// l'enfant a bien la variable myname

void	builtin_export(char *key, t_sys *s_sys)
{
	int		i;
	int		pos;
	char	**ienv;
	char	*key;
	int		e;

	e = 0;
	while (key[e] != '\0' && key[e] != '=')
		e++;
	i = 0;
	pos = -1;
	if (! key)
		builtin_env(s_sys);
	if (key[e] != '=')
		return;
	key[e] = '\0';
	while (s_sys->env[i])
	{
		if (ft_strncmp (s_sys->env[i], key, e) != 0)
			pos = i;
		i++;
	}
	key[e] = '=';
	while (key[e] != '\0' && key[e] != ' ')
		e++;
	key[e] = '\0';
	if (pos == -1)
	{
		ienv = (char **)ft_calloc(i + 1, sizeof(char *));
		i = -1;
		while (s_sys->env[++i])
		{
			ienv[i] = ft_strdup(s_sys->env[i]);
			free(s_sys->env[i]);
		}
		free(s_sys->env);
		ienv[i++] = ft_strdup(key;
		ienv[i++] = NULL;
		s_sys->env = ienv;
	}
	else
	{
		free(s_sys->env[i]);
		s_sys->env[i] = ft_strdup(key_value);
		i++;
	}
}
