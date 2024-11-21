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

void	mi_pospasscote(char *ln, size_t *pos, t_sys *mi_sys)
{
	char	echap;
	int		i;

	i = *pos;

	while (ln[i] && ln[i] != '\'' && ln[i] != '"' && ln[i] != '\0')
		i++;
	if (ft_strin(TECHAP, ln[i]))
	{
		echap = ln[i];
		i++;
		i += ft_pos_left_char ((ln + i), echap);
		if (ln[i] == echap)
			i++;
		else
			mi_logerror(130, "erreur de quot", mi_sys);
	}
	*pos = i;
}
