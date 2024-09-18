/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 09:45:52 by jegirard          #+#    #+#             */
/*   Updated: 2023/11/15 09:46:00 by jegirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
Description : 	Applique la fonction ’f’ à chaque caractère de la chaîne de
				caractères passée en argument pour créer une nouvelle chaîne de
				caractères (avec 
				malloc(3)) résultant des applications successives de ’f’.
Paramètres :
				s: La chaîne de caractères sur laquelle itérer.
				f: La fonction à appliquer à chaque caractère.
Retour :	
				La chaîne de caractères résultant des applications 	successives
				de ’f’.
				Retourne NULL si l’allocation échoue.

Autorisées :
				malloc 
*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str_out;
	int		i;

	if (!s)
		return (NULL);
	i = ft_strlen(s);
	str_out = (char *) malloc (i + 1 * sizeof(char));
	if (!str_out)
		return (NULL);
	str_out[i] = '\0';
	while (i-- > 0)
		str_out[i] = f(i, s[i]);
	return (str_out);
}
