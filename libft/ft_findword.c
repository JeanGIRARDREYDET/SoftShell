/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findword.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:35:05 by jegirard          #+#    #+#             */
/*   Updated: 2024/10/14 11:35:09 by jegirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

bool	ft_findword(const char *source, const char *find)
{
	char		*p;
	size_t		i;
	size_t		offset;
	size_t		lenfind;

	lenfind = ft_strlen(find);
	if (*find == '\0' || find == NULL)
		return (false);
	i = 0;
	p = (char *)source;
	while ((i < lenfind) && (*p != '\0'))
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
