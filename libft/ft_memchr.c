/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard  <jegirard@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 10:41:04 by jegirard          #+#    #+#             */
/*   Updated: 2024/12/07 13:24:53 by jegirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
Description :
				scans les n octets initiaux de la zone mémoire pointée par s 
				pour la première instance de c . C et les octets de la zone 
				mémoire pointés par s sont interprétés comme unsigned char.
Name :
				ft_memchr
Prototype :
				void	*ft_memchr(const void *s, int c, size_t n)
Paramètres :
				s : 
				c : 
				n : 
Retour :
				pointeur vers l'octet correspondant ou NULL si le caractère 
				n'apparaît pas dans la zone mémoire donnée
*/

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*p;
	size_t			i;

	i = 0;
	p = (unsigned char *)s;
	while (i < n && p[i] != (unsigned char)c)
		i++;
	if (n == i)
		return (NULL);
	return ((void *)p + i);
}
