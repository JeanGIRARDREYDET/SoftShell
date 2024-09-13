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

void	common_initialization(char **env, t_sys *sys)
{
	int	i;

	sys->SHLVL = "0";
	i = 0;
	while (env[i])
	{
		if (ft_strnstr (env[i], "PATH=", 5) != 0)
			sys->path = env[i] + 5;
		if (ft_strnstr (env[i], "PWD=", 4) != 0)
			sys->pwd = env[i] + 4;
		if (ft_strnstr (env[i], "SHLVL=", 6) != 0)
			sys->SHLVL = ft_itoa((1 + ft_atoi(env[i] + 6)));
		i++;
	}
	sys->env = (char **)ft_calloc(i, sizeof(char *));
	i = -1;
	while (env[++i])
	{
		if (ft_strnstr (env[i], "SHLVL=", 6) != 0)
			sys->env[i] = ft_strjoin("SHLVL=", sys->SHLVL);
		else
			sys->env[i] = ft_strdup(env[i]);
	}
}


