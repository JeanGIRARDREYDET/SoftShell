/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pos_passstring.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard <jegirard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 18:11:24 by jegirard          #+#    #+#             */
/*   Updated: 2024/12/05 23:38:20 by jegirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_pos_passstring(char *ln, int *i)
{
	char	echap;
// && ln[*i] != '<' && ln[*i] != '>'
	echap = '\0';
	while (ln && ln[*i] != '\0'
		&& (!ft_strchr(WSPACE, ln[*i]) || echap != '\0'))
	{
		if ((echap == '\0') && ft_strchr(TECHAP, ln[*i]))
			echap = ft_strchr(TECHAP, ln[*i])[0];
		else if (ln[*i] == echap)
			echap = '\0';
		(*i)++;
	}
}
