/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findcommand.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:38:49 by jegirard          #+#    #+#             */
/*   Updated: 2024/10/14 11:38:52 by jegirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_findcommand(char *line)
{
	int			i;
	int			c1;
	int			c2;

	i = 0;
	while (line[i] < 33)
		i++;
	c1 = i;
	while (line[i] > 32)
		i++;
	c2 = i;
	while (line[i] < 33)
		i++;
	return (ft_substr(line, c1, (c2 - c1)));
}
