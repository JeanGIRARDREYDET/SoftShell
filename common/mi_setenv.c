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

int	mi_setenv(char *key, char *value, t_sys *sys)
{
	int			i;
	int			len;
	char		*tmp;

	i = 0;
	len = ft_strlen(key);
	while (sys->env[i])
	{
		if (ft_strncmp (sys->env[i], key, len) == 0)
		{
			tmp = join_3(key, "=", value);
			free(sys->env[i]);
			sys->env[i] = tmp;
			return (i);
			break ;
		}
		i++;
	}
	return (-1);
}
