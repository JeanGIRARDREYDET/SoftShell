/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 09:26:05 by jegirard          #+#    #+#             */
/*   Updated: 2023/11/07 09:26:09 by jegirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Description :
			La fonction strdup() renvoie un pointeur sur une nouvelle chaîne de 
			caractères qui est dupliquée depuis s.

			La mémoire occupée par cette nouvelle chaîne est obtenue en appelant
			malloc(3), et peut (et doit) donc être libérée avec free(3).

			La fonction strndup() est identique, mais ne copie au plus que
			n octets.
			Si s est plus grande que n, seuls n octets sont  copiés et l’octet
			NULL de fin (« \0 ») est ajouté.

Prototype :
			Char	*ft_strdup(const char *s)
Paramètres :
			char :
Retour :
			En cas de succès, la fonction strdup() renvoie un pointeur sur la
			chaîne dupliquée. NULL est renvoyé s’il n’y avait pas assez de
			mémoire et errno est défini pour indiquer l’erreur.
*/
#include "../minishell.h"

char	*ft_strdup(const char *s)
{
	char	*p;
	size_t	nmemb;

	nmemb = 1;
	while (s[nmemb - 1])
		nmemb ++;
	if (sizeof(char) != 0)
		if ((nmemb * sizeof (char)) / sizeof(char) != nmemb)
			return (NULL);
	p = (char *) malloc ((nmemb) * sizeof(char));
	if (!p)
		return (NULL);
	p[--nmemb] = '\0';
	while (0 < nmemb--)
		p[nmemb] = s[nmemb];
	return (p);
}





