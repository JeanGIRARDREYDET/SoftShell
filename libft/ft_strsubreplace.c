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
	char					*nw;
	struct s_CompReplace	cr;

	cr.i = 0;
	cr.j = 0;
	nw = ft_calloc(ft_strlen(str) + ft_strlen(replace) - len + 1, sizeof(char));
	while (cr.i < start)
	{
		nw[cr.i] = str[cr.i];
		cr.i++;
	}
	while (replace[cr.j])
	{
		nw[cr.i] = replace[cr.j];
		cr.i++;
		cr.j++;
	}
	cr.j = start + len;
	while (str[cr.j])
	{
		nw[cr.i] = str[cr.j];
		cr.i++;
		cr.j++;
	}
	return (nw);
}
