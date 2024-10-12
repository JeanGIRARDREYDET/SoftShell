/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 09:27:50 by jegirard          #+#    #+#             */
/*   Updated: 2023/11/07 09:27:54 by jegirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

/*
Description : compare les npremier caracteres dees chaines	

Name :			

Prototype : 	

Paramètres : string 1 string 2 Nobre de caractere a comparer

Retour :		
*/

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	if (n <= 0 || !s1 || !s2)
		return (0);
	while (((s1[i] || s2[i]) && i < n - 1) && s1[i] == s2[i])
		i++;
	return ((unsigned char)(s1[i]) - (unsigned char)(s2[i]));
}
