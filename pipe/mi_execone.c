/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mi_execone.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 19:50:42 by jegirard          #+#    #+#             */
/*   Updated: 2024/10/04 19:50:46 by jegirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	mi_exefind(t_pipe *pipe, t_sys *mi_sys)
{
	char		*cmd;
	char		**paths;
	int			i;
	char		*error_msg;

	i = 0;
	if (access(pipe->cmd, F_OK) == 0)
		return ;
	cmd = join_3(mi_getenv("PWD", mi_sys) , "/", pipe->cmd);
	if (access(pipe->cmd, F_OK) == 0)
		return ;
	paths = ft_split (mi_getenv("PATH", mi_sys), ':');
	while (paths && paths[++i])
	{
		cmd = join_3(paths[i], "/", pipe->cmd);
		if (access(cmd, F_OK) == 0)
		{
			pipe->cmd = cmd;
			free(paths);
			return ;
		}
		free(cmd);
	}
	error_msg = join_3 ("minishell: ", pipe->cmd, ": command not found\n");
	mi_logerror(126, error_msg, &pipe->error);
	free(cmd);
	free(paths);
	free(pipe->cmd);
	return ;
}

void	mi_exepermis(t_pipe *pipe, t_sys *mi_sys)
{
	char		*error_msg;

	if (access(pipe->cmd, X_OK) == 0)
		return ;
	error_msg = join_3 ("minishell: ", pipe->cmd, ": Permission denied\n");
	mi_logerror(126, error_msg, &pipe->error);
	free(error_msg);
	mi_sys->nb_error++;
}

int	mi_exec_child_in(t_pipe *pipe, char **argv, int ind, char **env)
{
	if (pipe->pid == 0)
		return (0);
	pipe->pid = fork();
	if (pipe->pid == -1)
		return (ft_perror(pipe, "fork failed in :", 3, 0));
	if (pipe->pid != 0)
		return (0);
	if (dup2(pipe->fdd[1][1], STDOUT_FILENO) == -1)
		return (1);
	close (pipe->fdd[1][0]);
	if (dup2(pipe->fdd[0][0], STDIN_FILENO) == -1)
		return (1);
	close_pipe (pipe, 1);
	if (pipe->exe[ind] != NULL)
		ft_exec_cmd(pipe, argv, ind, env);
	free_pipe (pipe);
	exit (EXIT_FAILURE);
	return (errno);
}


void	mi_execone(t_pipe *pipe, t_sys *mi_sys)
{
	if (ft_strncmp(pipe->cmd, "exit", 5) == 0)
	{
		printf("exit\n");
		exit(0);
	}
	else if (ft_strncmp(pipe->cmd, "env", 4) == 0)
		builtin_env(mi_sys);
	else if (ft_strncmp(pipe->cmd, "env", 4) == 0)
		builtin_env(mi_sys);
	else if (ft_strncmp(pipe->cmd, "pwd", 4) == 0)
		builtin_pwd();
	else if (ft_strncmp(pipe->cmd, "echo", 4) == 0)
		builtin_echo(ft_post_left_sep(pipe->cmd, WSPACE));
	else if (ft_strncmp(pipe->cmd, "cd", 2) == 0)
		builtin_cd(ft_post_left_sep(pipe->cmd, WSPACE), mi_sys);
	else if (ft_strncmp(pipe->cmd, "unset", 5) == 0)
		builtin_unset(pipe->args[0], mi_sys);
	else if (ft_strncmp(pipe->cmd, "export", 6) == 0)
		builtin_export(ft_post_left_sep(pipe->cmd, WSPACE), mi_sys);
	else
		pipe->builtin = false;
	if (pipe->builtin == false)
	{
		mi_exefind(pipe, mi_sys);
		if (pipe->cmd)
			mi_exepermis(pipe, mi_sys);
	}
}
