/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_param.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 15:57:54 by jegirard          #+#    #+#             */
/*   Updated: 2024/09/27 15:57:59 by jegirard         ###   ########.fr       */
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

char	*ft_strtrim_param(char const *s1, int debut, int fin, char const *set)
{
	char	*p;
	int		i;

	if (!(s1 && set && fin))
		return (0);
	while (ft_strchr (set, s1[debut]) && s1[debut] != '\0')
		debut++;
	while (ft_strchr(set, s1[fin]) && fin >= debut)
		fin--;
	p = (char *) ft_calloc ((fin - debut + 2), sizeof(char));
	printf("size de p =  %d\n", fin - debut + 2);
	if (!p)
		return (NULL);
	i = 0;
	while (debut <= fin)
		p[i++] = s1[debut++];
	p[i] = 0;
	printf("strtrim param = %p et %s\n", p, p);
	return (p);
}
