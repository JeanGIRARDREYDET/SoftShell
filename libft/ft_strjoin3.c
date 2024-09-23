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

char	*join_3(char *s1, char *s2, char *s3)
{
	char	*p;
	int		i;
	int		j;

	if (s1 == NULL || s2 == NULL || s3 == NULL)
		return (NULL);
	i = ft_strlen(s1) + ft_strlen(s2) + ft_strlen(s3);
	p = (char *) ft_calloc (i + 1, sizeof(char));
	if (!p)
		return (NULL);
	j = 0;
	i = 0;
	while (s1[j] != 0)
		p[i++] = s1[j++];
	j = 0;
	while (s2[j] != 0)
		p[i++] = s2[j++];
	j = 0;
	while (s3[j] != 0)
		p[i++] = s3[j++];
	p[i] = 0;
	return (p);
}

char	*join_4(char *s1, char *s2, char *s3, char *s4)
{
	char	*p;
	int		i;
	int		j;

	if (!(s1 && s2 && s3))
		return (0);
	i = ft_strlen(s1) + ft_strlen(s2) + ft_strlen(s3)+ ft_strlen(s4);
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
	j = 0;
	while (s3[j] != 0)
		p[i++] = s3[j++];
	j = 0;
	while (s4[j] != 0)
		p[i++] = s4[j++];
	p[i] = 0;
	return (p);
}
