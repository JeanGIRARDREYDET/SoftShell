/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cnt_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 18:10:56 by jegirard          #+#    #+#             */
/*   Updated: 2024/10/04 18:11:00 by jegirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_cnt_arg(char *ln, int *i, int *n)
{
	ft_pos_passspace(ln, i);
	ft_pos_passstring(ln, i);
	(*n)++;
	if (ln[*i])
		ft_cnt_arg(ln, i, n);
}
