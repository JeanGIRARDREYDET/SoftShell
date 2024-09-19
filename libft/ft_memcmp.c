/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 09:19:50 by jegirard          #+#    #+#             */
/*   Updated: 2023/11/07 09:19:52 by jegirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
Description :
			La fonction memcmp() compare les n premiers octets (chacun 
			interprété comme un interprétés comme des caractères non signés) des
			zones de mémoire s1 et s2.

Prototype :
			int ft_memcmp(const void *s1, const void *s2, size_t n)
Paramètres :

Retour :
			La fonction memcmp() renvoie un entier inférieur, égal ou supérieur
			à zéro.
			supérieur à zéro 
			si les n premiers octets de s1 sont respectivement inférieurs à,
			égal ou supérieur aux n premiers octets de s2.

			Pour une valeur de retour non nulle, le signe est déterminé par le
			signe de la différence entre la première paire d'octets de s1 et la
			première paire d'octets de s2. 
			différence entre la première paire d'octets (interprétés comme des
			caractères non signés) qui diffèrent dans s1 et s2.
			char non signés) qui diffèrent dans s1 et s2.

			Si n est nul, la valeur de retour est nulle.
*/

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0 ;
	while (i++ != n)
		if (*(unsigned char *)s1++ - *(unsigned char *)s2++)
			return (*(unsigned char *)--s1 - *(unsigned char *)--s2);
	return (0);
}
