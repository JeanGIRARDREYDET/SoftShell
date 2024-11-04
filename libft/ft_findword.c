/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findword.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard <jegirard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:35:05 by jegirard          #+#    #+#             */
/*   Updated: 2024/10/20 20:09:34 by jegirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

typedef struct s_findworlf
{
	size_t		i;
	size_t		lenfind;
	size_t		lensource;
}	t_findworlf;

bool	ft_findword(const char *source, const char *find)
{
	t_findworlf		fw;
	size_t			offset;
	char			*p;

	if (find == NULL || source == NULL || source[0] == '\0' || find[0] == '\0')
		return (false);
	fw.lenfind = ft_strlen(find);
	fw.lensource = ft_strlen(source);
	if (*find == '\0' || find == NULL)
		return (false);
	fw.i = 0;
	p = (char *)source;
	while ((fw.i < fw.lensource) && (*p != '\0'))
	{
		offset = 0;
		while (find[offset] == p[offset] && offset < fw.lenfind - fw.i + 1)
		{
			offset++;
			if ((p[offset] == ' ' || p[offset] == '\0') && find[offset] == '\0')
				return (true);
		}
		p++;
		fw.i++;
	}
	return (false);
}
