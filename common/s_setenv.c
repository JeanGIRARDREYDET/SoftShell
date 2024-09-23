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

int s_setenv(char *key, char *value, t_sys *s_sys)
{
	int i;
	int len;

	i = 0;
	len = ft_strlen(key);
	while (s_sys->env[i])
	{
		if (ft_strncmp (s_sys->env[i], key, len) == 0)
		{
			free(s_sys->env[i]);
			s_sys->env[i] = join_3(key, "=",value);
			return (i);
			break;
		}
		i++;
	}
	return (-1);
}
