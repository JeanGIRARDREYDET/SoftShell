/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sigint_heredoc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doferet <doferet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 19:44:12 by jegirard          #+#    #+#             */
/*   Updated: 2025/01/17 16:08:39 by doferet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	sigint_heredoc(void)
{
	return (0);
}

void	signal_in_heredoc(int signal)
{
	g_signal = signal;
	rl_done = 1;
}
