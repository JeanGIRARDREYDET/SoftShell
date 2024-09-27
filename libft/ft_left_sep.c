/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_left_sep.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 17:12:51 by jegirard          #+#    #+#             */
/*   Updated: 2024/09/18 17:13:04 by jegirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../minishell.h"

char	*ft_left_sep(char *src, const char *c)
{
	size_t	i;
	char	*p;

	p = ft_strdup(src);
	i = 0;
	while (p[i] != '\0' && !ft_strchr(c, *p))
	{
		i++;
	}
	p[i] = '\0';
	return (p);
}
