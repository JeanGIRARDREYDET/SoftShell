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

int	ft_get_confpos(char *key, char k_sep, char **conf)
{
	int			i;
	int			offset;
	char		*line;
	char		end;

	i = 0;
	offset = 0;
	while (key[offset] != k_sep && key[offset] != '\0' && key[offset] > 33)
		offset++;
	while (conf[i] && key[0] != k_sep)
	{
		line = conf[i];
		end = line[offset];
		if (ft_strncmp (line, key, offset) == 0 && (end == '=' || end == 0))
			return (i);
		i++;
	}
	return (-1);
}
