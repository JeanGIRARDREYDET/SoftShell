/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 09:27:46 by jegirard          #+#    #+#             */
/*   Updated: 2023/11/07 09:27:49 by jegirard         ###   ########.fr       */
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
