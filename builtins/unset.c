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

void	builtin_unset(char *key, t_sys *s_sys)
{
	int	pos;

	pos = ft_get_confpos(key, '=', s_sys->env);
	if (pos != -1)
		free(s_sys->env[pos]);
}
