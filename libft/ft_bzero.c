/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 09:26:05 by jegirard          #+#    #+#             */
/*   Updated: 2023/11/07 09:26:09 by jegirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  <unistd.h>

/*
Description :
			La fonction bzero() met à 0 les n premiers octets du bloc pointé
			par s (octets contenant « \0 »).	
Prototype :
			void	ft_bzero(void *source, size_t n)
Paramètres :
*/

void	ft_bzero(void *source, size_t n)
{
	char	*p;

	p = (char *)source;
	while (0 < n--)
		p[n] = 0 ;
	return ;
}
