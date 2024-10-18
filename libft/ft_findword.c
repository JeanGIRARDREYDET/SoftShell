/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findword.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard <jegirard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:35:05 by jegirard          #+#    #+#             */
/*   Updated: 2024/10/14 20:00:04 by jegirard         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../minishell.h"

bool	ft_findword(const char *source, const char *find)
{
	char		*p;
	size_t		i;
	size_t		offset;
	size_t		lenfind;
	size_t		lensource;

	if (find == NULL || source == NULL || source[0] == '\0' || find[0] == '\0')
		return (false);
	lenfind = ft_strlen(find);
	lensource = ft_strlen(source);
	if (*find == '\0' || find == NULL)
		return (false);
	i = 0;
	p = (char *)source;
	while ((i < lensource) && (*p != '\0'))
	{
		offset = 0;
		while (find[offset] == p[offset] && offset < lenfind - i + 1)
		{
			offset++;
			if (p[offset] == ' ' && find[offset] == '\0')
				return (true);
		}
		p++;
		i++;
	}
	return (false);
}
