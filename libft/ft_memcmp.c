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
			The memcmp() function compares the first n bytes (each interpreted
			as unsigned char) of the memory areas s1 and s2.

Prototype :
			int	ft_memcmp(const void *s1, const void *s2, size_t n)
Paramètres :

Retour :
			The memcmp() function returns an integer less than, equal to, or
			greater than zero 
			if the first  n bytes of s1 is found, respectively, to be less than,
			to match, or be greater than the first n bytes of s2.

			For a nonzero return value, the sign is determined by the sign of the 
			difference between thef irst pair of bytes (interpreted as unsigned
			char) that differ in s1 and s2.

			If n is zero, the return value is zero.
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
