/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard <jegirard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 12:08:01 by doferet           #+#    #+#             */
/*   Updated: 2024/10/14 18:56:37 by jegirard         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "minishell.h"

extern int	g_status;

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
	mi_logerror(126, error_msg, &mi_cmd->error);
	free(cmd);
	free(paths);
	free(mi_cmd->cmd);
	return ;
}

void mi_cmdexec(t_cmd *mi_cmd, t_sys *mi_sys)
{
	char	**argv;

	if (mi_cmd->builtin == true)
	{
		if (ft_findword("cd", mi_cmd->cmd))
			builtin_cd(mi_cmd->arg, mi_sys);
		else if (ft_findword("echo", mi_cmd->cmd))
			builtin_echo(mi_cmd->arg);
		else if (ft_findword("env", mi_cmd->cmd))
			builtin_env(mi_sys);
		else if (ft_findword("exit", mi_cmd->cmd))
			builtin_exit();
		else if (ft_findword("export", mi_cmd->cmd))
			builtin_export(mi_cmd->arg, mi_sys);
		else if (ft_findword("pwd", mi_cmd->cmd))
			builtin_pwd();
		else if (ft_findword("unset", mi_cmd->cmd))
			builtin_unset(mi_cmd->arg, mi_sys);
	}
	else
	{
		argv = ft_split(mi_cmd->full_cmd, ' ');
		mi_execchild(mi_cmd, mi_sys);
	}
}

int	main(int ac, char **argv, char **env)
{
	char	*line;
	t_sys	mi_sys;
	t_cmd	*mi_cmd;

	if (ac > 1)
	{
		printf("Error: minishell does not take arguments. Try: ./%s\n", argv[0]);
		exit(0);
	}
	mi_sysinitialization(env, &mi_sys);
	while (1)
	{
		line = readline("minishell> ");

		while (*line !='\0' && ft_strrchr (WSPACE, *line ) != NULL) 
			line++;
		if (*line =='\0')
			continue;
		mi_sys.nb_pipe = 0;
		mi_cmd = mi_createcmd(&mi_sys);
		mi_lexingline (line, 0, mi_cmd, &mi_sys);
		mi_sys.cmd = mi_cmd;
		mi_syscmditer(&mi_sys, &mi_expand_interface);
		mi_cmditer (mi_cmd, &mi_cmdsplitcmd);
		mi_cmditer (mi_cmd, &mi_cmdparsse);
//		mi_cmditer (mi_cmd, &mi_cmdargparsse);
		mi_cmditer (mi_cmd, &mi_checkbuiltin);
		mi_syscmditer (&mi_sys, &mi_checkpathaccess);
		mi_syscmditer (&mi_sys, &mi_cmdexec);
//		mi_cmditer (&mi_cmd, &mi_cmdherdoc);
//		mi_exec(&mi_cmd &mi_sys);
		add_history(line);
	}
}
