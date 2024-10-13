/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doferet <doferet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 12:08:01 by doferet           #+#    #+#             */
/*   Updated: 2024/09/10 14:56:19 by doferet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_status;

void	mi_pipe_acc(t_pipe *mi_pipe, t_sys *mi_sys)
{
	char		*cmd;
	char		**paths;
	int			i;
	char		*error_msg;

	i = 0;
	if (access(mi_pipe->cmd, F_OK) == 0)
		return ;
	i = 0;
	cmd = join_3(mi_getenv("PWD", mi_sys), "/", mi_pipe->cmd);
	if (access(mi_pipe->cmd, F_OK) == 0)
		return ;
	paths = ft_split (mi_getenv("PATH", mi_sys), ':');
	while (paths && paths[++i])
	{
		cmd = join_3(paths[i], "/", mi_pipe->cmd);
		if (access(cmd, F_OK) == 0)
		{
			mi_pipe->cmd = cmd;
			free(paths);
			return ;
		}
		free(cmd);
	}
	error_msg = join_3 ("minishell: ", mi_pipe->cmd, ": command not found\n");
	mi_logerror(126, error_msg, &mi_pipe->error);
	free(cmd);
	free(paths);
	free(mi_pipe->cmd);
	return ;
}

void	mi_pipe_access (t_pipe *mi_pipe, t_sys *mi_sys)
{
	int i;
	char	*pathcmd;
	char	**paths;
	char	*pathstring;

	if (access(mi_pipe->cmd, F_OK) == 0)
		return;
	pathcmd = join_3(mi_getenv("PWD", mi_sys), "/", mi_pipe->cmd);
	if (access(pathcmd, F_OK) == 0)
		return ;
	pathstring = ft_strdup(mi_getenv("PATH", mi_sys));

	paths = ft_split (pathstring, ':');
	i = -1;
	while (paths && paths[++i])
	{
		pathcmd = join_3(paths[i], "/", mi_pipe->cmd);
		if (access(pathcmd, F_OK) == 0)
		{
			mi_pipe->cmd = pathcmd;
			free(paths);
			return ;
		}
		free(pathcmd);
	}

}



int	main(int ac, char **argv, char **env)
{
	char	*line;
	t_sys	mi_sys;
	t_pipe	mi_pipe;

	if (ac > 1)
	{
		printf("Error: minishell does not take arguments. Try: ./%s\n", argv[0]);
		exit(0);
	}
	mi_sysinitialization(env, &mi_sys);
	while (1)
	{
		line = readline("minishell> ");
		if (*line =='\0')
			continue;
		mi_sys.nb_pipe = 0;
		mi_pipe = *mi_createpipe(&mi_sys);
		mi_lexingline (line, 0, &mi_pipe, &mi_sys);
		mi_sys.pipe = &mi_pipe;
		mi_syspipeiter(&mi_sys, &mi_expand_interface);
		mi_pipeiter (&mi_pipe, &mi_pipeparsse);
		mi_pipeiter (&mi_pipe, &mi_pipeargparsse);
		mi_syspipeiter(&mi_sys, &mi_expand_interface);
		mi_syspipeiter (&mi_sys, &mi_pipe_access);
//		mi_pipeiter (&mi_pipe, &mi_pipeherdoc);
//		mi_exec(&mi_pipe, &mi_sys);
		add_history(line);
	}
}
