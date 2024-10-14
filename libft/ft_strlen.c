/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 09:25:48 by jegirard          #+#    #+#             */
/*   Updated: 2023/11/07 09:25:54 by jegirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Description :	The strlen() function calculates the length of the string pointed
				to by s, excluding the terminating null byte ('\0').

Prototype : 	

Paramètres :

Retour :		The strlen() function returns the number of bytes in the string 
				pointed to by s
*/

#include "../minishell.h"

size_t	ft_strlen(char const *str)
{
	size_t	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
