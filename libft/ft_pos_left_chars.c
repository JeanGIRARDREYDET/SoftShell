/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pos_left_chars.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:15:34 by jegirard          #+#    #+#             */
/*   Updated: 2024/10/14 11:15:40 by jegirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_pos_left_chars(char *s, char *c)
{
	int		i;

	i = 0;
	while (s[i] && s[i] != '\0' && !ft_strchr(c, (int)(s[i])))
		i++;
	return (i);
}
