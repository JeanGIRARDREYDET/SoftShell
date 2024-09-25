/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_getenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 14:47:50 by jegirard          #+#    #+#             */
/*   Updated: 2024/09/23 14:47:55 by jegirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*s_getenv(char *key, t_sys *s_sys)
{
	int			i;
	int			len;
	char		end;

	i = 0;
	len = ft_strlen(key);
	while (s_sys->env[i])
	{
		end = s_sys->env[i][len];
		if (ft_strncmp (s_sys->env[i], key, len) == 0 && end == '=')
			break ;
		i++;
	}
	return (s_sys->env[i] + len + 1);
}
