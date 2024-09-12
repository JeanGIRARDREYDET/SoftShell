/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 09:45:14 by jegirard          #+#    #+#             */
/*   Updated: 2023/11/15 09:45:29 by jegirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Description :	Alloue (avec malloc(3)) et retourne une chaîne de caractères
				issue de la chaîne ’s’.
				Cette nouvelle chaîne commence à l’index ’start’ 
				et a pour taille maximale ’len’.

Name :			ft_itoa

Prototype : 	char *ft_itoa(int n);

Paramètres :	n : L’entier à convertir.

Retour :		La chaîne de caractères représentant l’entier.
				NULL si l’allocation échoue.

Autorisées : 	malloc
*/

#include "../minishell.h"

static int	ft_itoa_len(int n)
{
	if (n != 0)
		return (1 + ft_itoa_len(n / 10));
	else
		return (0);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	long	number;

	number = n;
	len = 0;
	if (number <= 0)
	{
		number = -number;
		len++;
	}
	len = len + ft_itoa_len(number);
	str = (char *) ft_calloc ((len + 1), sizeof(char));
	if (!str)
		return (NULL);
	while (--len >= 0)
	{
		str[len] = '0' + number % 10;
		number = number / 10;
	}
	if (0 > n)
		str[0] = '-';
	return (str);
}
