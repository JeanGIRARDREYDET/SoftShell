/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard  <jegirard@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 10:41:04 by jegirard          #+#    #+#             */
/*   Updated: 2024/12/07 13:24:53 by jegirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
Name :
			ft_strlcpy
Description :
			La fonction strlcpy() copie jusqu'à la taille - 1 caractères de la
			chaîne src terminée par NUL vers dst, terminant le résultat par NUL.
			Notez qu'un octet pour le NUL doit être dans inclus dans la taille.
			Notez également que strlcpy() ne fonctionnent que sur de vraies
			chaînes «C».
			Cela signifie que pour strlcpy() src doit être terminé par NUL et
			pour strlcat(), src et dst doivent être terminés par NUL.
Prototype :
		 	size_t strlcpy(char *dst , const char *src , size_t size);
Paramètres :

Retour :
		Longeur total de la chaine copiee
*/

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	unsigned int	i;

	i = 0;
	if (size > 0)
	{
		while (i < (size -1) && src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}
