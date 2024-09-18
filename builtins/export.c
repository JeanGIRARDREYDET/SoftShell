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

void	print_export(t_sys *sys)
{
	int	i;

	i = 0;
	while (sys->env[i] && sys->env[i] != 0 && sys->env[i] != NULL)
	{
			printf("%s\n", sys->env[i]);
		i++;
	}
}

void	builtin_export(char *key, t_sys *s_sys)
{
	int		i;
	int		pos;
	char	**ienv;
	size_t	e;

	e = ft_strchr_pos(key, '=');
	i = 0;
	pos = -1;

	if (!key=='\0')
		print_export(s_sys);
	if (key[e] == '=' || key[e] == '\0')
		e++;
	while (s_sys->env[i])
	{
		if (ft_strncmp (s_sys->env[i], key, e) == 0)
		{
			pos = i;
			break;
		}
		i++;
	}
	while (key[e] != '\0' && key[e] != ' ')
		e++;
	key[e] = '\0';
	if (pos == -1)
	{
		s_sys->env_len = s_sys->env_len + 1;
		ienv = (char **)ft_calloc(s_sys->env_len, sizeof(char *));
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
}
