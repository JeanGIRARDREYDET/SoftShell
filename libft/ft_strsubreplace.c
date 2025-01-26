/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsubreplace.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard  <jegirard@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 19:49:29 by jegirard          #+#    #+#             */
/*   Updated: 2024/12/07 13:24:53 by jegirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_strsubreplace(char *str, int start, int len, char *replace)
{
	char		*nw;
	int			i[2];

	ft_bzero(i, 2 * sizeof(int));
	nw = ft_calloc(ft_strlen(str) + ft_strlen(replace) - len + 1, sizeof(char));
	while (i[0] < start)
	{
		nw[i[0]] = str[i[0]];
		i[0]++;
	}
	while (replace && replace[i[1]])
	{
		nw[i[0]] = replace[i[1]];
		i[0]++;
		i[1]++;
	}
//	 return (nw);
	i[1] = start + len;
	while (str[i[1]])
	{
		nw[i[0]] = str[i[1]];
		i[0]++;
		i[1]++;
	}
	return (nw);
}
