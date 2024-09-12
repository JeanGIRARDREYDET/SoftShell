/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 09:42:44 by jegirard          #+#    #+#             */
/*   Updated: 2023/11/15 09:42:49 by jegirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
Name :

Description :

Prototype :
			char *ft_strjoin(char const *s1, char const *s2);
Paramètres :

Retour :

*/

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*p;
	int		i;
	int		j;

	if (!(s1 && s2))
		return (0);
	i = 0;
	j = 0;
	while (s1[i++] != 0)
		;
	while (s2[j++] != 0)
		i++;
	p = (char *) ft_calloc (i, sizeof(char));
	if (!p)
		return (NULL);
	j = 0;
	i = 0;
	while (s1[j] != 0)
		p[i++] = s1[j++];
	j = 0;
	while (s2[j] != 0)
		p[i++] = s2[j++];
	return (p);
}
