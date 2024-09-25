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
