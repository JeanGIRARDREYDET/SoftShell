/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard  <jegirard@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 19:44:12 by jegirard          #+#    #+#             */
/*   Updated: 2024/12/07 13:24:53 by jegirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// intercepter les signaux :
// CTRL+D = quitte le programme et ecrit "exit"
//  => dans le cas d'une commande blocante comme cat | ls
//  => coupe la boucle infinie et retour au prompt
// CTRL+C = SIGINT
// CTRL+\ = SIGQUIT
// utiliser qu'une seule variable globale
// int is_control_c(int g_signal)
// => si le signal == SIGINT return (1);
// => sinon return (0);

// int is_control_backslash(int status);
// => si le signal est SIGQUIT return (1);
// => sinon return (0);

// int handle_signal_interrupt(int status, int is_last_child);
// si ctrl+c est appuye, print new line
// if (is_control_c(status))
//     ft_putstr_fd("\n", STDOUT_FILENO);

// si ctrl+\ appuye et que c le dernier enfant print "Quit\n";
// if (is_control_backslash(status))
//     ft_putchar_fd("Quit\n", STDOUT_FILENO);

// return the interrupt signal
// return(INTERRUPT + WTERMSIG(status))

// #define INTERRUPT ou const int
// errmsg.h
// #define INTERRUPT 130

// int wait_for_child(int child_pid, int is_last_child);
// if(child_pid == FORK_ERROR)
//     return(EXIT_FAILURE);

// wait for the child process to finish
// if(waitpid(child_pid, &status, 0) == -1)
//     perror("waitpid");

// fonction qui attend que tous les processus enfants finissent
// int wait_for_children(int children_pid[1024])
// while (children_pid[0] != 0)
// is_last_children = (children_pid[i + 1] == 0);
// exit_status = wait_for_child(children_pid[i], is_last_child);
// clean_after_execute(children_pid); // free
// return(exit_status);

int	g_signal = 0;

void	signal_handle_sigint(int sign)
{
	(void)sign;
	printf("\n");
	rl_replace_line("", 0);
	rl_on_new_line();
	if (g_signal == 0)
		rl_redisplay();
}

void	signal_handle_sigquit(void)
{
	printf("'^\'");
	rl_on_new_line();
	if (g_signal == 0)
		return ;
}

void	signal_in_heredoc(int signal)
{
	g_signal = signal;
	close(STDIN_FILENO);
}
