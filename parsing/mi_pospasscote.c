/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mi_pospasscote.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 18:37:57 by jegirard          #+#    #+#             */
/*   Updated: 2024/10/04 18:38:00 by jegirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		mi_pospasscote( char *ln, int i, t_error *mi_error)
{
	char	echap;

	while (ln[i] && ln[i] != '\'' && ln[i] != '"' && ln[i] != 0 && ln[i] != '|')
		i++;
	if (ft_strin(TECHAP, ln[i]))
	{
		echap = ln[i];
		i++;
		i += ft_pos_left_char ((ln + i), echap);
		if (ln[i] == echap)
			i++;
		else
			mi_logpipeerror(130, "erreur de quot", mi_error);
	}
	return (i);
}
