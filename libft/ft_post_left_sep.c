/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_post_left_sep.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 17:11:44 by jegirard          #+#    #+#             */
/*   Updated: 2024/09/18 17:12:01 by jegirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_post_left_sep(char *src, const char *c)
{
	char	*p;

	p = (char *)src;
	while (*p != '\0' && !ft_strchr(c, *p))
		p++;
	if (ft_strchr(c, *p))
		p++;
	return (p);
}
