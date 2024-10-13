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

char	**ft_split2(char const *s, char c)
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


static int	count_words(const char *str, char c)
{
	int i;
	int trigger;

	i = 0;
	trigger = 0;
	while (*str)
	{
		if (*str != c && trigger == 0)
		{
			trigger = 1;
			i++;
		}
		else if (*str == c)
			trigger = 0;
		str++;
	}
	return (i);
}

static char	*word_dup(const char *str, int start, int finish)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((finish - start + 1) * sizeof(char));
	while (start < finish)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

char		**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	int		index;
	char	**split;

	if (!s || !(split = malloc((count_words(s, c) + 1) * sizeof(char *))))
		return (0);
	i = 0;
	j = 0;
	index = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == ft_strlen(s)) && index >= 0)
		{
			split[j++] = word_dup(s, index, i);
			index = -1;
		}
		i++;
	}
	split[j] = 0;
	return (split);
}
