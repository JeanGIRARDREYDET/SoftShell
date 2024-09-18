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

void	builtin_env(t_sys *sys)
{
	int	i;

	i = 0;
	while (sys->env[i] && sys->env[i] != 0 && sys->env[i] != NULL)
	{
		if (ft_strin(sys->env[i], '='))
			printf("%s\n", sys->env[i]);
		i++;
	}
}
