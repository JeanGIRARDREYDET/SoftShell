/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_setenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 14:45:32 by jegirard          #+#    #+#             */
/*   Updated: 2024/09/23 14:45:37 by jegirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int s_setenv(char *key, char *value, t_sys *sys)
{
	int i;
	int len;

	i = 0;
	len = ft_strlen(key);
	while (sys->env[i])
	{
		if (ft_strncmp (sys->env[i], key, len) == 0)
		{
			free(sys->env[i]);
			sys->env[i] = join_3(key, "=",value);
			return (i);
			break;
		}
		i++;
	}
	return (-1);
}
