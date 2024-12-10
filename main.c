/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard  <jegirard@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 11:38:34 by jegirard          #+#    #+#             */
/*   Updated: 2024/12/07 13:24:53 by jegirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	mi_checkline(char *line, t_sys *mi_sys)
{
	if (ft_findword("exit", line))
		builtin_exit(mi_sys);
}

void	mi_checkmsargument(int argc, char **argv)
{
	if (argc > 1)
	{
		printf("Error: minishell does not take arguments. Try: ./%s\n",
			argv[0]);
		exit(0);
	}
}

void	mi_analyse(char *line, t_sys *mi_sys)
{
	mi_checkline(line, mi_sys);
	mi_lexingline(line, mi_sys);
	mi_syscmditer(mi_sys, &mi_expand_interface);
	mi_cmditer(mi_sys, &mi_cmdsplitcmd);
	mi_syscmditer(mi_sys, &mi_cmdparsse);
	mi_sysrediter(mi_sys, HEREDOC, &mi_heredoc);
	mi_cmditer(mi_sys, &mi_checkbuiltin);
	mi_syscmditer(mi_sys, &mi_checkpathaccess);
}

int	main(int argc, char **argv, char **env)
{
	char			*line;
	t_sys			mi_sys;

	mi_checkmsargument(argc, argv);
	mi_sysinitialization(env, &mi_sys);
	while (1)
	{
		signal(SIGINT, &signal_handle_sigint);
		line = readline("minishell> ");
		if (line && *line == '\0')
			continue ;
		else if (line)
			add_history(line);
		else if (!line)
			builtin_exit(&mi_sys);
		while (*line != '\0' && ft_strrchr(WSPACE, *line) != NULL)
			line++;
		mi_analyse(line, &mi_sys);
		mi_syscmditer(&mi_sys, &mi_execone);
		mi_waitingpipe(&mi_sys);
		mi_freecmd(&mi_sys);
	}
}
