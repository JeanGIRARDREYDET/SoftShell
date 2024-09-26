/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 08:53:37 by jegirard          #+#    #+#             */
/*   Updated: 2023/11/15 08:53:43 by jegirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
Description :	Alloue (avec malloc(3)) et retourne une chaîne de caractères
				issue de la chaîne ’s’.
				Cette nouvelle chaîne commence à l’index ’start’ et a pour taille
				maximale ’len’.

Name :			char *ft_substr(char const *s, unsigned int start, size_t len);

Prototype : 	

Paramètres :	s: La chaîne de laquelle extraire la nouvelle chaîne.
				start: L’index de début de la nouvelle chaîne dans
				la chaîne ’s’.
				len: La taille maximale de la nouvelle chaîne.

Retour :		La nouvelle chaîne de caractères.
					 NULL si l’allocation échoue.
*/

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	int		i;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (start > ft_strlen(s))
		len = 0;
	else if (ft_strlen(s) - start < len)
		len = ft_strlen(s) - start;
	p = (char *) ft_calloc ((len + 1), sizeof(char));
	if (!p)
		return (NULL);
	while (0 < len-- && s[start])
		p[i++] = s[start++];
	return (p);
}

char	*ft_strdupleft(char const *s, size_t len)
{
	return ft_substr(s, 0, len);
}
