/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard  <jegirard@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 19:31:05 by jegirard          #+#    #+#             */
/*   Updated: 2024/12/07 13:24:53 by jegirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	builtin_env(t_sys *mi_sys, int fd)
{
	int	i;

	i = 0;
	while (mi_sys->env != NULL && mi_sys->env[i] != 0)
	{
		if (ft_strin(mi_sys->env[i], '='))
		{
			write(fd, mi_sys->env[i], ft_strlen(mi_sys->env[i]));
			write(fd, "\n", 1);
		}
		i++;
	}
	mi_sys->exit_status = EXIT_SUCCESS;
}
