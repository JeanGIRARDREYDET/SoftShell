/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_mgetenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 14:47:50 by jegirard          #+#    #+#             */
/*   Updated: 2024/09/23 14:47:55 by jegirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*s_getenv(char *key, t_sys *sys)
{
	int			i;
	int			len;
	char		end;

	i = 0;
	len = ft_strlen(key);
	while (sys->env[i])
	{
		end = sys->env[i][len];
		if (ft_strncmp (sys->env[i], key, len) == 0 && end == '=')
			break ;
		i++;
	}
	if(sys->env[i])
		return (sys->env[i] + len + 1);
	return (NULL);
}
