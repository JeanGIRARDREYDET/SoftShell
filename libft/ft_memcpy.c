/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard  <jegirard@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 19:31:05 by jegirard          #+#    #+#             */
/*   Updated: 2024/12/07 13:24:53 by jegirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
Description :
				La fonction memcpy() copie n octets depuis la zone mémoire src
				vers la zone mémoire dest. Les deux zones ne doivent pas se 
				chevaucher.
				Si c’est le cas, utilisez plutôt memmove(3).
Name :
				La  fonction memcpy() copie n octets depuis la zone mémoire src
				vers la zone mémoire dest. Les deux zones ne doivent pas se 
				chevaucher.
				Si c’est le cas, utilisez plutôt memmove(3).
Prototype :
				void *memcpy(void dest[restrict .n], const void 
				src[restrict .n], size_t n);
Paramètres :
				dest 
				src

Retour :
				desc
*/

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*p;

	if (!(dest || src))
		return (0);
	p = (char *)dest;
	while (dest != NULL && 0 < n--)
		*(unsigned char *)dest++ = *(unsigned char *)src++;
	return ((void *)p);
}
