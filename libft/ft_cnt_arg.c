/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cnt_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard  <jegirard@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 19:31:05 by jegirard          #+#    #+#             */
/*   Updated: 2024/12/07 13:24:53 by jegirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_posredir(char *ln, int *i)
{
	int	s;

	s = *i;
	if (ln && ln[*i] && (ln[*i] != '<' && ln[*i] != '>'))
	{
		while (ln && ln[*i] && (ln[*i] != '<' && ln[*i] != '>'))
			(*i)++;
	}
	else if (ln && ln[*i] && (ln[*i] == '<' || ln[*i] == '>'))
	{
		while (ln && ln[*i] && ln[*i] == ln[s])
			(*i)++;
	}
}

void	ft_cnt_arg(char *ln, int *n)
{
	if (ln == NULL)
		return ;
	ft_posnospace(ln, &(n[1]));
	ft_posredir(ln, &(n[2]));
	if (n[1] < n[2])
		ft_posnostring(ln, &(n[1]));
	else
		ft_posnostring(ln, &(n[2]));
	(n[0])++;
	if (ln && ln[n[0]])
		ft_cnt_arg(ln, n);
}
