/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_subchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:34:07 by jegirard          #+#    #+#             */
/*   Updated: 2024/11/04 12:34:12 by jegirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Suprime les caractères c de la chaine s ne realloc pas la chaine

#include "../minishell.h"

void	ft_subchar(char *s, char c)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s || !s[0] || !c || c == '\0' || s == NULL)
		return ;
	while (s[i] && s[i] != '\0')
	{
		s[j] = s[i];
		if (s[j] != c)
			j++;
		i++;
	}
	s[j] = '\0';
}

void	ft_subchars(char *str, char *chars)
{
	int	i;

	i = 0;
	while (chars[i])
	{
		ft_subchar(str, chars[i]);
		i++;
	}
	i++;
}
