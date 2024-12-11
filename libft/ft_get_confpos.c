/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_confpos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard  <jegirard@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 10:41:04 by jegirard          #+#    #+#             */
/*   Updated: 2024/12/07 13:24:53 by jegirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_get_confpos(char *key, t_sys *mi_sys)
{
	int			i;
	int			offset;
	char		*line;
	char		endline;
	char		endkey;

	i = 0;
	offset = 0;
	while (key[offset] != '\0' && key[offset] > 33)
		offset++;
	while (i < mi_sys->len_env && mi_sys->env[i])
	{
		line = mi_sys->env[i];
		endline = ft_strchr_pos(line, '=');
		endkey = ft_strchr_pos(key, '=');
		if (endline == endkey && ft_strncmp (line, key, endkey) == 0)
			return (i);
		i++;
	}
	return (-1);
}
