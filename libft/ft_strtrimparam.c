/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrimparam.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard  <jegirard@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 19:31:05 by jegirard          #+#    #+#             */
/*   Updated: 2024/12/07 13:24:53 by jegirard         ###   ########.fr       */
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
			debut : dans la chaine a traiter 
			fin : dans la chaine a traiter 

Retour :
			La chaîne de caractères trimmée.
			NULL si l’allocation échoue
*/

char	*ft_strtrimparamwhile(char const *s1, int debut, int fin)
{
	char	*p;
	int		i;
	int		len;

	len = fin - debut +2;
	if (len == 1)
		return (NULL);
	p = (char *) ft_calloc (len, sizeof(char));
	if (!p)
		return (NULL);
	i = 0;
	while (debut + i <= fin)
	{
		p[i] = s1[debut + i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

char	*ft_strtrimparam(char const *s1, int debut, int fin, char const *set)
{
	if (!s1 || !set || !fin || fin <= debut)
		return (NULL);
	while (ft_strchr (set, s1[debut]) && s1[debut] != '\0')
		debut++;
	if (s1[fin] == '|')
		fin--;
	while (ft_strchr(set, s1[fin]) && fin >= debut && s1[fin] != '\0')
		fin--;
	return (ft_strtrimparamwhile(s1, debut, fin));
}
