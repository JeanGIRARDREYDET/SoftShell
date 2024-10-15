/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cnt_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard <jegirard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 18:10:56 by jegirard          #+#    #+#             */
/*   Updated: 2024/10/14 19:54:52 by jegirard         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../minishell.h"

void	ft_pos_redir(char *ln, int *i)
{
	while (ln && ln[*i] && (ln[*i] == '<' || ln[*i] == '>'))
		(*i)++;
}


void	ft_cnt_arg(char *ln, int *i, int *n)
{
	if (ln == NULL)
		return ;
	ft_pos_redir(ln, i);
	ft_pos_passspace(ln, i);
	ft_pos_passstring(ln, i);
	(*n)++;
	if (ln[*i])
		ft_cnt_arg(ln, i, n);
}
