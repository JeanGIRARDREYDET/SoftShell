/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mi_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard  <jegirard@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 18:31:47 by jegirard          #+#    #+#             */
/*   Updated: 2024/12/07 13:24:53 by jegirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*mi_getenv(char *key, t_sys *mi_sys)
{
	int			i;
	int			len;
	char		end;

	i = 0;
	len = ft_strlen(key);
	while (i <= mi_sys->len_env)
	{
		end = mi_sys->env[i][len];
		if (ft_strncmp (mi_sys->env[i], key, len) == 0 && end == '=')
			break ;
		i++;
	}
	if (mi_sys->env[i])
		return (mi_sys->env[i] + len + 1);
	return (NULL);
}

char	*mi_getenv_env(char *key, t_sys *mi_sys)
{
	int			i;
	int			len;
	char		end;

	i = 0;
	len = ft_strlen(key);
	while (i<= mi_sys->len_env)
	{
		end = mi_sys->env[i][len];
		if (ft_strncmp (mi_sys->env[i], key, len) == 0 && end == '=')
			break ;
		i++;
	}
	if (mi_sys->env[i])
		return (mi_sys->env[i] + len + 1);
	return (NULL);
}
