/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doferet <doferet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 11:38:34 by jegirard          #+#    #+#             */
/*   Updated: 2025/01/17 16:09:47 by doferet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
	mi_lexingline(line, mi_sys);
	mi_cmditer(mi_sys, &mi_cmdsplitcmd);
	mi_syscmditer(mi_sys, &mi_cmdparsse);
	mi_sysrediter(mi_sys, HEREDOC, &mi_heredoc);
	mi_cmditer(mi_sys, &mi_checkbuiltin);
	mi_syscmditer(mi_sys, &mi_checkpathaccess);
	mi_syscmditer(mi_sys, &mi_execone);
	mi_syscmditer(mi_sys, &mi_waitingcmdipe);
}

int	main(int argc, char **argv, char **env)
{
	char			*line;
	t_sys			mi_sys;

	mi_checkmsargument(argc, argv);
	mi_sysinitialization(env, &mi_sys);
	while (1)
	{
		init_signal();
		line = readline("minishell> ");
		if (!line)
		{
			mi_freesys(&mi_sys);
			mi_freecmd(&mi_sys);
			ft_putstr_fd("exit\n", 1);
			exit(0);
		}
		else if (line)
			add_history(line);
		while (*line != '\0' && ft_strrchr(WSPACE, *line) != NULL)
			line++;
		mi_analyse(line, &mi_sys);
		mi_waitingpipe(&mi_sys);
		mi_freecmd(&mi_sys);
	}
}
