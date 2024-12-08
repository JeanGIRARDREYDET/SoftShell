/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard  <jegirard@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 19:31:05 by jegirard          #+#    #+#             */
/*   Updated: 2024/12/07 13:24:53 by jegirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

//#include <stdio.h>

/*
Description :	
			The memmove() function copies n bytes from memory area src to memory
			area dest.
			The memory areas may overlap: copying takes place as though the
			bytes in src are first copied into a temporary array that does not
			overlap src or dest, and the bytes are then copied from the 
			temporary array to dest.

Prototype :
			void	*ft_memmove(void *dest, const void *src, size_t n)

Paramètres :

Retour :
			The memmove() function returns a pointer to dest.
*/

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*p;

	if (!(dest || src))
		return (0);
	p = (char *)dest;
	if (dest > src)
	{
		dest = dest + n - 1;
		src = src + n - 1;
		while (0 < n--)
			*(unsigned char *)(dest--) = *(unsigned char *)(src--);
	}
	else
		while (p != NULL && 0 < n--)
			*(unsigned char *)p++ = *(unsigned char *)src++;
	return ((void *)p);
}
