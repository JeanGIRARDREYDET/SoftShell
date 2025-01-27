/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doferet <doferet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 19:44:12 by jegirard          #+#    #+#             */
/*   Updated: 2025/01/17 16:08:39 by doferet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	g_signal = 0;

void	signal_handle_sigint(int sign)
{
	(void)sign;
	write(2, "\n", 1);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
	g_signal = SIGINT;
}

void	signal_handle_sigint_cat(int sign)
{
	(void)sign;
	write(2, "\n", 1);
	rl_replace_line("", 0);
	rl_on_new_line();
	g_signal = SIGINT;
}

void	signal_handle_sigquit(int sign)
{
	(void)sign;
	write(2, "Quit (core dumped)\n", 19);
	g_signal = SIGQUIT;
}

void	init_signal(void)
{
	signal(SIGINT, &signal_handle_sigint);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGTERM, SIG_IGN);
	signal(SIGTSTP, SIG_IGN);
}

int	sigint_heredoc(void)
{
	return (0);
}

void	signal_in_heredoc(int signal)
{
	g_signal = signal;
	rl_done = 1;
}
