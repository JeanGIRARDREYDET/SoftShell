/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doferet <doferet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 13:48:11 by doferet           #+#    #+#             */
/*   Updated: 2024/09/10 11:44:01 by doferet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// unset values and attributes of variables and functions
// unset peut supprimer une variable cree dans env

void	builtin_env2(t_sys *sys)
{
	int	i;

	i = 0;
	//while (sys->env != NULL && sys->env[i] && sys->env[i] != NULL)
	while (sys->env && sys->env[i] != 0 && sys->env[i] != NULL)
	{
		if (ft_strin(sys->env[i], '='))
			printf("%s\n", sys->env[i]);
		i++;
	}
}

void	s_unset2(char *key, t_sys *s_sys)
{
	int		i;
	int		pos;
	char	**ienv;
	size_t	e;

	e = ft_strchr_pos(key, '=');
	pos = -1;
	if (key[0] == '\0')
		print_export(s_sys);
	if (key[e] == '=' || key[e] == '\0')
		e++;
	i = 0;
	while (s_sys->env[i])
	{
		if (ft_strncmp (s_sys->env[i], key, e) == 0)
		{
			pos = i;
			break ;
		}
		i++;
	}
	while (key[e] != '\0' && key[e] != ' ')
		e++;
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
}

void	s_unset(char *key, t_sys *s_sys)
{
	int	i;
	int	pos;

	i = 0;
	pos = -1;
	while (s_sys->env[i])
	{
		if (ft_strnstr (s_sys->env[i], key, ft_strlen(key)) != 0)
			pos = i;
		i++;
	}
	if (pos == -1)
		return ;
	while (s_sys->env[pos + 1])
	{
		s_sys->env[pos] = s_sys->env[pos + 1];
		pos++;
	}
	free(s_sys->env[pos+1]);
	s_sys->env[pos] = NULL;
}
