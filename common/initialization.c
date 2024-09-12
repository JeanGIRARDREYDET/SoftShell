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

	i = 0;
	while (env[i])
	{
		if (ft_strnstr (env[i], "PATH=", 5) != 0)
			sys->path = env[i] + 5;
		if (ft_strnstr (env[i], "PWD=", 4) != 0)
			sys->pwd = env[i] + 4;
		if (ft_strnstr (env[i], "SHLVL=", 6) != 0)
			sys->SHLVL = env[i] + 4;
		i++;
	}
	sys->env = (char **)ft_calloc(i, sizeof(char *));
		i = 0;
	while (env[i])
	{
		sys->env[i] = ft_strdup(env[i]);
		i++;
	}
}
