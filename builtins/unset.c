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

void	builtin_unset(char *key, t_sys *sys)
{
	int	i;
	int	pos;

	i = 0;
	pos = -1;
	while (sys->env[i])
	{
		if (ft_strnstr (sys->env[i], key, ft_strlen(key)) != 0)
			pos = i;
		i++;
	}
	if (pos == -1)
		return ;
	while (sys->env[pos + 1])
	{
		sys->env[pos] = sys->env[pos + 1];
		pos++;
	}
	free(sys->env[pos+1]);
	sys->env[pos] = NULL;
}
