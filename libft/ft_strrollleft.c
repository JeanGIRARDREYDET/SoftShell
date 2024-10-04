/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrollleft.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 18:11:48 by jegirard          #+#    #+#             */
/*   Updated: 2024/10/04 18:11:51 by jegirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_strrollleft(char *str)
{
	int			i;
	char		c;

	i = 0;
	c = str[0];
	if (!str[0] || !str[1])
		return ;
	while (str[i +1])
	{
		str[i] = str[i + 1];
		i++;
	}
	str[i] = c;
}