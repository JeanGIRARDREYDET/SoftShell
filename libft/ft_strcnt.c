/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcnt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 09:25:48 by jegirard          #+#    #+#             */
/*   Updated: 2023/11/07 09:25:54 by jegirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
Description :	The strcnt() function count the number of the caracter is in
				the stringstring.

Prototype : 	

Paramètres :

Retour :		The strlen() function returns the number  ocurence in the string
*/

size_t	ft_strcnt(const char *s, const char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		i++;
		if (s[i] == c)
			j++;
	}
	return (j);
}
