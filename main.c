/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 17:29:03 by jegirard          #+#    #+#             */
/*   Updated: 2024/11/02 17:29:09 by jegirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"



void	mi_cmd_acc(t_cmd *mi_cmd, t_sys *mi_sys)
{
	char		*cmd;
	char		**paths;
	int			i;
	char		*error_msg;

	i = 0;
	if (access(mi_cmd->cmd, F_OK) == 0)
		return ;
	i = 0;
	cmd = join_3(mi_getenv("PWD", mi_sys), "/", mi_cmd->cmd);
	if (access(mi_cmd->cmd, F_OK) == 0)
		return ;
	paths = ft_split (mi_getenv("PATH", mi_sys), ':');
	while (paths && paths[++i])
	{
		cmd = join_3(paths[i], "/", mi_cmd->cmd);
		if (access(cmd, F_OK) == 0)
		{
			mi_cmd->cmd = cmd;
			free(paths);
			return ;
		}
		free(cmd);
	}
	error_msg = join_3 ("minishell: ", mi_cmd->cmd, ": command not found\n");
//	mi_logerrorcmd(126, error_msg, mi_sys);
	free(cmd);
	free(paths);
	free(mi_cmd->cmd);
	return ;
}

void mi_checkline(char *line, t_sys *mi_sys)
{
	if (ft_findword("exit", line))
		builtin_exit(mi_sys);
}

void mi_checkmsargument(int argc, char **argv)
{
	if (argc > 1)
	{
		printf("Error: minishell does not take arguments. Try: ./%s\n", argv[0]);
		exit(0);
	}
}

int	main(int argc, char **argv, char **env)
{
	char	*line;
	t_sys	mi_sys;
	t_cmd	*mi_cmd;

	mi_checkmsargument(argc, argv);
	mi_sysinitialization(env, &mi_sys);
	while (1)
	{
		signal(SIGINT, &signal_handle_sigint);
		line = readline ("minishell> ");
		if (line)
			add_history(line);
		else
			break ;
		while (*line != '\0' && ft_strrchr(WSPACE, *line) != NULL)
			line++;
		if (*line == '\0')
			continue ;
		mi_checkline(line, &mi_sys);
		mi_sys.nb_pipe = 0;
		mi_cmd = mi_createcmd (&mi_sys);
		mi_lexingline (line, 0, mi_cmd, &mi_sys);
		mi_sys.cmd = mi_cmd;
		mi_syscmditer (&mi_sys, &mi_expand_interface);
		mi_syscmditer (&mi_sys, &mi_cmdsplitcmd);
		mi_cmditer (mi_cmd, &mi_cmdparsse);
		mi_cmditer (mi_cmd, &mi_checkbuiltin);
		mi_syscmditer (&mi_sys, &mi_checkpathaccess);
		mi_syscmditer (&mi_sys, &mi_execone);
		mi_waitingpipe (&mi_sys);
		mi_freecmd(mi_cmd, &mi_sys);
	//  mi_cmditer (&mi_cmd, &mi_cmdherdoc);

		
	}
}
