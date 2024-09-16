/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 09:28:05 by jegirard          #+#    #+#             */
/*   Updated: 2023/11/07 09:28:09 by jegirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Description :
			La fonction strnstr() localise la première occurrence du chaîne 
			terminée par un caractère nul rechercher dans la source de la chaîne,
			où pas plus de len caractères sont recherchés.
			Les caractères qui apparaissent après un caractère « \0 » ne sont
			pas recherchés.
			Puisque la fonction strnstr() est une API spécifique à FreeBSD,
			elle devrait ne doit être utilisé que lorsque la portabilité n'est
			pas un problème.
Prototype :
			void ft_putendl_fd(char *s, int fd);

Paramètres :

Retour :
			- If find is an empty string, source is returned;
			- If find occurs nowhere in big, NULL is returned;
			- otherwise a pointer to the first character of
				the first occurrence of find is returned.
*/

#include <stddef.h>

char	*ft_strnstr(const char *source, const char *find, size_t len)
{
	char	*p;
	size_t	i;
	size_t	offset;

	if (*find == '\0' || find == NULL)
		return ((char *)source);
	i = 0;
	p = (char *)source;
	while ((i < len) && (*p != '\0'))
	{
		offset = 0;
		while (find[offset] == p[offset] && offset < len - i)
		{
			if (find[++offset] == '\0')
				return (p);
		}
		p++;
		i++;
	}
	return (NULL);
}
