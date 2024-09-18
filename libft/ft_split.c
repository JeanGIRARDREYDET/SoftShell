/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 09:44:52 by jegirard          #+#    #+#             */
/*   Updated: 2023/11/15 09:44:56 by jegirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
Description :
			ft	Alloue (avec malloc(3)) et retourne un tableau de chaînes de
			caractères obtenu en séparant ’s’ à l’aide du caractère ’c’,
			utilisé comme délimiteur.
			Le tableau doit être terminé par NULL.
Prototype :
			char **ft_split(char const *s, char c);

Paramètres :
			s: La chaîne de caractères à découper.
			c: Le caractère délimiteur.
retour
			Le tableau de nouvelles chaînes de caractères résultant du découpage.
			NULL si l’allocation échoue.
EXternes
			malloc, free
*/

static size_t	str_nb_elt_neq(char const *s, char c)
{
	while (*s && *s == c)
		s++;
	if (!*s)
		return (0);
	while (*s && *s != c)
		s++;
	return (str_nb_elt_neq(s, c) + 1);
}

static char	**str_add_malloc_clild_neq(char **my_split, char const *s, char c)
{
	char const	*str_start;
	int			i;

	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (!*s)
			break ;
		str_start = s;
		while (*s != c && *s)
			s++;
		my_split[i++] = ft_substr(str_start, 0, s - str_start);
		if (!my_split[i - 1])
		{
			while (i)
				free(my_split[--i]);
			return (NULL);
		}
	}
	return (my_split);
}

char	**ft_split(char const *s, char c)
{
	char	**my_split;

	if (s == NULL)
		return (0);
	my_split = (char **)ft_calloc((str_nb_elt_neq(s, c) + 1), sizeof(char *));
	if (my_split == NULL)
		return (0);
	my_split = str_add_malloc_clild_neq(my_split, s, c);
	if (!my_split)
		free (NULL);
	return (my_split);
}
