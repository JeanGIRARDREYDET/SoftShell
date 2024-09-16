/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 09:27:41 by jegirard          #+#    #+#             */
/*   Updated: 2023/11/07 09:27:44 by jegirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Name :
			ft_strlcat
Description :
			recherche la première occurrence du caractère passé en second
			paramètre dans la chaîne de caractères spécifiée via le premier
			paramètre.
Prototype :
			size_t strlcat(char *dst , const char *src , size_t size);
Paramètres :

Retour :
			Soit le caractère recherché est présent dans la chaîne et, dans 
			ce cas, un pointeur sur la première occurrence du caractère vous
			sera retourné.
			Soit le caractère n'est pas présent dans la chaîne et dans ce 
			cas, le pointeur NULL vous sera renvoyé.
*/

#include <stddef.h>

char	*ft_strchr(const char *source, int find)
{
	char	*p;

	p = (char *)source;
	while (*p && *p != (char unsigned)find)
		p++;
	if (*p == '\0' && find != 0)
		return (NULL);
	else
		return (p);
}
