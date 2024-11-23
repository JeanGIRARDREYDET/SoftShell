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
	char	*cmd;
	char	**paths;
	int		i;

	i = 0;
	if (access(mi_cmd->args[0], F_OK) == 0)
		return ;

	cmd = join_3(mi_getenv("PWD", mi_sys), "/", mi_cmd->args[0]);
	if (access(mi_cmd->args[0], F_OK) == 0)
	{
		free(cmd);
		return ;
	}
	free(cmd);
	paths = ft_split(mi_getenv("PATH", mi_sys), ':');
	while (paths && paths[++i])
	{
		cmd = join_3(paths[i], "/", mi_cmd->args[0]);
		if (access(cmd, F_OK) == 0)
		{
			mi_cmd->args[0] = ft_strdup(cmd);
			free(paths);
			return ;
		}
		free(cmd);
	}
	free(paths);
	free(mi_cmd->args[0]);
	return ;
}

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

int	main(int argc, char **argv, char **env)
{
	char	*line;
	t_sys	mi_sys;

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
		mi_checkline(line, &mi_sys);
		mi_lexingline(line, &mi_sys);
		mi_syscmditer(&mi_sys, &mi_expand_interface);
		mi_cmditer(mi_sys.cmd, &mi_cmdsplitcmd);
		mi_syscmditer(&mi_sys, &mi_cmdparsse);
		mi_cmditer(mi_sys.cmd, &mi_checkbuiltin);
		mi_syscmditer(&mi_sys, &mi_checkpathaccess);
		mi_syscmditer(&mi_sys, &mi_execone);
		mi_waitingpipe(&mi_sys);
		mi_freecmd(&mi_sys);
		//  mi_cmditer (&mi_cmd, &mi_cmdherdoc);
	}
}
