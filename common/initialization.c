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

	s_sys->SHLVL = "0";
	i = 0;
	while (env[i])
	{
		if (ft_strnstr (env[i], "PATH=", 5) != 0)
			s_sys->path = env[i] + 5;
		if (ft_strnstr (env[i], "PWD=", 4) != 0)
			s_sys->pwd = env[i] + 4;
		if (ft_strnstr (env[i], "SHLVL=", 6) != 0)
			s_sys->SHLVL = ft_itoa((1 + ft_atoi(env[i] + 6)));
		i++;
	}
	ienv = (char **)ft_calloc(i, sizeof(char *));
	i = -1;
	while (env[++i])
	{
		if (ft_strnstr (env[i], "SHLVL=", 6) != 0)
			ienv[i] = ft_strjoin("SHLVL=", s_sys->SHLVL);
		else
			ienv[i] = ft_strdup(env[i]);
	}
	s_sys->env = ienv;
}
