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

struct s_CompReplace
{
	int						i;
	int						j;
};

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
