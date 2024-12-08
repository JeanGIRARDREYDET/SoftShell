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

void	ft_pos_redir(char *ln, int *i)
{
	while (ln && ln[*i] && (ln[*i] == '<' || ln[*i] == '>'))
		(*i)++;
}

void	ft_cnt_arg(char *ln, int *i, int *n)
{
	int			s;

	if (ln == NULL)
		return ;
	ft_pos_passspace(ln, i);
	s = *i;
	ft_pos_redir(ln, i);
	if (s == *i)
		ft_pos_passstring(ln, i);
	(*n)++;
	if (ln && ln[*i])
		ft_cnt_arg(ln, i, n);
}
