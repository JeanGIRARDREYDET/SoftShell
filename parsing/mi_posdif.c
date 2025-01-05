/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mi_posdif.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard  <jegirard@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 11:38:34 by jegirard          #+#    #+#             */
/*   Updated: 2024/12/07 13:24:53 by jegirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"


void	mi_posdif(char *ln, int *s, int *i)
{

	while (ln && ln[*i] && ln[*i] != '\0' && ft_strchr(WSPACE, ln[*i]))
		(*i)++;
	
	*s = *i;
	if (ln && ln[*i] && ln[*i] != '\0' && (ln[*i] != '<' && ln[*i] != '>'))
	{
		while (ln && ln[*i] && ln[*i] != '\0'  && !ft_strchr(WSPACE, ln[*i]) 
		&& (ln[*i] != '<' && ln[*i] != '>'))
			(*i)++;
	}
	else if (ln && ln[*i] && ln[*i] != '\0'  && !ft_strchr(WSPACE, ln[*i]) 
	&& (ln[*i] == '<' || ln[*i] == '>'))
		{
			while (ln && ln[*i] && ln[*i] == ln[*s])
				(*i)++;
		}
}
