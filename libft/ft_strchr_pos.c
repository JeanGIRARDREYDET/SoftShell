/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_pos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 09:27:41 by jegirard          #+#    #+#             */
/*   Updated: 2023/11/07 09:27:44 by jegirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Name :
			ft_strchr_pos
Description :
			recherche la première occurrence du caractère passé en second
			paramètre dans la chaîne de caractères spécifiée via le premier
			paramètre.
Prototype :
			size_t ft_strchr_pos(char *source ,int find);
Paramètres :

Retour :
			Soit le caractère recherché est présent dans la chaîne et, dans 
			ce cas, la position du caractere sera retourné.
			Soit le caractère n'est pas présent dans la chaîne et dans ce 
			cas, NULL vous sera renvoyé.
*/

#include <stddef.h>

size_t	ft_strchr_pos(const char *source, int find)
{
	int	i;

	if (source == NULL)
		return (0);
	i = 0;
	while (source[i] && source[i] != find)
		i++;
	return (i);
}
