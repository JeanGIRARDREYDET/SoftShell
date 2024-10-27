/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mi_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard <jegirard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 14:47:50 by jegirard          #+#    #+#             */
/*   Updated: 2024/10/20 19:12:16 by jegirard         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../minishell.h"

char	*mi_getenv(char *key, t_sys *mi_sys)
{
	int			i;
	int			len;
	char		end;

	i = 0;
	len = ft_strlen(key);
	while (mi_sys->env[i])
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

char	*mi_getenv_env(char *key, char **env)
{
	int			i;
	int			len;
	char		end;

	i = 0;
	len = ft_strlen(key);
	while (*env[i])
	{
		end = env[i][len];
		if (ft_strncmp (env[i], key, len) == 0 && end == '=')
			break ;
		i++;
	}
	if(env[i])
		return (env[i] + len + 1);
	return (NULL);
}