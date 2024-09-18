/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 09:46:44 by jegirard          #+#    #+#             */
/*   Updated: 2023/11/15 09:48:57 by jegirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
Description :
			Applique la fonction ’f’ à chaque caractère de la chaîne de
			caractères transmise comme argument, et en passant son index comme
			premier argument.
			Chaque caractère est transmis par adresse à ’f’ afin d’être modifié
			si nécessaire.

Paramètres :
			s: La chaîne de caractères sur laquelle itérer.
			f: La fonction à appliquer à chaque caractère.

Valeur de retour : Aucune

Autorisées :
			Aucune
*/

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	i;

	if (! (s && f))
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
