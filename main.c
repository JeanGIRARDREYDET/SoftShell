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

void	mi_analyse(char *line, t_sys *mi_sys)
{
	mi_lexingline(mi_sys);
	mi_checksyntax(line, mi_sys);
	if (mi_sys->error)
		return ;
	mi_cmditer(mi_sys, &mi_cmdsplitcmd);
	mi_syscmditer(mi_sys, &mi_cmdparsse);
	mi_sysrediter(mi_sys, HEREDOC, &mi_heredoc);
	mi_cmditer(mi_sys, &mi_checkbuiltin);
	mi_syscmditer(mi_sys, &mi_checkpathaccess);
	mi_syscmditer(mi_sys, &mi_execone);
	mi_syscmditer(mi_sys, &mi_waitingcmdipe);
	mi_waitingpipe(mi_sys);
}

int	main(int argc, char **argv, char **env)
{
	t_sys			mi_sys;

	mi_sysinitialization(env, &mi_sys, argc, argv);
	while (1)
	{
		init_signal();
		mi_prompt(&mi_sys);
		add_history(mi_sys.input);
		while (*mi_sys.input != '\0'
			&& ft_strrchr(WSPACE, *mi_sys.input) != NULL)
			mi_sys.input++;
		if (g_signal == SIGINT)
			mi_sys.code_error = 130;
		mi_analyse(mi_sys.input, &mi_sys);
		mi_freecmd(&mi_sys);
		free(mi_sys.input);
		g_signal = 0;
	}
}
