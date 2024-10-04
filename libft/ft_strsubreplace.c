/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsubreplace.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 16:30:21 by jegirard          #+#    #+#             */
/*   Updated: 2024/10/04 16:30:27 by jegirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_strsubreplace(char *str, int start, int len, char *replace)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new = ft_calloc(ft_strlen(str) + ft_strlen(replace) - len + 1, sizeof(char));
	while (i < start)
	{
		new[i] = str[i];
		i++;
	}
	while (replace[j])
	{
		new[i] = replace[j];
		i++;
		j++;
	}
	j = start + len;
	while (str[j])
	{
		new[i] = str[j];
		i++;
		j++;
	}
	return (new);
}