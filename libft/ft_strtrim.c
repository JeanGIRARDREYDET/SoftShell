/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norminey.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 09:44:29 by jegirard          #+#    #+#             */
/*   Updated: 2023/11/15 09:44:33 by jegirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
Description :
			Alloue (avec malloc(3)) et retourne une copie de la chaîne ’s1’,
			sans les caractères spécifiés dans ’set’ au début et à la fin de la
			chaîne de caractères.


Prototype :
			*ft_strtrim(char const *s1, char const *set)
{

Paramètres :
			s1: La chaîne de caractères à trimmer.
			set: Le set de référence de caractères à trimmer.

Retour :
			La chaîne de caractères trimmée.
			NULL si l’allocation échoue
*/

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*p;
	int		debut;
	int		i;
	int		fin;

	if (!(s1 && set))
		return (0);
	debut = 0;
	while (ft_strchr (set, s1[debut]) && s1[debut] != '\0')
		debut++;
	fin = debut;
	while (s1[fin] != '\0')
		fin++;
	while (ft_strchr(set, s1[fin]) && fin >= debut)
		fin--;
	p = (char *) ft_calloc ((fin - debut + 2), sizeof(char));
	if (!p)
		return (NULL);
	i = 0;
	while (debut <= fin)
		p[i++] = s1[debut++];
	p[i] = 0;
	return (p);
}
