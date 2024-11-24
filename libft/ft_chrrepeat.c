/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chrrepeat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 10:19:35 by jegirard          #+#    #+#             */
/*   Updated: 2024/11/24 10:20:02 by jegirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_chrrepeat(char c, int n)
{
	char	*str;
	int		i;

	i = 0;
	str = ft_calloc (n + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	while (i < n)
	{
		str[i] = c;
		i++;
	}
	str[i] = '\0';
	return (str);
}
