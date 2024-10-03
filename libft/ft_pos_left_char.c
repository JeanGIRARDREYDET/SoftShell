/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pos_left_char.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 11:47:31 by jegirard          #+#    #+#             */
/*   Updated: 2024/09/27 11:47:36 by jegirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_pos_left_char(char *s, char c)
{
	int		i;

	i = 0;
	while (s[i] && s[i] != '\0' && s[i] != c)
		i++;
	return (i);
}
int	ft_pos_left_chars(char *s, char *c)
{
	int		i;

	i = 0;
	while (s[i] && s[i] != '\0' && !ft_strchr(c, (int)(s[i])))
		i++;
	return (i);
}
