/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
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

Name :			

Prototype : 	

Paramètres :

Retour :
			A pointer to the last occurrence of the
*/

char	*ft_strrchr(const char *src, int find)
{
	char	*p;

	p = (char *)src;
	while (*p != '\0')
		p++;
	while (p != src && *p != (char unsigned)find)
		p--;
	if (*p == (char unsigned)find)
		return (p);
	else
		return (NULL);
}
