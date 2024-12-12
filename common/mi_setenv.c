/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mi_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard  <jegirard@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 11:38:34 by jegirard          #+#    #+#             */
/*   Updated: 2024/12/07 13:24:53 by jegirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	mi_setenv(char *key, char *value, t_sys *mi_sys)
{
	int			i;
	int			len;
	char		*tmp;

	i = 0;
	len = ft_strlen(key);
	while (i < mi_sys->len_env)
	{
		if (ft_strncmp (mi_sys->env[i], key, len) == 0)
		{
			tmp = join_3(key, "=", value);
			free(mi_sys->env[i]);
			mi_sys->env[i] = tmp;
			return (i);
			break ;
		}
		i++;
	}
	return (-1);
}
