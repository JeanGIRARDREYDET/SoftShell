/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doferet <doferet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 17:12:48 by doferet           #+#    #+#             */
/*   Updated: 2024/09/10 14:42:11 by doferet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	common_initialization(char **env, t_sys *s_sys)
{
	int		i;
	char	**ienv;

	s_sys->shlvl = "0";
	s_sys->env_len = 0;
	while (env[s_sys->env_len])
	{
		if (ft_strnstr (env[s_sys->env_len], "PATH=", 5) != 0)
			s_sys->path = env[s_sys->env_len] + 5;
		if (ft_strnstr (env[s_sys->env_len], "PWD=", 4) != 0)
			s_sys->pwd = env[s_sys->env_len] + 4;
		if (ft_strnstr (env[s_sys->env_len], "SHLVL=", 6) != 0)
			s_sys->shlvl = ft_itoa((1 + ft_atoi(env[s_sys->env_len] + 6)));
		s_sys->env_len++;
	}
	s_sys->env_len++;
	ienv = (char **)ft_calloc(s_sys->env_len, sizeof(char *));
	i = -1;
	while (env[++i])
	{
		if (ft_strnstr (env[i], "SHLVL=", 6) != 0)
			ienv[i] = ft_strjoin("SHLVL=", s_sys->shlvl);
		else
			ienv[i] = ft_strdup(env[i]);
	}
	s_sys->env = ienv;
}
