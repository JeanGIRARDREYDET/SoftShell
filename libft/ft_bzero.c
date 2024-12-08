/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard <jegirard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 10:41:04 by jegirard          #+#    #+#             */
/*   Updated: 2024/12/08 18:47:37 by jegirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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
