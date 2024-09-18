/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 09:27:23 by jegirard          #+#    #+#             */
/*   Updated: 2023/11/07 09:27:27 by jegirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
Name :
			ft_strlcat
Description :
			La fonction ft_strlcat() concaténent jusqu'à la taille - 1 
			caractères de la chaîne src terminée par NUL vers dst, terminant
			le résultat par NUL.
			Notez qu'un octet pour le NUL doit être dans inclus dans la taille.
			Notez également que strlcpy() ne fonctionnent que sur de vraies
			chaînes «C».
			Cela signifie que pour strlcpy() src doit être terminé par NUL et
			pour strlcat(), src et dst doivent être terminés par NUL.
Prototype :
			size_t strlcat(char *dst , const char *src , size_t size);
Paramètres :
			dest : la chaîne de destination, où le résultat de la 
					concaténation sera stocké.
			src  : la chaîne source qui sera concaténée à la fin de dest.
			size : la taille totale de la mémoire allouée pour dest.
Retour :
			si la taille est zero.
			si la taille est si la taille supereiur la position du /0 dans dest 
			dans dst on fait la copie
			taille est Longeur total de la chaine copiee
*/

static void	ft_cat_run(char *dst, const char *src, size_t dstsize, size_t len)
{
	size_t	i;

	i = 0;
	while (len < (dstsize - 1) && src[i] != '\0')
	{
		dst[len] = src[i];
		i++;
		len++;
	}
	dst[len] = '\0';
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dest_len;	
	size_t	src_len;

	if ((!dst) && dstsize == 0)
		return (0);
	dest_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dstsize == 0)
		return (src_len);
	if (dstsize > dest_len)
	{
		ft_cat_run(dst, src, dstsize, dest_len);
		return (src_len + dest_len);
	}
	else
		return (dstsize + src_len);
}
