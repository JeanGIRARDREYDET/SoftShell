/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 09:25:56 by jegirard          #+#    #+#             */
/*   Updated: 2023/11/07 09:26:03 by jegirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
Description :
			The memset() function fills the first n bytes of the memory area
			pointed to 

Prototype :
				void	*ft_memset(void *s, int c, size_t n)
Paramètres :

Retour :		 The memset() function returns a pointer to the memory area s
*/

void	*ft_memset(void *s, int c, size_t n)
{
	char	*p;

	p = (char *)s;
	while (0 < n--)
		p[n] = c ;
	return (p);
}
