/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_subchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard  <jegirard@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 19:49:29 by jegirard          #+#    #+#             */
/*   Updated: 2024/12/07 13:24:53 by jegirard         ###   ########.fr       */
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
