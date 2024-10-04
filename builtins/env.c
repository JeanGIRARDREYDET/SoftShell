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

void	builtin_env(t_sys *mi_sys)
{
	int	i;

	i = 0;
	while (mi_sys->env != NULL && mi_sys->env[i] != 0)
	{
		if (ft_strin(mi_sys->env[i], '='))
			printf(" %s\n", mi_sys->env[i]);
		i++;
	}
}
